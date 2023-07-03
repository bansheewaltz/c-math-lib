#include <stdbool.h>

#include "s21_fp_utils.h"

bool s21_isfinite(double x) {
  if (s21_isinf(x) || s21_isnan(x)) {
    return false;
  }
  return true;
}
