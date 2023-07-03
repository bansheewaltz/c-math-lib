#include <stdbool.h>
#include <stdint.h>

#include "s21_fp_utils.h"

bool s21_isreal(double x) {
  if (s21_isfinite(x) && s21_trunc(x) != (long double)x) {
    return true;
  }
  return false;
}
