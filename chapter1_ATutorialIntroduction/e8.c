#include <stdio.h>
/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#define NEWLINE '\n'
#define BLANK ' '
#define TAB '\t'
int main(void)
{
  int c;
  long nel, bla, tab;
  nel = 0;
  bla = 0;
  tab = 0;

  while((c=getchar()) != EOF)
  {
    if (c == TAB)
    {
      tab++;
    }
    else if (c == NEWLINE)
    {
      nel++;
    }
    else if (c == BLANK)
    {
      bla++;
    }
  }

  printf("blanks: %ld tab: %ld newline: %ld\n", bla, tab, nel);
}
