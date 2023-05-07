#include "s21_fp_utils.h"
#include "s21_fp_utilsl.h"
#include "s21_math.h"

// through Taylor series
long double s21_sin(double x) {
  if (s21_isnan(x) || s21_isinf(x)) {
    return S21_FP_NAN;
  }

  long double inp = s21_trig_range_reduction((long double)x);

  long double ith_term = inp;  // inp is the zeroth term
  long double partial_sum = ith_term;

  for (int i = 1; s21_fabsl(ith_term) > S21_EPSILON && i < LOOP_LIMIT; ++i) {
    ith_term = -ith_term * inp * inp / ((2 * i) * (2 * i + 1));
    partial_sum += ith_term;
  }

  return partial_sum;
}
