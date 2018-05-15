#include <stdio.h>

/* Exercise 1-10. Write a program to copy its input to its output,
replacing wach tab by \t, backspace by \b, and each backslash by \\.*/

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'

int main(void)
{
  int c;
  while((c=getchar())!=EOF)
  {
    if(c==TAB)
    {
      putchar('\\');
      putchar('t');
      putchar(' ');
    }
    // TODO: find way to test
    else if (c==BACKSPACE)
    {
      putchar('\\');
      putchar('b');
      putchar(' ');
    }
    else if (c==BACKSLASH)
    {
      putchar('\\');
      putchar('\\');
      putchar(' ');
    }
    else
    {
      putchar(c);
    }
  }
  return 0; 
}
