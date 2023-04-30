#include "s21_fp_utils.h"
#include "s21_math.h"

long double s21_ceil(double x) {
  long long int tmp = (long long int)x;

  if ((x != S21_FP_PINF) && (x != -S21_FP_NINF) && (tmp != x)) {
    if (x > 0) {
      x = tmp;
    } else {
      x = tmp - 1;
    }
  }

  return x;
}
