long double s21_factorial(int x) {
  if (x < 0) {
    return 0;
  }
  if (x == 0) {
    return 1;
  }

  return (long double)x * s21_factorial(x - 1);
}
