#include <stdio.h>

/* Exercise 1-21. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop.
Assume a fixed set of tab stops, say every n columns. Should n be a variable or a
symbolic parameter? */

// constants
#define TAB '\t'
#define TAB_EQ "     "
#define INPT_LEN 1000

// vars
char inpt[INPT_LEN];
int char_num = 0;

// functions
void detab();
void getLine();
void print_inpt();

int main(void)
{

  // print the input where '\t' is a string
  printf("Write your input:\n");
  getLine();
  print_inpt();
  detab();
}

void detab()
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
  // printf("\n");
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
    if (i>=INPT_LEN)
    {
      printf("input len overreached\n");
      break;
    }
  }
  inpt[++i]='\0'; 
  // printf("%s", inpt);
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
