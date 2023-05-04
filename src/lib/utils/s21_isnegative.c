#include <stdbool.h>

#include "s21_fp_utils.h"

bool s21_isnegative(double x) {
  if (s21_signbit(x) == 1) {
    return true;
  }
  return false;
}
