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

## Line counting
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
