#include "s21_fp_utils.h"
#include "s21_math.h"

// through Taylor series
long double s21_exp(double x) {
  const int LDBL_MAX_EXP_POWER = 700;

  if (x > LDBL_MAX_EXP_POWER) {
    return S21_FP_PINF;
  }
  if (x < -LDBL_MAX_EXP_POWER) {
    return 0;
  }

  long double ith_term = 1;  // 1 is the zeroth term
  long double partial_sum = ith_term;

  for (int i = 1; s21_fabs((double)ith_term) > S21_EPSILON; ++i) {
    ith_term = ith_term * x / i;
    partial_sum += ith_term;
  }

  return partial_sum;
}
