#include <stdint.h>

#include "s21_fp_utils.h"

long double s21_ceil(double x) {
  if (s21_isnan(x) || s21_isinf(x) || s21_isint(x)) {
    return x;
  }

  int64_t tmp = (int64_t)x;

  if (x > 0) {
    x = tmp + 1;
  } else {
    x = tmp;
  }

  return x;
}
