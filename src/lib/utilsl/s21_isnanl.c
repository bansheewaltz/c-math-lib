#include <stdbool.h>

bool s21_isnanl(long double x) {
  if (x != x) {
    return true;
  }
  return false;
}
