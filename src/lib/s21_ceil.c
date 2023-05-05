#include "s21_fp_utils.h"

long double s21_ceil(double x) {
  if (!s21_isfinite(x)) {
    return x;
  }
  if (s21_isint(x)) {
    return x;
  }

  long double truncated_value = s21_trunc(x);

  if (x > 0) {
    ++truncated_value;
  }

  return truncated_value;
}
