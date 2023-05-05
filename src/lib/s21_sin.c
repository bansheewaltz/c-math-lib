#include "s21_fp_utils.h"
#include "s21_math.h"

// through Taylor series
long double s21_sin(double x) {
  if (s21_isnan(x) || s21_isinf(x)) {
    return x;
  }

  x = s21_trig_range_reduction(x);

  long double ith_term = x;  // x is the zeroth term
  long double partial_sum = ith_term;

  for (int i = 1; s21_fabs((double)ith_term) > S21_EPSILON; ++i) {
    ith_term = -ith_term * x * x / ((2 * i) * (2 * i + 1));
    partial_sum += ith_term;
  }

  return partial_sum;
}
