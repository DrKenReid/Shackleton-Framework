/*
 ============================================================================
 Name        : fitness.c
 Author      : Hannah M. Peeler
 Version     : 1.0
 Copyright   :

    Copyright 2019 Arm Inc., Andrew Sloss, Hannah Peeler

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

    Please refer to
    https://github.com/ARM-software/Shackleton-Framework/blob/master/LICENSE.TXT
    for a full overview of the license covering this work.

 Description : Main and helper functions for determining the fitness
               of an individual and using that fitness value within
               the evolution process
 ============================================================================
 */

/*
 * IMPORT
 */

#include "fitness.h"
#include "support/build_llvm.h"
#include "support/measure.h"
#define BILLION 1000000000L;
/*
 * ROUTINES
 */

/*
 * NAME
 *
 *   fitness_pre_cache_simple
 *
 * DESCRIPTION
 *
 *  Creates a file that describes the control values for fitness using LLVM opt
 *
 * PARAMETERS
 *
 *  char* folder - the main run folder that the control will be saved to
 *  char* bool - whether or not caching is being used
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (object_type == SIMPLE) {
 *     fitness_pre_cache_simple(main_folder, test_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_pre_cache_simple(char *folder, bool cache) {

  // do nothing, default for now
}

/*
 * NAME
 *
 *   fitness_cache_simple
 *
 * DESCRIPTION
 *
 *  Creates a file that describes an individual along with their fitness
 *
 * PARAMETERS
 *
 *  double fitness - the fitness of the individual in question
 *  node_str* indiv - the individual that is to be evaluated
 *  char* cache_file - the file that will hold the outputted information
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (cache) {
 *     fitness_cache_simple(fit, indiv, cache_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_cache_simple(double fitness, node_str *indiv, char *cache_file) {

  // do nothing, default for now
}

/*
 * NAME
 *
 *   fitness_simple
 *
 * DESCRIPTION
 *
 *  Calculates the fitness value specifically for a simple
 *  individual, currently is only a default
 *
 * PARAMETERS
 *
 *  node_str* indiv - the individual that is to be evaluated
 *  bool vis - whether or not visualization is enabled
 *
 * RETURN
 *
 *  uint32_t - the fitness value for indiv
 *
 * EXAMPLE
 *
 * uint32_t simple_fit = fitness_simple(node, true);
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

uint32_t fitness_simple(node_str *indiv, bool vis) {

  return 100 * (rand() / (RAND_MAX + 1.0));
}

/*
 * NAME
 *
 *   fitness_pre_cache_assembler
 *
 * DESCRIPTION
 *
 *  Creates a file that describes the control values for fitness using LLVM opt
 *
 * PARAMETERS
 *
 *  char* folder - the main run folder that the control will be saved to
 *  char* bool - whether or not caching is being used
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (object_type == ASSEMBLER) {
 *     fitness_pre_cache_assembler(main_folder, test_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_pre_cache_assembler(char *folder, bool cache) {

  // do nothing, default for now
}

/*
 * NAME
 *
 *   fitness_cache_assembler
 *
 * DESCRIPTION
 *
 *  Creates a file that describes an individual along with their fitness
 *
 * PARAMETERS
 *
 *  double fitness - the fitness of the individual in question
 *  node_str* indiv - the individual that is to be evaluated
 *  char* cache_file - the file that will hold the outputted information
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (cache) {
 *     fitness_cache_assembler(fit, indiv, cache_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_cache_assembler(double fitness, node_str *indiv,
                             char *cache_file) {

  // do nothing, default for now
}

/*
 * NAME
 *
 *   fitness_assembler
 *
 * DESCRIPTION
 *
 *  Calculates the fitness value specifically for an assembler
 *  individual, currently is only a default
 *
 * PARAMETERS
 *
 *  node_str* indiv - the individual that is to be evaluated
 *  bool vis - whether or not visualization is enabled
 *
 * RETURN
 *
 *  uint32_t - the fitness value for indiv
 *
 * EXAMPLE
 *
 * uint32_t assembler_fit = fitness_assembler(node, true);
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

uint32_t fitness_assembler(node_str *indiv, bool vis) {

  return 100 * (rand() / (RAND_MAX + 1.0));
}

/*
 * NAME
 *
 *   fitness_pre_cache_osaka_string
 *
 * DESCRIPTION
 *
 *  Creates a file that describes the control values for fitness using LLVM opt
 *
 * PARAMETERS
 *
 *  char* folder - the main run folder that the control will be saved to
 *  char* bool - whether or not caching is being used
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (object_type == OSAKA_STRING) {
 *     fitness_pre_cache_osaka_string(main_folder, test_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_pre_cache_osaka_string(char *folder, bool cache) {

  // do nothing, default for now
}

/*
 * NAME
 *
 *   fitness_cache_osaka_string
 *
 * DESCRIPTION
 *
 *  Creates a file that describes an individual along with their fitness
 *
 * PARAMETERS
 *
 *  double fitness - the fitness of the individual in question
 *  node_str* indiv - the individual that is to be evaluated
 *  char* cache_file - the file that will hold the outputted information
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (cache) {
 *     fitness_cache_osaka_string(fit, indiv, cache_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_cache_osaka_string(double fitness, node_str *indiv,
                                char *cache_file) {

  // do nothing, default for now
}

/*
 * NAME
 *
 *   fitness_osaka_string
 *
 * DESCRIPTION
 *
 *  Calculates the fitness value specifically for an osaka_string
 *  individual, currently is only a default
 *
 * PARAMETERS
 *
 *  node_str* indiv - the individual that is to be evaluated
 *  bool vis - whether or not visualization is enabled
 *
 * RETURN
 *
 *  uint32_t - the fitness value for indiv
 *
 * EXAMPLE
 *
 * uint32_t osaka_string_fit = fitness_osaka_string(node, true);
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

uint32_t fitness_osaka_string(node_str *indiv, bool vis) {

  return 100 * (rand() / (RAND_MAX + 1.0));
}

/*
 * writes ./src/files/llvm/junk_output/<file>_<cache_id> into @param dest
 */
