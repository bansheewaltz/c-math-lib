#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void s21_print_bits(size_t const size, void const *const ptr) {
  uint8_t *bytes = (uint8_t *)ptr;

  for (size_t i = size - 1; i < size; --i) {
    for (size_t j = CHAR_BIT - 1; j < CHAR_BIT; --j) {
      if (bytes[i] >> j & 1U) {  // NOLINT
        putchar('1');
      } else {
        putchar('0');
      }
    }
  }

  puts("");
}
