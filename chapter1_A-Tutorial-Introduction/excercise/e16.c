#include <stdio.h>
#define MAX_LENGTH 1000

/* Excercise 1-16. Revise the main routine of the longest-line program
so it will correctly print the length of arbritrarily long input lines, and as much
as possible of the text. */

int get_line(char line[], int max_len);
void copy(char to[], char from[]);

int main(void)
{
  int max = 0;
  int len;
  char line[MAX_LENGTH];
  char longest[MAX_LENGTH];

  printf("write lines: \n");
  while((len=get_line(line, MAX_LENGTH)) > 0)
  {
    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0)
  {
    printf("longest (%d chars):%s", max, longest);
  }
  return 0;
}

int get_line(char line[], int max_len)
{
  int c, i;
  for (i=0; (i<max_len-1)&&((c=getchar())!=EOF)&&(c!='\n'); ++i)
  {
    line[i] = c;
  }
  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i=0;
  while((to[i]=from[i])!='\0')
  {
    ++i;
  }
}