void build_basefilename(char *dest, const int len_dest, const char *file,
                        const char *cache_id) {

  char working_cpy[1000];
  strncpy(working_cpy, file, 1000);

  char *p = strchr(working_cpy, '.');
  if (!p) {
    printf(
        "File (%s) must have valid extension such as .c or .cpp.\n\nAborting "
        "code\n\n",
        file);
    exit(0);
  }
  *p = 0;

  char *t = strrchr(working_cpy, '/');

  snprintf(dest, len_dest, "src/files/llvm/junk_output/%s_%s",
           t != NULL ? t + 1 : working_cpy, cache_id);
};

void build_command_ll2so(char *dest, const int len_dest, const char *ll,
                         const char *so) {
  snprintf(dest, len_dest, "clang %s -shared -fpic -fpie -o %s", ll, so);
  printf("compiling ll to so with %s\n", dest);
}

/*
 * NAME
 *
 *   fitness_pre_cache_llvm_pass
 *
 * DESCRIPTION
 *
 *  Creates a file that describes the control values for fitness using LLVM opt
 *
 * PARAMETERS
 *
 *  char* folder - the main run folder that the control will be saved to
 *  char* test_file - the file that will be measured for its control values
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (object_type == LLVM_PASS) {
 *     fitness_pre_cache_llvm_pass(main_folder, test_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_pre_cache_llvm_pass(char *folder, char *test_file,
                                 char **src_files, uint32_t num_src_files,
                                 bool cache, double *track_fitness,
                                 const char *cache_id, uint32_t num_runs,
                                 bool fitness_with_var, const char **levels,
                                 const int num_levels) { // added 6/8/2021

  const double tol = 0.95;

  char base_file[300] = {'\0'};
  char build_command[20000] = {'\0'};
  char run_command[1000] = {'\0'};
  char so_file[300] = {'\0'};

  llvm_form_build_ll_command(src_files, num_src_files, test_file, build_command,
                             cache_id);
  llvm_run_command(build_command);
  cache_create_baseline_folder(cache, folder);
  if (!cache) {
    return;
  }

  build_basefilename(base_file, 300, test_file, cache_id);

  for (int i = 0; i < num_levels; i++) {

    build_commands(build_command, 20000, so_file, 300, run_command, 1000,
                   base_file, levels[i]);

    // builds bc and so
    llvm_run_command(build_command);

    double fitness =
        run_with_measuresuite(num_runs, fitness_with_var, so_file, NULL);

    track_fitness[i] = fitness; // Added 6/8/2021

    fitness_pre_cache_log_to_summary(i, folder, levels, num_levels, fitness);
  }
}

void fitness_pre_cache_log_to_summary(int level_ind, char *folder,
                                      const char **levels, const int num_levels,
                                      double fitness) {
  // record precache information to /main_folder/track_fitness.csv file
  char track_fitness_file[300];
  strcpy(track_fitness_file, folder);
  strcat(track_fitness_file, "/track_fitness.csv");
  FILE *track_fitness_file_ptr = fopen(track_fitness_file, "a");
  if (level_ind == 0) {
    fprintf(track_fitness_file_ptr, "no_opt,");
    for (int l = 1; l < num_levels; l++) {
      fprintf(track_fitness_file_ptr, "%s,", levels[l]);
    }
    fprintf(track_fitness_file_ptr, "initial,gen1,gen2,gen3\n");
  }
  fprintf(track_fitness_file_ptr, "%lf,", fitness);
  fclose(track_fitness_file_ptr);

  // record precache information to /main_folder/track_fitness.csv file
  char test_compare_file[300];
  strcpy(test_compare_file, folder);
  strcat(test_compare_file, "/test_compare.csv");
  FILE *test_compare_ptr = fopen(test_compare_file, "a+");
  if (level_ind == 0) {
    fprintf(test_compare_ptr, "gen, no_opt,");
    for (int l = 1; l < num_levels; l++) {
      fprintf(test_compare_ptr, "%s,", levels[l]);
    }
    fprintf(test_compare_ptr, "shackleton\n0,");
  }
  fprintf(test_compare_ptr, "%lf,", fitness);
  fclose(test_compare_ptr);

  // write each baseline optimization level to its own file inside
  // /main_folder/baseline folder
  char out_file[300];
  char out_file_str[5000];
  char time_str[50];
  strcpy(out_file, folder);
  strcat(out_file, "/baseline");
  if (level_ind == 0) {
    strcat(out_file, "/original_no_optimization.txt");
  } else {
    strcat(out_file, "/default_opt_");
    strcat(out_file, levels[level_ind]);
    strcat(out_file, ".txt");
  }
  strcpy(out_file_str, "");
  sprintf(
      out_file_str,
      "Level of default LLVM optimization is: %s\n\nThe fitness of the "
      "individual is the time it takes to complete the testing script provided "
      "in seconds. Lower fitness is better.\n\nFitness of this individual: ",
      strlen(levels[level_ind]) == 0 ? "no optimization" : levels[level_ind]);
  sprintf(time_str, "%f", fitness);
  strcat(out_file_str, time_str);
  strcat(out_file_str, " sec");

  FILE *out_file_ptr = fopen(out_file, "w");
  fputs(out_file_str, out_file_ptr);
  fclose(out_file_ptr);
}

void fitness_redo_basic(char *folder, char *test_file, bool cache,
                        double *track_fitness, const char *cache_id,
                        uint32_t num_runs, bool fitness_with_var,
                        const char **levels, const int num_levels) {
  if (!cache) {
    return;
  }
  char base_file[300] = {'\0'};
  char build_command[20000] = {'\0'};
  char run_command[1000] = {'\0'};
  char so_file[300] = {'\0'};

  build_basefilename(base_file, 300, test_file, cache_id);

  for (int i = 0; i < num_levels; i++) {

    build_commands(build_command, 20000, so_file, 300, run_command, 1000,
                   base_file, levels[i]);

    // builds bc and so
    llvm_run_command(build_command);

    double fitness =
        run_with_measuresuite(num_runs, fitness_with_var, so_file, NULL);

    printf("LLVM opt level: %s, average time=%lf over %d success runs, "
           "fitness=%lf\n",
           strlen(levels[i]) == 0 ? "no_opt" : levels[i], fitness, num_runs,
           fitness);
    track_fitness[i] = fitness; // Added 6/8/2021
  }
}

/*
 * NAME
 *
 *   fitness_cache_llvm_pass
 *
 * DESCRIPTION
 *
 *  Creates a file that describes an individual along with their fitness
 *
 * PARAMETERS
 *
 *  double fitness - the fitness of the individual in question
 *  node_str* indiv - the individual that is to be evaluated
 *  char* cache_file - the file that will hold the outputted information
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (cache) {
 *     fitness_cache_llvm_pass(fit, indiv, cache_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_cache_llvm_pass(double fitness, node_str *indiv,
                             char *cache_file) {
  // printf("fitness.c:682, fitness_cache, cache_file: %s\n", cache_file);
  char string[30000];
  char fitness_num[100];
  char input_str[10000];
  char output_str[10000];

  strcpy(string, "Description file for Individual 1\n\nHere are the passes in "
                 "this individual, in order:\n\n");
  sprintf(fitness_num, "%f", fitness);
  strcpy(input_str, "");
  strcpy(output_str, "");

  while (NEXT(indiv) != NULL) {
    char desc[60];
    strcpy(desc, "");
    osaka_describenode(desc, indiv);
    strcat(string, desc);
    strcat(string, "\n");
    indiv = NEXT(indiv);
  }

  char desc[60];
  strcpy(desc, "");
  osaka_describenode(desc, indiv);
  strcat(string, desc);
  strcat(string, "\n\nThe fitness of the individual is the time it takes to "
                 "complete the testing script provided in seconds after the "
                 "specified optimization passes are applied. Lower fitness is "
                 "better.\n\nFitness of this individual: ");
  strcat(string, fitness_num);
  strcat(string, " sec\n\n");

  int seq_len = 0;
  if (indiv->objtype == 5) {
    char *opt_seq_str = gen_seq_str(indiv, &seq_len);
    strcat(string, opt_seq_str);
  }

  // printf("fitness.c:737, fitness_cache, cache_file: %s\n", cache_file);

  FILE *file_ptr = fopen(cache_file, "w+");
  fputs(string, file_ptr);
  // fclose(input);
  // fclose(output);
  fclose(file_ptr);
  // printf("Done writing to cache file.\n");

  // free(line);
  // printf("fitness.c:747, fitness_cache, cache_file: %s\n", cache_file);
}

/*
 * NAME
 *
 *   fitness_llvm_pass
 *
 * DESCRIPTION
 *
 *  Calculates the fitness value specifically for an llvm pass
 *  individual, based on the optimization of the code outputted
 *
 * PARAMETERS
 *
 *  node_str* indiv - the individual that is to be evaluated
 *  bool vis - whether or not visualization is enabled
 *
 * RETURN
 *
 *  double - the fitness value for indiv
 *
 * EXAMPLE
 *
 *  double llvm_pass_fit = fitness_llvm_pass(node, true);
 *
 * SIDE-EFFECT
 *
 *  none
 *
 */

