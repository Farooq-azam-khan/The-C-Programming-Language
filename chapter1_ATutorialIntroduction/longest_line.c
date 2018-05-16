
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
int getLine(char line[], int lim);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
  int len;                  /* length of current line */
  int max;                  /* length of maximum line seen */
  char line[MAXLINE];       /* current input line */
  char longest[MAXLINE];    /* longest line seen so far */


  max = 0;
  while((len=getLine(line, MAXLINE)) > 0)
  {
    if (len>max)
    {
      max = len;
      copy(longest, line);
      printf("%s", longest); 
    }
  }
  if (max>0) /* indication of a line */
  {
    printf("%s", longest);
  }
  return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
  int c, i;
  for (int i=0; i<lim-1 && (c=getchar()!=EOF&&c!='\n'); ++i)
  {
    // put character into array s
    s[i] = c;
  }
  // adding index for a new line becuase we want to return 0 when it is EOF
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  // this is end of string
  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to': assume 'to' is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;

  /* as long as end of file is not reached copy i'th index */
  while((to[i] = from[i] !='\0'))
  {
    ++i;
  }
  // don't need to return to[] because arrays are pass by reference.
}
