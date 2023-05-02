#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_tan(double x) {
  if (s21_isnan(x) || s21_isinf(x)) {
    return S21_FP_NAN;
  }

  x = s21_trig_range_reduction(x);
  return s21_sin(x) / s21_cos(x);
}
