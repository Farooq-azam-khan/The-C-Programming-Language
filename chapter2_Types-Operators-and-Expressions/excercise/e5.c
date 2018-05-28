#include <stdio.h>

/* Excercise 2-5. Write the function any(s1, s2), which
returns the first location in the string s1 where any character
from the string s2 occurs, or  -1 if s1 contains no characters from s2. */
#define true 1
#define false 0

int any(char s1[], char s2[]);

int main(void)
{
  char s1[] = "hello world";
  char s2[] = "ell";
  printf("indx of %s in %s: %d\n", s2, s1, any(s1, s2));

  char s3[] = "z";
  printf("indx of %s in %s: %d\n", s2, s1, any(s1, s3));
}

int any(char s1[], char s2[])
{
  int indx = -1;
  for (int i=0; s1[i]!='\0';++i)
  {
    int found = false;
    for (int j=0; s2[j]!='\0';++j)
    {
      if (s1[i]==s2[j])
      {
        found = true;
      }
      else
      {
        continue;
      }
    }
    if (found)
    {
      indx = i;
      return indx;
    }
  }
  return indx;
}
