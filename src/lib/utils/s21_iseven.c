#include <stdbool.h>

#include "s21_fp_utils.h"
#include "s21_math.h"

bool s21_iseven(double x) {
  if (s21_isint(x) && s21_fabs(s21_fmod(x, 2.0)) < S21_EPSILON) {  // NOLINT
    return true;
  }
  return false;
}
