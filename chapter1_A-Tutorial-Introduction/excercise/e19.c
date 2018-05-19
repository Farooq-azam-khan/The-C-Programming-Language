#include <stdio.h>
#define A_LEN 1000
/*Excercise 1-19. Write a function reverse(s) that reverses the
character string s. Use it to write a program that reverses
its input a line at a time. */

int get_line(char line[], int lim);
void reverse(char line[]);

int main(void)
{
  int len;
  char line[A_LEN];
  printf("write line\n");
  while((len=get_line(line, A_LEN)) > 0)
  {
    reverse(line);
    printf("reverse: %s\n", line);
  }
  return 0;
}


int get_line(char line[], int lim)
{
  int i,c;
  for(i=0;(i<lim-1)&&((c=getchar())!=EOF)&&c!='\n';++i)
  {
    line[i] = c;
  }
  if(c='\n')
  {
    line[i++]=c;
  }
  line[i]='\0';
  return i;
}

void reverse(char s[])
{
  int len;
  //fined the length
  for(len=0;s[len]!='\0'; len++){}
  // check if last elemnt is len
  if(s[len-1]=='\n'){len--;}

  /*   eg: a, b, c, d, e, g
      rev: g, e, d, d, b, a
    (odd): a, b, c, d, e
         : e, d, c, b, a
  for odd len will == i so it will switch with itself
  */
  for (int i=0;i<len; i++, --len)
  {
    int tmp = s[len];
    s[len] = s[i];
    s[i] = tmp;
  }

}
