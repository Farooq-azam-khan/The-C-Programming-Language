#include <stdio.h>

/* Excercise 1-12. Write a program that prints its input on word per line. */
#define IN 1
#define OUT 0

int main(void)
{
  int c, state;
  state = OUT;

  while((c=getchar()) != EOF)
  {
    // print new line if word ends
    if (c == ' ' || c == '\t' || c == '\n')
    {
      state = OUT;
      putchar('\n');
    }
    // print char if word found
    else if (state == OUT)
    {
      state = IN;
      putchar(c);
    }
    else if (state == IN)
    {
      putchar(c);
    }
  }
  return 0;
}
