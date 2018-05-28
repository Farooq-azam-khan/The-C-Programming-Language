#include <stdio.h>

int atio(char s[]);

int main(void)
{
  char num[] = "123456";
  int n = atio(num);
  printf("num: %d", n);
}

int atio(char s[])
{
  int i, n;
  n=0;
  for(i=0;s[i]>='0'&&s[i]<='9';++i)
  {
    printf("char: %c ", s[i]);
    n = 10*n + (s[i]-'0');
    printf("num: %d \n", n);
  }
  return n;
}
