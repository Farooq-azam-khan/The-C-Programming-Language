#include <stdio.h>
#define MAX_LEN 1000

// TODO
/*Excercise 1-18. Write a program to remove trailing
blanks and tabs from each line of input, and to
delete entirely blank lines. */
int get_line(char line[], int lim);
int remove_trailing_whitespace(char line[], int len);

int main(void)
{
  int len;
  char line[MAX_LEN];
  printf("write line w/ trailing whitespace\n");
  while((len=get_line(line, MAX_LEN))>0)
  {
    // printf("line(w/out blanks): %s\n", line);
    // check for trailing whitespace
    for (int i=0; i<len; i++)
    {
      char c = line[i];
      if (c=='\0')
      {
        printf("\\");
        printf("0 \n");
      }
      else if (c == ' ')
      {
        printf("!");
      }
      else if (c == '\t')
      {
        printf("\\");
        printf("t");
      }
      else if (c=='\n')
      {
        printf("\\");
        printf("n");
      }
      else
      {
        printf("%c", c);
      }
    }
  }
}

int get_line(char line[], int lim)
{
  int c, i;
  for(i=0;(i<lim-1)&&((c=getchar())!=EOF)&&c!='\n';++i)
  {
    line[i] = c;
  }
  if (c=='\n')
  {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  // process line
  int new_len = remove_trailing_whitespace(line, i);
  printf("(original) length: %d ", i);
  printf("(new) length: %d\n", i);
  return new_len;
}

int remove_trailing_whitespace(char line[], int len)
{
  int new_len = len;
  char last_c = 0;
  int last_c_index = 0;
  for (int i=len; i>=2; --i)
  {
    new_len++;
    char c = line[i];
    // find last char
    // will run only once
    if (last_c == 0)
    {
      if (c >='a' && c <='z' || c>='A' && c<='Z')
      {
        last_c = c;
        last_c_index = i;
        break;
      }
      else
      {
        // otherwise random space
        new_len--;
      }
    }
  }
  // shift the '\n' and '\0' next to last char
  // and do it only after you've found last char
  if (last_c != 0)
  {
    line[last_c_index+1] = '\n';
    line[last_c_index+2] = '\0';
  }
  for (int i=last_c_index+3; i<len+1; i++)
  {
    line[i] = 0;
  }
  return new_len;
}
