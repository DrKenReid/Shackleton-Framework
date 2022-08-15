#include <osaka/osaka.h>
#include <stdlib.h>
int build_commands(
    char *build_command, // will build an optimized .bc and .so
    size_t build_command_len,
    char *so_file, // the name of the resulting .so file
    size_t so_file_len,
    char *run_bitcode_cmd, // will run .bc with lli
    size_t run_bitcode_cmd_len,
    const char *base_name, // path/to/main (from main.c)
    const char *level      // optimisation level to append to opt (can be len=0)
);
int build_commands_sequence(
    char *build_command, // will build an optimized .bc and .so
    size_t build_command_len,
    char *so_file, // the name of the resulting .so file
    size_t so_file_len,
    char *run_bitcode_cmd, // will run .bc with lli
    size_t run_bitcode_cmd_len,
    const char *base_name, // path/to/main (from main.c)
    const char *sequence   // optimisation sequence to be put to opt
);

int build_commands_individual(
    char *build_command, // will build an optimized .bc and .so
    size_t build_command_len,
    char *so_file, // the name of the resulting .so file
    size_t so_file_len,
    char *run_bitcode_cmd, // will run .bc with lli
    size_t run_bitcode_cmd_len,
    const char *base_name, // path/to/main (from main.c)
    node_str *indiv        // the individual to get the passes from
);
