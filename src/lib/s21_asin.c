#include "s21_fp_utils.h"
#include "s21_math.h"

// through atan
long double s21_asin(double x) {
  const long double sin_of_pi_4 = 0.70710678118654746L;

  if (x < -1.0 || 1.0 < x) {
    return S21_FP_NAN;
  }
  if (x == 1.0) {
    return S21_PI_2;
  }
  if (x == -1.0) {
    return -S21_PI_2;
  }
  if (x == sin_of_pi_4) {
    return S21_PI_4;
  }
  if (x == -sin_of_pi_4) {
    return -S21_PI_4;
  }

  return s21_atan(x / s21_sqrt(1 - x * x));
}
