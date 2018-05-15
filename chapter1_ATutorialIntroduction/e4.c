#include <stdio.h>

/* Write a program to print the corresponding C -> F */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void)
{
  // heading
  printf("-----------------------\n");
  printf("Celsius | Fahrenheight \n");
  printf("-----------------------\n");
  float fahr, celsius;
  for (celsius=LOWER; celsius<=UPPER; celsius+=STEP)
  {
    fahr = ((celsius*9)/5) + 32;
    printf("%7.2f | \t%5.2f\n", celsius, fahr);
  }
  printf("-----------------------\n");
}
