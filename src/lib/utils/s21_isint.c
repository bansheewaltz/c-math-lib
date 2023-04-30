#include <stdbool.h>
#include <stdint.h>

#include "s21_fp_utils.h"

bool s21_isint(double x) {
  if (x - (int64_t)x == 0) {
    return true;
  }
  return false;
}