#include <stdio.h>

/* Excercise 2-4: Write an alternate version of equeeze(s1, s2) that
deltes each character in s1 that matches any character in string s2. */

/* delete_char: deltes matching har from s1 that is in s2 */
void delete_chars(char s1[], char s2[]);

int main(void)
{
  char s1[] = "hello world";
  char s2[] = "wo";
  delete_chars(s1, s2);
  printf("delted: %s -> s1: %s\n", s2, s1);

}

/* deltes matching har from s1 that is in s2 */
void delete_chars(char s1[], char s2[])
{
  int i, j, new_i;
  for (i=new_i=0; s1[i]!='\0'; i++)
  {
    printf("s1: %c\n", s1[i]);
    int found_same_char = 0;
    for (j=0;s2[j]!='\0'; j++)
    {
      // printf("s2: %c\n", s2[j]);
      if (s1[i]==s2[j])
      {
        found_same_char = 1;
        continue;
      }
    }
    if (!found_same_char)
    {
      s1[new_i++] = s1[i];
    }
  }
  s1[new_i]='\0';
}
