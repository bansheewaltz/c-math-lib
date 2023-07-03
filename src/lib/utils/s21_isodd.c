#include <stdbool.h>

#include "s21_fp_utils.h"
#include "s21_math.h"

bool s21_isodd(double x) {
  if (s21_isint(x) && !s21_iseven(x)) {  // NOLINT
    return true;
  }
  return false;
}
