# Chapter 1: A Tutorial Introduction

## 1.1 The First `C` Program
``` C
#include <stdio.h>
int main(void)
{
  printf("hello World\n");
}
```
- The `#include <stdio.h>` loads in a library for standard input and output.
  - This is done for the `printf("Hello World\n");` command.
  - `\n` means new line and counts as only one character. There are other special scharacters: `\t` for tab, `\b` for backspace, `\"` for double quote, and  `\\` for backslash.
- The `int main(void){}` is a function decloration.

## 1.2/1.3 Variables and Arithmetic Expressions/For Loop
``` C
#include <stdio.h>
int main(void)
{
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper)
  {
    /* apply the formula for the conversion */
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius); // display it
    // update for new temperature
    fahr = fahr + step;
  }
}
```
- `/**/` is a multi-line comment
- __variables__ store data in memory. The amount of data that can be store depends on the use in `C`.
  - Types of storage: `char`, `int`, `float`, `double`, `long`, `short`
- `while` command performs the commands in its body until the condition provided turns false.
- Check `temperature.c` for different looping mechanism.
- Magic numbers are not that easy to understand thus they can be put as constants: `#define name replacement text`.

## 1.5 Character Input and Output
- _Text Stream_ is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character.
- simples: `getchar` and `putchar`
  - `c = getchar()` gets input a character at a time.
  - `putchar(c)` print character of the integer variable as a character.

  ``` C
  #include <stdio.h>
  /* Copy input to output: 1st Version */
  main()
  {
    int c;
    c = getchar();
    while(c != EOF)
    {
      putchar(c);
      c = getchar();
    }
  }
  ```
- `!=` mean does not equal to.
- the reason `int` is used instead of `char` for the variable `c` is because `getchar()` returns a distinctive value when there is no more input. That input cannot be confused with any real character. Variable `c` must be big enough to hold return type of `getchar()`, but `char` cannot do that, i.e. hold `EOF`; thus, `int`is used.
- `EOF` is "End of File". It is an integer defined in `<stdio.h>`.
- `=` is an __assignment operator__, meaning it can appear anywhere as part of a larger expression.
``` C
#include<stdio.h>
/* copy input to output: 2nd version */
main()
{
  int c;
  while(c=getchar() != EOF)
  {
    putchar(c);
  }
}
```
- the parentheses in the `while` condition are necessary because `!=` is higher than `=`.
  - this would mean `c = getchar() != EOF` is same as `c = (getchar() != EOF)`. Here c is either true or false.

- following code counts characters
``` C
#include <stdio.h>
/* count characters in input */
main()
{
  /* 1st version */
  long nc;
  nc = 0;
  while(getchar() != EOF)
  {
    ++nc;
  }
  printf("%ld\n", nc);

  /* 2nd version */
  double nc_double;
  for(nc_double=0; getchar() != EOF; ++nc_double){;}
  printf("%.0f\n", nc);
}
```
- `++nc` is a __pre-increment__ operator, which means that the var is incremented by 1 before it is used.

### Line counting
- counting lines is just counting `\n`.
``` C
/* count lines in input */
main()
{
  int c, nl;
  nl = 0;
  while((c=getchar()) != EOF)
  {
    if (c == '\n')
    {
      ++nl;
    }
  }
  printf("%ld\n", nl);
}
```
### Word Counting
- __word__ is defined as: _any sequence of characters that does not contain a blank, tab or newline._

``` C
#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
main()
{
  int c, nl, nw, nc, state;

  state = OUT; // outside a word by default
  nl = nw = nc = 0; // default initial state of counters
  while((c=getchar()) != EOF)
  {
    ++nc;
    if (c == '\n')
    {
      ++nl
    }
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
    }
    else if (state == OUT)
    {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
  return 0;
}
```
- once the first character of a word is received then it is counted as a word. `state` records if program is in a word or not.
- `nl = nw = nc = 0`: assignment is an expression with a value and assignments associated from right to left. Same as
`n1 = (nw = (nc = 0))`
- `||` means `OR`, `&&` is `AND`.

## 1.6 Arrays
``` C
#include <stdio.h>
/* count digits, white space, others */
main()
{
  int c, i, nwhite, nother;
  int ndigit[10]; // array with size

  // initalize
  nwhite = nother = 0;
  for (int i=0; i<10; i++)
  {
    ndigit[i] = 0;
  }

  while((c=getchar()) != EOF)
  {
    if (c>='0' && c <='9')
    {++ndigit[c-'0'];}
    else if (c==' ' || c == '\n' || c == '\t')
    {++nwhite;}
    else{++nother;}
  }

  printf("digits=");
  for(i=0;i<10;++i){printf(" %d",ndigit[i]);}
  printf(", white space = %d, other = %d\n", nwhite, nother);
}
```
- ndigit is an array of 10 integers.

