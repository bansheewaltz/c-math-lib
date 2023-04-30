#include <stdbool.h>

#include "s21_fp_utils.h"

bool s21_isinf(double x) {
  if (s21_ispinf(x) || s21_isninf(x)) {
    return true;
  }
  return false;
}