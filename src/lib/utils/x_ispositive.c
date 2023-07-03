#include <stdbool.h>

#include "sx_fp_utils.h"

bool sx_ispositive(double x) {
  if (sx_signbit(x) == 0) {
    return true;
  }
  return false;
}
