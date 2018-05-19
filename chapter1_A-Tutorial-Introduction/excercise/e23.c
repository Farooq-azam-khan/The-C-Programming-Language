#include <stdio.h>

/*
  Excercise 1-23. Write a program to "fold" long input lines into two
  or more shorter lines after the last non-blank character that occurs before the
  n-th column of input. Make sure your program does something intelligent with
  very long lines, and if there are no blanks or tabs before the specified columns.
*/
// TODO 
// constants
#define MAX_LEN 100
#define LINE_LEN 50

// vars
char inpt[MAX_LEN];
int char_len = 0;

// functions
void getLine();
void fold();
void print_inpt();

int main(void)
{
  printf("Input:\n");
  getLine();
  // print_inpt();
  printf("folded input:\n");
  fold();
  // print_inpt();
  return 0;
}

void getLine()
{
  extern char inpt[];
  extern int char_len;
  int c;
  // get input from user
  while((c=getchar())!=EOF && c!='\n')
  {
    inpt[++char_len] = c;
    if (char_len > MAX_LEN){break;}
  }
  inpt[++char_len]='\0';
}

void fold()
{
  extern char inpt[];
  extern int char_len;

  printf("executing...\n");

  // int char_lin=0;
  // for(;char_lin<char_len;char_lin++)
  // {
  //   if(char_lin%LINE_LEN==0)
  //   {
  //     inpt[char_lin] = '\n';
  //   }
  // }
}

void print_inpt()
{
  extern char inpt[];
  printf("%s", inpt);
}
