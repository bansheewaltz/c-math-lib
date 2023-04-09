#include <stddef.h>
#include <stdio.h>

void s21_print_bits(size_t const size, void const *const ptr) {
  unsigned char *bytes = (unsigned char *)ptr;

  for (int i = size - 1; i >= 0; i--) {
    for (int j = 7; j >= 0; j--) {
      if ((bytes[i] >> j) & 1) {
        putchar('1');
      } else {
        putchar('0');
      }
    }
  }
  puts("");
}