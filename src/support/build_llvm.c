#include "build_llvm.h"
#include <osaka/osaka.h>
#include <stdio.h>
#include <string.h>

/*
 * will return >1 if buffer were too small.
 */
int build_commands(
    char *build_command, // will build an optimized .bc and .so
    size_t build_command_len,
    char *so_file, // the name of the resulting .so file
    size_t so_file_len,
    char *run_bitcode_cmd, // will run .bc with lli
    size_t run_bitcode_cmd_len,
    const char *base_name, // path/to/main (from main.c)
    const char *level      // optimisation level to append to opt (can be len=0)
) {
  int printed = snprintf(so_file, so_file_len, "%s_shackleton.so", base_name);
  if (printed >= so_file_len) {
    return 1;
  }

  if (strlen(level) == 0) {
    // the workflow is
    // <input>_linked.ll --- llvm-as ---> <input>_shackleton.bc
    // <input>_linked.ll ---  clang  ---> <input>_shackleton.so
    printed = snprintf(build_command, build_command_len,
                       "llvm-as %s_linked.ll -o %s_shackleton.bc && "
                       "clang %s_linked.ll -shared -fpic -fpie -o %s",
                       base_name, base_name, base_name, so_file);
    if (printed >= build_command_len) {
      return 11;
    }

    printed = snprintf(run_bitcode_cmd, run_bitcode_cmd_len,
                       "lli %s_shackleton.bc", base_name);
    if (printed >= run_bitcode_cmd_len) {
      return 12;
    }
  } else {
    // we do have optimization
    // the workflow is
    //
    // 1.
    // <input>_linked.ll --- opt --> <input>_opt_<level>.ll
    //
    // 2.
    // <input>_opt_<level>.ll --- llvm-as ---> <input>_shackleton.bc
    // <input>_opt_<level>.ll ---  clang  ---> <input>_shackleton.so

    printed = snprintf(build_command, build_command_len,
                       "opt -%s %s_linked.ll -S -o %s_opt_%s.ll && "
                       "llvm-as %s_opt_%s.ll    -o %s_shackleton.bc && "
                       "clang   %s_opt_%s.ll -shared -fpic -fpie -o %s",
                       level, base_name, base_name, level, base_name, level,
                       base_name, base_name, level, so_file);
    if (printed >= build_command_len) {
      return 21;
    }

    printed = snprintf(run_bitcode_cmd, run_bitcode_cmd_len,
                       "lli %s_shackleton.bc", base_name);
    if (printed >= run_bitcode_cmd_len) {
      return 22;
    }
  }
  return 0;
}

/*
 * will return >1 if buffer were too small.
 */
int build_commands_sequence(
    char *build_command, // will build an optimized .bc and .so
    size_t build_command_len,
    char *so_file, // the name of the resulting .so file
    size_t so_file_len,
    char *run_bitcode_cmd, // will run .bc with lli
    size_t run_bitcode_cmd_len,
    const char *base_name, // path/to/main (from main.c)
    const char *sequence   // optimisation sequence to be put to opt
) {
  int printed = snprintf(so_file, so_file_len, "%s_shackleton.so", base_name);
  if (printed >= so_file_len) {
    return 1;
  }

  // we do have optimization
  // the workflow is
  // 1.
  // <input>_linked.ll --- opt --> <input>_opt.ll
  //
  // 2.
  // <input>_opt.ll --- llvm-as ---> <input>_shackleton.bc
  // <input>_opt.ll ---  clang  ---> <input>_shackleton.so

  printed = snprintf(build_command, build_command_len,
                     "opt %s %s_linked.ll -S -o %s_opt.ll && "
                     "llvm-as %s_opt.ll      -o %s_shackleton.bc && "
                     "clang   %s_opt.ll -shared -fpic -fpie -o %s",
                     sequence, base_name, base_name, base_name, base_name,
                     base_name, so_file);
  if (printed >= build_command_len) {
    return 21;
  }

  printed = snprintf(run_bitcode_cmd, run_bitcode_cmd_len,
                     "lli %s_shackleton.bc", base_name);
  if (printed >= run_bitcode_cmd_len) {
    return 22;
  }

  return 0;
}
/*
 * will return >1 if buffer were too small.
 */
int build_commands_individual(
    char *build_command, // will build an optimized .bc and .so
    size_t build_command_len,
    char *so_file, // the name of the resulting .so file
    size_t so_file_len,
    char *run_bitcode_cmd, // will run .bc with lli
    size_t run_bitcode_cmd_len,
    const char *base_name, // path/to/main (from main.c)
    node_str *indiv        // the individual to get the passes from
) {

  if (indiv == NULL) {
    printf("Individual is null. Aborting code.");
    exit(1);
  }
  if (OBJECT_TYPE(indiv) != LLVM_PASS) {
    printf(
        "Object type used was incompatible with this function. Aborting code.");
    exit(1);
  }

  size_t size = 1000;
  char *sequence = calloc(size, sizeof(char));
  size_t remaining = size - 1;

  do {
    object_llvm_pass_str *pass = (object_llvm_pass_str *)OBJECT(indiv);

    char *s = PASS(pass);
    const size_t len = strlen(s);

    if (len >= remaining - 1) { // -1 for space-char
                                // if the buffer would be too small, we extend
      remaining += size;
      size *= 2;
      printf("rallocing\n\n\n'");
      sequence = realloc(sequence, size);
    }

    // append
    strncat(sequence, s, remaining);
    strncat(sequence, " ", 2);
    remaining -= len + 1;

  } while ((indiv = NEXT(indiv)) != NULL);

  printf("seq: %s\n\n\n", sequence);
  // then call the sequence function
  int ret = build_commands_sequence(build_command, build_command_len, so_file,
                                    so_file_len, run_bitcode_cmd,
                                    run_bitcode_cmd_len, base_name, sequence);
  free(sequence);

  return ret;
}
