#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_sqrt(double x) {
  long double y = x;
  long double y_temp = 1;
  if (x < 0) {
    y = -S21_FP_NAN;
  } else if (x == S21_FP_PINF) {
    y = S21_FP_PINF;
  } else if (x > 0) {
    while ((y_temp - y) || (y - y_temp) > S21_EPSILON) {
      y = y_temp;
      y_temp = (y_temp + (x / y_temp)) / 2;
    }
  }
  return y;
}