double fitness_llvm_pass(node_str *indiv, char *file, char **src_files,
                         uint32_t num_src_files, bool vis, bool cache,
                         char *cache_file, const char *cache_id,
                         DataNode *indiv_data, uint32_t num_runs, int gen,
                         bool fitness_with_var) {

  char base_file[300] = {'\0'};
  char build_command[20000] = {'\0'};
  char run_command[1000] = {'\0'};
  char so_file[300] = {'\0'};

  if (!node_reeval_by_chance(indiv_data, gen)) {
    return indiv_data->fitness;
  }

  if (vis) {
    printf("Calculating fitness of individual\n");
  }

  build_basefilename(base_file, 280, file, cache_id);

  build_commands_individual(build_command, 20000, so_file, 300, run_command,
                            1000, base_file, indiv);

  // builds bc and so
  llvm_run_command(build_command);

  double all_runtime[num_runs];

  // will fill all_runtime with the cycle-results
  double fitness =
      run_with_measuresuite(num_runs, fitness_with_var, so_file, all_runtime);

  return node_record_data(indiv_data, indiv, all_runtime, fitness, num_runs,
                          gen, fitness_with_var);
}

/*
 * NAME
 *
 *   fitness_pre_cache_binary_up_to_512
 *
 * DESCRIPTION
 *
 *  Creates a file that describes the control values for fitness using LLVM opt
 *
 * PARAMETERS
 *
 *  char* folder - the main run folder that the control will be saved to
 *  char* bool - whether or not caching is being used
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (object_type == BINARY_UP_TO_512) {
 *     fitness_pre_cache_llvm_pass(main_folder, test_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_pre_cache_binary_up_to_512(char *folder, bool cache) {

  // do nothing, default for now
}

/*
 * NAME
 *
 *   fitness_cache_binary_up_to_512
 *
 * DESCRIPTION
 *
 *  Creates a file that describes an individual along with their fitness
 *
 * PARAMETERS
 *
 *  double fitness - the fitness of the individual in question
 *  node_str* indiv - the individual that is to be evaluated
 *  char* cache_file - the file that will hold the outputted information
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (cache) {
 *     fitness_cache_binary_up_to_512(fit, indiv, cache_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_cache_binary_up_to_512(double fitness, node_str *indiv,
                                    char *cache_file) {

  // do nothing, default for now
}

/*
 * NAME
 *
 *   fitness_binary_up_to_512
 *
 * DESCRIPTION
 *
 * Calculates the fitness value specifically for an binary_up_to_512
 * inidividual, currently is only a default. AUTO-GENERATED
 *
 * PARAMETERS
 *
 *  node_str* indiv - the individual that is to be evaluated
 *  bool vis - whether or not visualization is enabled
 *
 * RETURN
 *
 *  uint32_t - the fitness value for indiv
 *
 * EXAMPLE
 *
 * uint32_t binary_up_to_512_fit = fitness_binary_up_to_512(node, true);
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

uint32_t fitness_binary_up_to_512(node_str *indiv, bool vis) {

  return 100 * (rand() / (RAND_MAX + 1.0));
}

/*
 * NAME
 *
 *   fitness_pre_cache_gi_llvm_pass
 *
 * DESCRIPTION
 *
 *  Creates a file that describes the control values for fitness using LLVM opt
 *
 * PARAMETERS
 *
 *  char* folder - the main run folder that the control will be saved to
 *  char* bool - whether or not caching is being used
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (object_type == GI_LLVM_PASS) {
 *     fitness_pre_cache_gi_llvm_pass(main_folder, test_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_pre_cache_gi_llvm_pass(char *folder, char *test_file,
                                    char **src_files, uint32_t num_src_files,
                                    bool cache, double *track_fitness,
                                    const char *cache_id, uint32_t num_runs,
                                    bool fitness_with_var, const char **levels,
                                    const int num_levels) { // added 6/8/2021

  char base_file[300] = {'\0'};
  char input_file_base[300] = {'\0'};
  char out_file_base[300] = {'\0'};
  char so_in_file[300] = {'\0'};
  char so_file[300] = {'\0'};
  char build_command[20000] = {'\0'};
  char opt_command[1000] = {'\0'};
  char bc_command[1000] = {'\0'};
  char run_command[1000] = {'\0'};
  char so_command[5000] = {'\0'};

  llvm_form_build_ll_command(src_files, num_src_files, test_file, build_command,
                             cache_id);
  llvm_run_command(build_command);
  cache_create_baseline_folder(cache, folder);

  if (!cache) {
    return;
  }
  build_basefilename(base_file, 300, test_file, cache_id);

  for (int i = 0; i < num_levels; i++) {

    build_commands(build_command, 20000, so_file, 300, run_command, 1000,
                   base_file, levels[i]);

    // builds bc and so
    llvm_run_command(build_command);

    double fitness =
        run_with_measuresuite(num_runs, fitness_with_var, so_file, NULL);

    track_fitness[i] = fitness; // Added 6/8/2021

    track_fitness[i] = fitness; // Added 6/8/2021

    fitness_pre_cache_log_to_summary(i, folder, levels, num_levels, fitness);
  }
}

/*
 * NAME
 *
 *   fitness_cache_gi_llvm_pass
 *
 * DESCRIPTION
 *
 *  Creates a file that describes an individual along with their fitness
 *
 * PARAMETERS
 *
 *  double fitness - the fitness of the individual in question
 *  node_str* indiv - the individual that is to be evaluated
 *  char* cache_file - the file that will hold the outputted information
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * if (cache) {
 *     fitness_cache_gi_llvm_pass(fit, indiv, cache_file);
 * }
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

void fitness_cache_gi_llvm_pass(double fitness, node_str *indiv,
                                char *cache_file) {

  // do nothing, default for now
}

/*
 * NAME
 *
 *   fitness_gi_llvm_pass
 *
 * DESCRIPTION
 *
 *  Calculates the fitness value specifically for a GI LLVM PASS
 *  individual, currently is only a default
 *
 * PARAMETERS
 *
 *  node_str* indiv - the individual that is to be evaluated
 *  bool vis - whether or not visualization is enabled
 *
 * RETURN
 *
 *  uint32_t - the fitness value for indiv
 *
 * EXAMPLE
 *
 * uint32_t gi_llvm_pass_fit = fitness_gi_llvm_pass(node, true);
 *
 * SIDE-EFFECT
 *
 * none
 *
 */

