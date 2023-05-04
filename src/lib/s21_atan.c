#include "s21_fp_utils.h"
#include "s21_math.h"

#define LOOPS_COUNT 500

// through taylor series
long double s21_atan(double x) {
  const long double atan_of_1 = 0.7853981633974483L;

  if (x == 1.0) {
    return atan_of_1;
  }
  if (x == -1.0) {
    return -atan_of_1;
  }

  long double ith_term;
  long double partial_sum;

  if (-1.0 < x && x < 1.0) {
    ith_term = x;  // x is zeroth term
    partial_sum = ith_term;

    for (int i = 1; s21_fabs(ith_term) > S21_EPSILON; ++i) {
      ith_term = -ith_term * x * x / (2 * i + 1) * (2 * (i - 1) + 1);
      partial_sum += ith_term;
    }

  } else {
    ith_term = 1.0 / x;  // 1/x is zeroth term
    partial_sum = ith_term;

    for (int i = 1; s21_fabs(ith_term) > S21_EPSILON; ++i) {
      ith_term = -ith_term * 1.0 / (x * x * (2 * i + 1)) * (2 * (i - 1) + 1);
      partial_sum += ith_term;
    }
    partial_sum = S21_PI * s21_fabs(x) / (2 * x) - partial_sum;
  }

  return partial_sum;
}
