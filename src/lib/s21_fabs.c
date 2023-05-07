#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_fabs(double x) {
  if (s21_isnan(x)) {
    return S21_FP_NAN;
  }

  if (x < 0.0) {
    return -x;
  }
  return x;
}
