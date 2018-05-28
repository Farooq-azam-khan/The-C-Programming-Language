#include <stdio.h>
#include <limits.h>
#include <float.h>
/*
  Excersize 2-1. Write a program to determine the ranges of  char, short, int,
  and long variables, both signed and unsigned, but printing appropriate values
  from standard headers and by direct computation. Harder if you computer them:
  determine the ranges of the various floating-point types.
*/
int main(void)
{
  printf("char\n");
  printf("Signed char min: %d\n", SCHAR_MIN);
  printf("Signed char max: %d\n", SCHAR_MAX);
  printf("Unsigned char min: %d\n", 0);
  printf("Unsigned char max: %d\n", UCHAR_MAX);
  printf("\n");

  printf("int\n");
  printf("Int min: %d\n", INT_MIN);
  printf("Int max: %d\n", INT_MAX);
  printf("\n");

  printf("long\n");
  printf("Long min: %d\n", LONG_MIN);
  printf("Long max: %d\n", LONG_MAX);
  printf("Unsigned Long min: %d\n", 0);
  printf("Unsigned Long max: %d\n", LONG_MAX);
  printf("\n");

  printf("short\n");
  printf("Short min: %d\n", SHRT_MIN);
  printf("Short max: %d\n", SHRT_MAX);
  printf("Unsigned Long min: %d\n", 0);
  printf("Unsigned Long max: %d\n", USHRT_MAX);
  printf("\n");

  //TODO: for double from standard library and calculation
  return 0;
} 