double fitness_gi_llvm_pass(node_str *indiv, char *file, char **src_files,
                            uint32_t num_src_files, bool vis, bool cache,
                            char *cache_file, const char *cache_id,
                            DataNode *indiv_data, uint32_t num_runs, int gen,
                            bool fitness_with_var) {

  char so_file[300] = {'\0'};
  char base_file[280] = {'\0'};
  char build_command[20000] = {'\0'};
  char run_command[1000] = {'\0'};

  if (!node_reeval_by_chance(indiv_data, gen)) {
    return indiv_data->fitness;
  }

  if (vis) {
    printf("Calculating fitness of individual\n");
  }

  char *sequence = seq_str_fitness(indiv);

  // writes ./src/files/llvm/junk_output/<file>_<cache_id> into base_file
  build_basefilename(base_file, 280, file, cache_id);

  build_commands_sequence(build_command, 20000, so_file, 300, run_command, 1000,
                          base_file, sequence);
  // builds bc and so
  llvm_run_command(build_command);

  double all_runtime[num_runs];
  double fitness =
      run_with_measuresuite(num_runs, fitness_with_var, so_file, all_runtime);

  return node_record_data(indiv_data, indiv, all_runtime, fitness, num_runs,
                          gen, fitness_with_var);
}

/*
 * NAME
 *
 *  fitness_pre_cache
 *
 * DESCRIPTION
 *
 *  Does an initial setup cache, is dependent on the object type
 *
 * PARAMETERS
 *
 *  char* folder - the folder where the pre caching files will be housed
 *  char* file - for some object types, will be a file used for the caching
 *  osaka_object_typ type - the object type for this evolutionary run
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 *  if (cache) {
 *      fitness_pre_cache(main_folder, test_file, ot);
 *  }
 *
 * SIDE-EFFECT
 *
 *  none
 *
 */

