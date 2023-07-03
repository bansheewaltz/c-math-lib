#include <stdbool.h>

bool sx_isnan(double x) {
  if (x != x) {
    return true;
  }
  return false;
}
