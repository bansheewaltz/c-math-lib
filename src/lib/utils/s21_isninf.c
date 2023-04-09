#include <float.h>
#include <stdbool.h>

bool s21_isninf(double x) {
  if (x < DBL_MIN) {
    return true;
  }
  return false;
}