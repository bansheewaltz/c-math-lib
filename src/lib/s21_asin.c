#include "s21_fp_utils.h"
#include "s21_math.h"

// through atan
long double s21_asin(double x) {
  if (x == 1.0) {
    return S21_PI / 2;
  }
  if (x == -1.0) {
    return -S21_PI / 2;
  }

  return s21_atan(x / s21_sqrt(1 - x * x));
}
