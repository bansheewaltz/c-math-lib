#include <float.h>
#include <stdbool.h>

bool s21_isninf(double x) {
  if (x < -DBL_MAX) {
    return true;
  }
  return false;
}
