#!/usr/bin/env bash

(
  cat <<EOF
#include <stdlib.h>
#include "../module/llvm_pass.h"

char ***llvm_set_default_level_strings(int *default_string_lengths,
                                       const int num_levels) {
  char ***default_strings = malloc(sizeof(char **) * num_levels);
  for (int l = 0; l < num_levels; l++) {
    default_strings[l] = malloc(sizeof(char *) * default_string_lengths[l]);
  }
EOF

  i=0
  declare -a lens
  while read -r optpass; do
    j=0
    while read -r -d' ' one_pass; do
      echo "  default_strings[$i][$j] = \"${one_pass}\";"
      ((j++))
    done < <(echo "${optpass}")
    echo
    lens[${i}]=${j}
    ((i++))
  done < <(
    for p in O0 O1 O2 O3 Os Oz; do
      opt -${p} -debug-pass=Arguments -disable-output -enable-new-pm=0 </dev/null 2>&1 |
        tee ${p} |
        sed -n 2p |
        sed -e 's/Pass Arguments: //'
    done
  )

  cat <<EOF
  return default_strings;
}

int* llvm_default_level_string_lengths(const int num_levels) {
  int* default_string_lengths = malloc(sizeof(int) * num_levels);

$(for i in "${!lens[@]}"; do echo "  default_string_lengths[${i}] = ${lens[$i]};"; done)

  return default_string_lengths;
}
EOF

) >./llvm_pass_dflt.c

mapfile -t vals < <(sed -ne 's/.* = "\(.*\)";/\1/p' <./llvm_pass_dflt.c | sort -u)

cat >>./llvm_pass_dflt.c <<EOF
void llvm_pass_set_valid_values(object_llvm_pass_str* o) {

  int num_passes = ${#vals[@]};
  char** values = malloc(sizeof(char*) * num_passes);

$(for i in "${!vals[@]}"; do echo "  values[${i}] = \"${vals[$i]}\";"; done)

  PASS_VALID_VALUES(o) = values;
  PASS_CONSTRAINED(o) = true;
  PASS_NUM_VALID_VALUES(o) = num_passes;

  return;
}
EOF

echo "done :)"
