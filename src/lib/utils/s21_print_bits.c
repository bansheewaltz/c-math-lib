#include <limits.h>
#include <stddef.h>
#include <stdio.h>

void s21_print_bits(size_t const size, void const *const ptr) {
  unsigned char *bytes = (unsigned char *)ptr;

  for (size_t i = size - 1; i < size; --i) {
    for (size_t j = CHAR_BIT - 1; j < CHAR_BIT; --j) {
      if ((bytes[i] >> j) & 1) {
        putchar('1');
      } else {
        putchar('0');
      }
    }
  }

  puts("");
}
