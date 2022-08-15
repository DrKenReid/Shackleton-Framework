#include "measure.h"
#include "support/utility.h"
#include <measuresuite.h>

double run_with_measuresuite(int num_runs, bool fitness_with_var,
                             const char *so_file, double all_runtime[]) {
  measuresuite_t ms;
  const uint64_t bounds[] = {-1};
  int init = ms_measure_init(&ms, 10, 2, 1, 16, bounds, so_file, "function");
  if (init == 1) {
    fprintf(stderr, "cannot initialize measuresuite. on file %s\n", so_file);
    ms_p_error(ms);
  }

  const int batchsize = 100;
  /** make num_runs uneven so we have one median  */
  num_runs |= 0b1;
  ms_measure_lib_only(ms, batchsize, num_runs);

  uint64_t *cycles;
  ms_get_libcycles(ms, &cycles);
  // cycles is now an array of length num_runs, which contains cycle counts

  // free all ms-associated memory
  ms_measure_end(ms);

  // calculate fitness
  double fitness = median(cycles, num_runs);

  // if parameter is NULL, write to local copy
  double all_runtime_local[num_runs];
  if (all_runtime == NULL) {
    all_runtime = all_runtime_local;
  }

  double sum = 0;
  for (uint32_t run = 0; run < num_runs; run++) {
    all_runtime[run] = (double)cycles[run];
    sum += (double)cycles[run];
  }

  double mean = sum / num_runs;

  if (fitness_with_var) {
    fitness += calc_var(all_runtime, mean, num_runs);
  }

  return fitness;
}
