#include <stdio.h>

int main(void)
{
  long nc; // number of characters
  nc = 0;
  while(getchar() != EOF)
  {
    ++nc;
  }
  printf("%ld\n", nc);
}
