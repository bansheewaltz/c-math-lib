#include <inttypes.h>
#include <string.h>

#include "s21_math.h"

#define MANT_BITS_COUNT (DBL_MANT_DIG - 1)
#define EXP_BIT_MASK 0x7ffU
#define EXP_BIAS 1023
#define BIT_MASK_64 0xffffffffffffffffUL

long double s21_trunc(double x) {
  uint64_t input = 0;
  memcpy(&input, &x, sizeof(double));

  int exp =
      (int)((input >> (unsigned)MANT_BITS_COUNT & EXP_BIT_MASK) - EXP_BIAS);

  if (exp >= 0) {
    int frac_bits_count = MANT_BITS_COUNT - exp;

    if (frac_bits_count > 0) {
      uint64_t integral_bit_mask = BIT_MASK_64 << (unsigned)frac_bits_count;

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
