#include "stdbool.h"
/*
 *
 * if @param all_runtime is non-NULL, the individual cycle counts will be
 * written to that array
 */
double run_with_measuresuite(int num_runs, bool fitness_with_var,
                             const char *so_file, double all_runtime[]);
