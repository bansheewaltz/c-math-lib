#include <stddef.h>

long double s21_factorial(int x) {
  if (x < 0) {
    return 0;
  }
  if (x == 0) {
    return 1;
  }

  long double res = 1.0L;  // NOLINT
  for (size_t i = 0; i <= (size_t)x; ++i) {
    res *= (long double)i;
  }

  return res;
}
