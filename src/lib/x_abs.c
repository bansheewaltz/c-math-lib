#include <limits.h>

int sx_abs(int x) {
  if (x == INT_MIN) {
    return x;
  }
  if (x < 0) {
    return -x;
  }
  return x;
}
