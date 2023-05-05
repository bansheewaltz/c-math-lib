#include <math.h>

#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_sqrt(double x) {
  if (x < 0.0) {
    return S21_FP_NAN;
  }
  if (x == 0.0) {
    return 0.0;
  }
  if (x == S21_FP_PINF) {
    return S21_FP_PINF;
  }

  long double intermediate_value = x;
  long double prev_value = 1;

  if (x > 0) {
    while (s21_fabs((double)(intermediate_value - prev_value)) > S21_EPSILON) {
      intermediate_value = prev_value;
      prev_value = (prev_value + (x / prev_value)) / 2;
    }
  }

  return intermediate_value;
}
