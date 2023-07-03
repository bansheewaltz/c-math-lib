#include <stdbool.h>

#include "sx_fp_utils.h"
#include "sx_fp_utilsl.h"
#include "sx_math.h"

#define INITIAL_GUESS 0.5L

// through Newton-Raphson method
long double sx_log(double x) {
  if (sx_isnan(x) || x < 0) {
    return Sx_FP_NAN;
  }
  if (sx_ispinf(x)) {
    return Sx_FP_PINF;
  }
  if (x == 0) {
    return Sx_FP_NINF;
  }

  long double temp_value = (long double)x;
  bool input_is_smaller_than_one = x < 1.0;
  if (input_is_smaller_than_one) {
    temp_value = (long double)1.0 / x;
  }

  size_t e_exponent_whole_part_count = 0;
  while (temp_value >= Sx_E) {
    temp_value /= Sx_E;
    ++e_exponent_whole_part_count;
  }

  long double ith_term = INITIAL_GUESS;
  long double partial_sum = ith_term;

  for (int i = 0; sx_fabsl(ith_term) > Sx_EPSILON && i < LOOP_LIMIT; ++i) {
    long double dividend = temp_value - sx_exp((double)partial_sum);
    long double divisor = temp_value + sx_exp((double)partial_sum);

    ith_term = 2 * dividend / divisor;
    partial_sum += ith_term;
  }
  partial_sum += (long double)e_exponent_whole_part_count;

  if (input_is_smaller_than_one) {
    partial_sum *= -1;
  }

  return partial_sum;
}
