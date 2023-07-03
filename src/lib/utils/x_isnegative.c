#include <stdbool.h>

#include "sx_fp_utils.h"

bool sx_isnegative(double x) {
  if (sx_signbit(x) == 1) {
    return true;
  }
  return false;
}
