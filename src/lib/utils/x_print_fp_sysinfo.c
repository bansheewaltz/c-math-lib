#include <float.h>
#include <stdio.h>

#ifdef JUST_PRINT
#define sx_print_fp_sysinfo main
#endif

void sx_print_fp_sysinfo(void) {
  puts("");

  printf("floating point types' characteristics on this machine:\n");
  puts("");

  printf("%-10s  %s  %s  %s  %-32s\n",  //
         "TYPE", "SIZE", "MANT", "PRECISION", "RANGE");
  puts("-------------------------------------------------------------------");
  printf("%-12s  %2zu   %-3d  %-2d digits  %-14e .. %-14e\n",  //
         "float", sizeof(float), FLT_MANT_DIG, FLT_DIG, FLT_MIN, FLT_MAX);
  printf("%-12s  %2zu   %-3d  %-2d digits  %-14e .. %-14e\n",  //
         "double", sizeof(double), DBL_MANT_DIG, DBL_DIG, DBL_MIN, DBL_MAX);
  printf("%-12s  %2zu   %-3d  %-2d digits  %-14Le .. %-14Le\n",  //
         "long double", sizeof(long double), LDBL_MANT_DIG, LDBL_DIG, LDBL_MIN,
         LDBL_MAX);
}
