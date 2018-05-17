#include <stdio.h>

/* counts words, new line, new character */

#define IN 1
#define OUT 0

#define NEWLINE '\n'
#define SPACE ' '
#define TAB '\t'


int main(void)
{
  int c, nc, nw, nl, state;

  state = OUT;
  nl=nw=nc=0;

  while((c=getchar()) != EOF)
  {
    ++nc;
    if(c == NEWLINE){++nl;}
    if (c==NEWLINE || c==TAB || c==SPACE)
    {
      state = OUT;
    }
    else if (state == OUT)
    {
      state = IN;
      ++nw;
    }
  }
  printf("lines: %d words: %d chars: %d \n", nl, nw, nc);
  return 0;
}
