#include <stdio.h>

/* pseudo-random number generator */
unsigned long int next = 1;

int rand(void);
void srand(unsigned int seed);
int main(void)
{
  srand(1); 
  for (int i=0; i<10; i++)
  {
    printf("rand num: %d\n", rand());
  }

}


/* rand: return rand int */
int rand(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536)%32768;
}
/*srand: set seet for rand() */
void srand(unsigned int seed)
{
  next = seed;
}
