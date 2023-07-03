#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>

#include "s21_fp_utils.h"

#define SIGN_SHIFT (sizeof(uint64_t) * CHAR_BIT - 1)

bool s21_signbit(double x) {
  union {
    double floating_point_representation;
    uint64_t unsigned_int_representation;
  } conversion;

  conversion.floating_point_representation = x;

  return (bool)(conversion.unsigned_int_representation >> SIGN_SHIFT);
}
