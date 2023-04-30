#include <stdbool.h>
#include <stdint.h>

#include "s21_fp_utils.h"

bool s21_isfp(double x) {
  // int fp = *(int*)&x;
  bool result = true;
  // int64_t mantissa = integral_form << 12;
  // int64_t integral_form = *(int64_t*)&x;

  // if (mantissa) {
  //   result = true;
  // }

  // return result;
  if (x - (int64_t)x == 0) {
    result = false;
  }

  return result;
}