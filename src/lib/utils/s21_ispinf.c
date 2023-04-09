#include <float.h>
#include <stdbool.h>

bool s21_ispinf(double x) {
  if (x > DBL_MAX) {
    return true;
  }
  return false;
}