## 1.7/1.8 Functions / Arguments - Call by Value
- `Fortran` has _subroutines_, `Pascal` has _procedures_, in `C` we have _functions_.
- convenient way to encapsulate encapsulation. Don't have to worry about implementation, just its input and output.

``` C
#include <stdio.h>
/* implement power function*/

int power(int m, int n);
main()
{
  int i;
  for (i=0; i<100; i++)
  {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
  }
}

/*power: raise base to n-th power; n>=0*/
int power(int base, int n)
{
  int i, p;
  p = 1;
  for (i = 1; i<= n; ++i)
  {
    p = p*base;
  }
  return p;
}
```
- all function args are pass by "value" i.e. swapping function won't work.
- pass by value gets a copy of the arguments when the function is called rather than the value that is store in memory.
- this is an _asset not a liability. It leads to more compact programs with fewer extraneous variables, i.e. you don't have to make temp vars of your parameters whenever you want to alter them._
- simpler implementation of power function, count down the variable n:

``` C
#include <stdio.h>
#define MAX_LENGTH 1000

int get_line(char line[], int lim);
void copy(char to[], char from[]);

int main(void)
{
  printf("Type a series of lines and I will give you ");
  printf("the longest one\n");

  int max;                    /* length of max line */
  int len;                    /* length of current line */

  char line[MAX_LENGTH];      /* character array of current line */
  char longest[MAX_LENGTH];   /* character array of longest line */

  max = 0;
  while((len=get_line(line, MAX_LENGTH))>0)
  {
    if (len>max)
    {
      max = len;
      copy(longest, line);
    }
  }
  /* if len > 0 means that there was input 1 or greater */
  if (max > 0)
  {
    printf("longest line: %s\n", longest);
  }
  return 0;
}

/* function that asks user for input */
int get_line(char line[], int lim)
{
  int c, i;

  for (i=0; (i<lim-1) && ((c=getchar()) !=EOF) && c!='\n'; ++i)
  {
      line[i] = c;
  }
  if (c=='\n')
  {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/* copy the value from one array to another: */
void copy(char to[], char from[])
{
  int i=0;
  while((to[i] = from[i]) != '\0')
  {
    i++;
  }
}
```
- reason `get_line()` has the arguments `MAX_LENGTH` even though it is a constant is because if we want to put it in a different file for broader use then we can.
- way in which arrays are pass as parameters are as following: `copy(int arr[])` -> note arrays are not pass by value. You do not need to return them if you want the contents they are modified when you use the function.
- `\0` is the _null character_ whose value is zero. It is added to the end of the character array to indicate the end of the array.

## 1.10 External Variable and Scope
- variables in a functions are local so no other function can have access to them. known as __automatic__ variables.
- there are also __external__ variables i.e. they can be accessed by any function. They must be declared in the outer most block. __External variables__ exist permanently even after the function that has declared has returned. These must be defined only once outside of any function, and must be declared (w/ `extern` command) in any function that wants to use it.

```C
#include <stdio.h>
#define MAXLINE 1000

/** this file demostrant the external vars and the extern cmd */
// external variables
int max;
char line[MAXLINE];
char longest[MAXLINE];

// fuction decleration
int get_line(void);
void copy(void);

int main(void)
{
  int len;
  // declare external vars
  extern int max;
  extern char longest[];

  max = 0;
  while((len=get_line())>0)
  {
    if(len > max)
    {
      max = len;
      copy();
    }
  }
  if(max>0)
  {
    printf("(max) %s", longest);
  }
  return 0;
}

int get_line(void)
{
  int c, i;
  extern char line[];

  for(i=0; (i<MAXLINE-1)&& (c=getchar())!=EOF
            &&c!='\n'; ++i)
  { line[i]=c; }

  if (c=='\n') { line[i++] = c; }
  line[i] = '\0';
  return i;

}

void copy(void)
{
  int i;
  extern char line[], longest[];
  i=0;
  while((longest[i]=line[i])!='\0')
  {
    ++i;
  }
}
```

- the `extern` declaration can be omitted if the definitio of an
external variable occurs in the source file before its use in a particular function
  - the `extern` declarations in `main`, `getline`, `copy` are redundant
  - if for example there were three files, and `file1` had a variable that was needed in `file2` and `file3`, the `extern` declaration would be needed in `file2` and `file3` to connect the occurrences of the variables.
  - usual practice is to collect `extern` declarations of variables and functions in a separate file, __header__, it is included by `#include` and the file extension `.h` is also conventional.

- __Define__ and __declaration__ have different meanings in this context.
  - _definition_: refers to place where variable is created or assigned storage
  - _declaration_: refers to places where the nature of the variable is state but no storage is allocated.
