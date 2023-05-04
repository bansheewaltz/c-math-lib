#include <inttypes.h>
#include <string.h>

#include "s21_math.h"

#define FRAC_PART_BITS_COUNT 52
#define EXP_BIT_MASK 0x7ff
#define EXP_BIAS 1023
#define BIT_MASK_64 0xffffffffffffffff

long double s21_trunc(double x) {
  uint64_t input;
  memcpy(&input, &x, sizeof(double));

  int exponent =
      (int)(((input >> FRAC_PART_BITS_COUNT) & EXP_BIT_MASK) - EXP_BIAS);

  if (exponent >= 0) {
    int fractional_bits_count = FRAC_PART_BITS_COUNT - exponent;

    if (fractional_bits_count > 0) {
      uint64_t integral_bit_mask = BIT_MASK_64 << fractional_bits_count;

      uint64_t output = input & integral_bit_mask;
      memcpy(&x, &output, sizeof(double));
    }
  } else {
    if (x < 0) {
      x = -0.0;
    } else {
      x = 0.0;
    }
  }

  return x;
}
