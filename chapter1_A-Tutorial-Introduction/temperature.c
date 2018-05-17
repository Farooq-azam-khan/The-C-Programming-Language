#include <stdio.h>

/*
  print table of temperatures from Farenheight to Celsius
*/

// constants
#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void)
{
  int fahr, celsius;

  fahr = LOWER;
  while (fahr<=UPPER)
  {
    /* apply the formula for the conversion */
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius); // display it
    // update for new temperature
    fahr = fahr + STEP;
  }

  // same thing as above but with a for loop and using floats
  printf("-------\n");
  float p_fahr, precise_celsius;

  for (p_fahr=LOWER; p_fahr<=UPPER; p_fahr+=STEP)
  {
    precise_celsius = 5 * (p_fahr - 32) / 9;
    printf("%3.2f\t%3.2f\n", p_fahr, precise_celsius);
  }
}
