#include <stdio.h>

/* Modify the temperature conversion program to
print a heading above the table. */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void)
{
  // heading
  printf("-----------------------\n");
  printf("Fahrenheight | Celsius\n");
  printf("-----------------------\n");
  float fahr, celsius;
  for (fahr=LOWER; fahr<=UPPER; fahr+=STEP)
  {
    celsius = 5 * (fahr - 32) / 9;
    printf("%12.2f | \t%5.2f\n", fahr, celsius);
  }
  printf("-----------------------\n");
}