void fitness_pre_cache(char *folder, char *test_file, char **src_files,
                       uint32_t num_src_files, osaka_object_typ type,
                       bool cache, double *track_fitness, const char *cache_id,
                       uint32_t num_runs, bool fitness_with_var,
                       const char **levels,
                       const int num_levels) { // added 6/8/2021
  // double fitness_pre_cache(char* folder, char* test_file, char** src_files,
  // uint32_t num_src_files, osaka_object_typ type, bool cache) { //added
  // 6/2/2021 void fitness_pre_cache(char* folder, char* test_file, char**
  // src_files, uint32_t num_src_files, osaka_object_typ type, bool cache) {
  if (type == 0) { // SIMPLE
    fitness_pre_cache_simple(folder, cache);
  } else if (type == 1) { // ASSEMBLER
    fitness_pre_cache_assembler(folder, cache);
  } else if (type == 2) { // OSAKA_STRING
    fitness_pre_cache_osaka_string(folder, cache);
  } else if (type == 3) { // LLVM_PASS
    fitness_pre_cache_llvm_pass(folder, test_file, src_files, num_src_files,
                                cache, track_fitness, cache_id, num_runs,
                                fitness_with_var, levels,
                                num_levels); // added 6/8/2021
    // return fitness_pre_cache_llvm_pass(folder, test_file, src_files,
    // num_src_files, cache);  //added 6/2/2021
  } else if (type == 4) { // BINARY_UP_TO_512
    fitness_pre_cache_binary_up_to_512(folder, cache);
  } else if (type == 5) { // GI_LLVM_PASS
    fitness_pre_cache_gi_llvm_pass(folder, test_file, src_files, num_src_files,
                                   cache, track_fitness, cache_id, num_runs,
                                   fitness_with_var, levels, num_levels);
    // fitness_pre_cache_gi_llvm_pass(folder, cache);
  }
}

