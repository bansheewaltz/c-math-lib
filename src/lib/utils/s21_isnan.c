#include <stdbool.h>

bool s21_isnan(double x) {
  if (x != x) {
    return true;
  }
  return false;
}