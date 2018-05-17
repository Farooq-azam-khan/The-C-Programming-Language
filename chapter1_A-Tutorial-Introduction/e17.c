#include <stdio.h>
#define MAX_LENGTH 1000

/* Excercise 1-17. Write a program to print al input lines
that are longer than 80 characters. */

int get_line(char line[], int max_len);

int main(void)
{
  int len;
  char line[MAX_LENGTH];

  while((len=get_line(line, MAX_LENGTH)) > 0)
  {
    if (len > 80)
    {
      printf("line(80+ chars): %s", line);
    }
  }
}

int get_line(char line[], int max_len)
{
  int c, i;
  for(i=0;(i<max_len-1)&&(c=getchar())!=EOF&&c!='\n'; ++i)
  {line[i] = c;}
  if (c=='\n'){line[i]=c;++i;}
  line[i] = '\0';
  return i;
}