/*
 * NAME
 *
 *  fitness_cache
 *
 * DESCRIPTION
 *
 *  Caches
 *
 * PARAMETERS
 *
 *  double fitness_value - the fitness value of the individual to be cached
 *  node_str* indiv - pointer to the individual to be cached
 *  char* cache_file - file where the cached information will reside
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 *  fitness_cache(value, individual, "individual1.txt");
 *
 * SIDE-EFFECT
 *
 *  none
 *
 */

void fitness_cache(double fitness_value, node_str *indiv, char *cache_file) {
  // printf("fitness.c:1101, fitness_cache, cache_id: %s\n", cache_id);
  osaka_object_typ type = OBJECT_TYPE(indiv);

  if (type == 0) { // SIMPLE
    return fitness_cache_simple(fitness_value, indiv, cache_file);
  } else if (type == 1) { // ASSEMBLER
    return fitness_cache_assembler(fitness_value, indiv, cache_file);
  } else if (type == 2) { // OSAKA_STRING
    return fitness_cache_osaka_string(fitness_value, indiv, cache_file);
  } else if (type == 3) { // LLVM_PASS
    return fitness_cache_llvm_pass(fitness_value, indiv, cache_file);
  } else if (type == 4) { // BINARY_UP_TO_512
    return fitness_cache_binary_up_to_512(fitness_value, indiv, cache_file);
  } else if (type == 5) { // GI_LLVM_PASS
    return fitness_cache_gi_llvm_pass(fitness_value, indiv, cache_file);
  }
}

