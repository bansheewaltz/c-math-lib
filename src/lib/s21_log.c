#include <stdbool.h>

#include "s21_fp_utils.h"
#include "s21_fp_utilsl.h"
#include "s21_math.h"

#define INITIAL_GUESS 0.5L

// through Newton-Raphson method
long double s21_log(double x) {
  if (s21_isnan(x) || x < 0) {
    return S21_FP_NAN;
  }
  if (s21_ispinf(x)) {
    return S21_FP_PINF;
  }
  if (x == 0) {
    return S21_FP_NINF;
  }

  long double temp_value = (long double)x;
  bool input_is_smaller_than_one = x < 1.0;
  if (input_is_smaller_than_one) {
    temp_value = (long double)1.0 / x;
  }

  size_t e_exponent_whole_part_count = 0;
  while (temp_value >= S21_E) {
    temp_value /= S21_E;
    ++e_exponent_whole_part_count;
  }

  long double ith_term = INITIAL_GUESS;
  long double partial_sum = ith_term;

  for (int i = 0; s21_fabsl(ith_term) > S21_EPSILON && i < LOOP_LIMIT; ++i) {
    long double dividend = temp_value - s21_exp((double)partial_sum);
    long double divisor = temp_value + s21_exp((double)partial_sum);

    ith_term = 2 * dividend / divisor;
    partial_sum += ith_term;
  }
  partial_sum += (long double)e_exponent_whole_part_count;

  if (input_is_smaller_than_one) {
    partial_sum *= -1;
  }

  return partial_sum;
}
