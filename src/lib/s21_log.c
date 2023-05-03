#include <stdbool.h>

#include "s21_fp_utils.h"
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

  bool input_is_smaller_than_one = x < 1.0L;
  if (input_is_smaller_than_one) {
    x = 1.0L / x;
  }

  size_t e_exponent_whole_part_count = 0;
  while (x >= S21_E) {
    x /= S21_E;
    ++e_exponent_whole_part_count;
  }

  long double ith_term = INITIAL_GUESS;
  long double partial_sum = ith_term;

  while (s21_fabs(ith_term) > S21_EPSILON) {
    ith_term = 2 * (x - s21_exp(partial_sum)) / (x + s21_exp(partial_sum));
    partial_sum += ith_term;
  }
  partial_sum += e_exponent_whole_part_count;

  if (input_is_smaller_than_one) {
    partial_sum *= -1;
  }

  return partial_sum;
}