/*
 * NAME
 *
 *  fitness_top
 *
 * DESCRIPTION
 *
 *  Applies the correct fitness function based on the
 *  specific object type of the individual
 *
 * PARAMETERS
 *
 *  node_str* indiv - the individual that is to be evaluated
 *  bool vis - whether or not visualization is enabled
 *
 * RETURN
 *
 *  double - the fitness value for indiv
 *
 * EXAMPLE
 *
 *  double fitness = fitness_top(node, true);
 *
 * SIDE-EFFECT
 *
 *  none
 *
 */

double fitness_top(node_str *indiv, bool vis, char *test_file, char **src_files,
                   uint32_t num_src_files, bool cache, char *cache_file,
                   const char *cache_id, DataNode *indiv_data,
                   uint32_t num_runs, int gen, bool fitness_with_var) {

  osaka_object_typ type = OBJECT_TYPE(indiv);

  // the fitness function depends on the object type
  if (type == 0) { // SIMPLE
    return fitness_simple(indiv, vis);
  } else if (type == 1) { // ASSEMBLER
    return fitness_assembler(indiv, vis);
  } else if (type == 2) { // OSAKA_STRING
    return fitness_osaka_string(indiv, vis);
  } else if (type == 3) { // LLVM_PASS
    return fitness_llvm_pass(indiv, test_file, src_files, num_src_files, vis,
                             cache, cache_file, cache_id, indiv_data, num_runs,
                             gen, fitness_with_var);
  } else if (type == 4) { // BINARY_UP_TO_512
    return fitness_binary_up_to_512(indiv, vis);
  } else if (type == 5) { // GI_LLVM_PASS
    return fitness_gi_llvm_pass(indiv, test_file, src_files, num_src_files, vis,
                                cache, cache_file, cache_id, indiv_data,
                                num_runs, gen, fitness_with_var);
  } else {
    return 100;
  }
}

/*
 * NAME
 *
 *   fitness_setup
 *
 * DESCRIPTION
 *
 *  initializes all typdefs for function pointers to their
 *  respective methods in fitness.h
 *
 * PARAMETERS
 *
 *  none
 *
 * RETURN
 *
 *  none
 *
 * EXAMPLE
 *
 * fitness_setup();
 *
 * SIDE-EFFECT
 *
 * alters the typedefs
 *
 */

void fitness_setup() {

  fpfitness_simple = &fitness_simple;
  fpfitness_assembler = &fitness_assembler;
  fpfitness_osaka_string = &fitness_osaka_string;
  fpfitness_llvm_pass = &fitness_llvm_pass;
  fpfitness_binary_up_to_512 = &fitness_binary_up_to_512;
  fpfitness_gi_llvm_pass = &fitness_gi_llvm_pass;
}
