#include <stdio.h>
#define MAX_LENGTH 1000

int get_line(char line[], int lim);
void copy(char to[], char from[]);

int main(void)
{
  printf("Type a series of lines and I will give you ");
  printf("the longest one\n");

  int max;                    /* length of max line */
  int len;                    /* length of current line */

  char line[MAX_LENGTH];      /* character array of current line */
  char longest[MAX_LENGTH];   /* character array of longest line */

  max = 0;
  while((len=get_line(line, MAX_LENGTH))>0)
  {
    if (len>max)
    {
      max = len;
      copy(longest, line);
    }
  }
  /* if len > 0 means that there was input 1 or greater */
  if (max > 0)
  {
    printf("longest line: %s\n", longest);
  }
  return 0;
}

/* function that asks user for input */
int get_line(char line[], int lim)
{
  int c, i;

  for (i=0; (i<lim-1) && ((c=getchar()) !=EOF) && c!='\n'; ++i)
  {
      line[i] = c;
  }
  if (c=='\n')
  {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/* copy the value from one array to another: */
void copy(char to[], char from[])
{
  int i=0;
  while((to[i] = from[i]) != '\0')
  {
    i++;
  }
}
