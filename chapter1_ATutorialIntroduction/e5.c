#include<stdio.h>
/* Modify temperature conversion program to print the
 table in reverse order, that is, from 300 degrees to 0*/
#define LOWER 0
#define UPPER 300
#define STEP 20
int main(void)
{
  float fahr, celsius;
  printf("|------------------------|\n");
  printf("| Fahrenight | Celsius   |\n");
  printf("|------------------------|\n");
  for(fahr=UPPER; fahr>=LOWER; fahr-=STEP)
  {
    celsius = 5*(fahr-32) / 9;
    printf("|%11.2f | %10.2f|\n", fahr, celsius);
  }
  printf("|------------------------|\n");
}
