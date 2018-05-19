#include <stdio.h>
/* Exercise 1-9. Write a program to copy its input to its output,
replacing each string of one or more blanks by a single blank.
*/
#define BLANK ' '

int main(void)
{
  int c;
  int prev_c;

  while((c=getchar()) != EOF)
  {
    if (!(prev_c == BLANK && c == BLANK))
    {
      putchar(c);
    }
    prev_c = c;
  }
  return 0;
}
