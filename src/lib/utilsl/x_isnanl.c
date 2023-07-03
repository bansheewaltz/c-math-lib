#include <stdbool.h>

bool sx_isnanl(long double x) {
  if (x != x) {
    return true;
  }
  return false;
}
