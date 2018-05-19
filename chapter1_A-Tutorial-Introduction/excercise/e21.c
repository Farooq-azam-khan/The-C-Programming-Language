#include <stdio.h>

/*
  Excercise 1-21. Write a program entab that replaces strings of blanks by
  the minimum number of tabs and blanks to achieve the same spacing.
  Use same tab stops as for detab. When either a tab or a single blank would
  suffice to reach a tab stop, which should be given preference?
*/

// constants
#define TAB '\t'
#define TAB_EQ "     " // tab width = 4 here
#define MAX_LEN 100
// vars
char inpt[MAX_LEN];
int char_num = 0;

// functions
void entab();
void getLine();
void print_inpt();

int main(void)
{

  getLine();
  print_inpt();
  entab();

  return 0;
}

void entab()
{
  extern char inpt[];
  extern int char_num;

  printf("Will printf equivalent:\n");
  for (int i=0;i<char_num;i++)
  {
    if (inpt[i] == TAB)
    {
      printf("%s", TAB_EQ);
    }
    else
    {
      printf("%c", inpt[i]);
    }
  }
}


void getLine()
{
  extern char inpt[];
  extern int char_num;
  int c,i=0;
  while((c=getchar()) !=EOF && c!='\n')
  {
    inpt[i++] = c;
    char_num++;
    if (i>=MAX_LEN)
    {
      printf("input len overreached\n");
      break;
    }
  }
  inpt[++i]='\0';
}

void print_inpt()
{
  extern char inpt[];
  extern int char_num;
  for (int i=0;i<char_num;i++)
  {
    char c = inpt[i];
    if (c == TAB)
    {
      printf("\\");
      printf("t");
    }
    else
    {
      printf("%c", c);
    }
  }
  printf("\n");
}
