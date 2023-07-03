#include <stdbool.h>

#include "s21_fp_utils.h"

bool s21_ispositive(double x) {
  if (s21_signbit(x) == 0) {
    return true;
  }
  return false;
}
