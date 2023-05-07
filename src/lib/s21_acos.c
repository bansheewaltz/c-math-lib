#include "s21_fp_utils.h"
#include "s21_fp_utilsl.h"
#include "s21_math.h"

// through atan
long double s21_acos(double x) {
  if (x < -1.0 || 1.0 < x) {
    return S21_FP_NAN;
  }
  if (x == 1.0) {
    return 0.0L;
  }
  if (x == -1.0) {
    return S21_PI;
  }
  if (x == 0) {
    return S21_PI / 2;
  }
  if (s21_fabsl((long double)x - S21_SQRT1_2) < S21_EPSILON) {
    return S21_PI_4;
  }
  if (s21_fabsl((long double)x - S21_SQRT1_2) < S21_EPSILON) {
    return 2 * S21_PI - S21_PI_4;
  }
  if (0.0 < x && x < 1.0) {
    return s21_atan((double)(s21_sqrt(1 - x * x) / (long double)x));
  }
  if (-1.0 < x && x < 0.0) {
    return S21_PI + s21_atan((double)(s21_sqrt(1 - x * x) / (long double)x));
  }

  return S21_FP_NAN;
}
