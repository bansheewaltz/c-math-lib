#include <stdbool.h>

#include "sx_fp_utils.h"

bool sx_isinf(double x) {
  if (sx_ispinf(x) || sx_isninf(x)) {
    return true;
  }
  return false;
}
