#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 1;
  if (x == S21_FP_PINF) {
    res = S21_FP_PINF;
  } else if (x == -S21_FP_PINF) {
    res = 0;
  } else if (x != x) {
    res = S21_FP_NAN;
  } else {
    long double rez_temp = 1;
    long double i = 1;
    while (rez_temp || -rez_temp > S21_EPSILON) {
      rez_temp *= x / i;
      res += rez_temp;
      i++;
    }
  }
  return res;
}
