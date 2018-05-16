#include <stdio.h>
/*Exercise 1-14. Write a program to print a histogram of the frequencies of different
characters in its input. */

#define ENG_LETTERS 26

void print_array(int arr[]);

int main(void)
{
  int letter_freq[ENG_LETTERS];
  // initalize
  for (int i=0; i<ENG_LETTERS; i++)
  {
    letter_freq[i] = 0;
  }

  int c;
  while((c=getchar())!=EOF)
  {
    int char_index;
    if (c>='a'&&c<='z')
    {
      char_index = (int)(c - 'a');
      letter_freq[char_index]++;
    }
    else if (c>='A'&&c<='Z')
    {
      char_index = (int)(c-'A');
      letter_freq[char_index]++;
    }
    // if (c == '\n' || c=='\t' || c==' ')
    // {
    //   print_array(letter_freq);
    // }
  }

  printf("Letter | Frequency \n");
  for (int i=0; i<ENG_LETTERS; i++)
  {
    int val = letter_freq[i];
    printf("      %c| %i: ", (char) i + 'a', val);
    for (int j=0; j<letter_freq[ENG_LETTERS]; j++)
    {
      printf("%c", '*');
    }
    printf("\n");
  }
}


void print_array(int arr[])
{
  for (int i=0; i<ENG_LETTERS; i++)
  {
    printf("%i ", arr[i]);
  }
  printf("\n");
}
