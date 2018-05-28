# Types, Operators, and Expressions
- Vars and constants are basic data objects
- With ANSI:
  - `signed` and `unsigned` forms of all integer types
  - floating type operations may be done in single precision
  - `long` and `double` extend precision.
  - string constants may be concatenated at compile time
  - can have `const`

## 1 Variable Names
- first char must be letter
- can use "_" but don't begin variable names with them because library routines use such conventions
- case sensitive
-  use lower case for variables and all uppercase for constants
- keywords (`if`/`while`/`for`...) cant be used as variable names

## 2 Data Types and Sizes
- `char`: 1 byte (8 bits) holds one character
  - `unsigned char` is between 0 and 255
  - `signed char` -128 and 127 (2's compliment)
  - __printable chars__ always __un-signed__
- 'int': reflects natural size on host machine
  - `short int sh;` -> `short sh;` it is 16 bits
  - `long int counter;` -> `long counter;` 32 bits
- `float`: single precision IEEE format
- `double`: double precision IEEE format
- `long` and `double` specifies extended-precision floating point. There are distinct sizes and the standard headers `<limits.h>` and `<float.h>` contain symbolic constants for all of these sizes

## 3 Constants
- `long` constant is written with a terminal `l` or `L`
- unsigned constants are written with `ul` or `UL`
- suffix `f` or `F` indicates `float` constant and `L` or `l` indicates `long double`
- can write integer in __octal__ (base 8) or __hex__ (base 16)
  - for octal the prefix is `0` and for hex is `0x`
  - can also be followed by `l` or `u`
- character constants are written with single quotations
- can also specify arbitrary byte-sized bit pattern w/ `\ooo` where `ooo` is one to 3 octal digits or w/ `\xhh` where `hh` is one or more hex digits.
- the character constant `''\0'` represents the character with value zero (null character). Just written for emphasis.
- _Constant expression_ is an expression that involves only constants. May be evaluated during compilation rather than run-time.
- _string constant/literal_ is a sequence of zero or more characters surrounded by double quotes. This is an array of characters. The internal representation of a string has a null character `'\0'` at the end, so the physical storage is `strlen(str)+1`.
  - `strlen(s)` return the length of the string (excluding the `'\0'` and is in the `<string.h>` file.
  - be carefule `'x'` is not the same as `"x"`.
```C
/* strlen: return length of s */
int strlen(char s[])
{
     int i;
     while(s[i] != '\0')
     {
       ++i;
     }
     return i;
}
```
- _Enumeration constant_ is a list of constant integer values
  - _names_ in different enumerations must be different, but _values_ need not be distinct in the same enumerations
  - eg
```C
enum boolean {NO, YES};
enum escapes {BELL='\a', BACKSPACe='\b', TAB='\t',
NEWLINE='\n', VTAB='\v', RETURN='\r'};
/* If not all values are specified,
unspecified values continue the
progression from the last specified value.
Here FEB=2, MAR=3 */
enum months {JAN=1, FEB, MAR, APR, MAY, JUN,
JUL, AUG, SEP, OCT, NOv, DEC};
```
- Enumerations provide a convenient way to associate constant values with names, an alternative to `#define` with the advantage that the values can be generated for you.

## 4 Declarations
- all variables must be declared before use. A declaration specifies a type, and contains a list of one or more variables of that type
- if the variable is not _automatic_ the initialization is done once only, and the initializer must be a constant expression.
- an explicitly initialized automatic variable is initialized each time the function or block it is in is entered
- external and static variables are initialized to zero by default.
- qualifier `const` ca be applied to the declaration of any variable to specify that its value will not be changed
```C
const double e = 2.71828182845;
const char msg[] = "warning: ";
```
- `const` can also be used with parameters for arrays so as to indicate that values cannot be changed
```C
int strlen(const char[]);
```
# 5/6 Arithmetic Operators/Relational and Logical Operataors
- Binary arithmetic operators `+, -, *, /, %`
```C
/* example of mod: leap year */
int yr = 2018; // year
if((yr%4==0 && yr%100!=0) || yr%400==0)
{
  printf("%i is a leap year", yr);
}
else
{
  printf("%i is not a leap year", yr);
}
```
- relational operators: `>, >=, <, <=`, all have same precedence. Below them in precedence are `==, !=`.
Relation operators have lower precedence than arithmetic operators. Eg `i<lim-1` is same as `i<(lim-1)`.
- logical operators `&&` and `||` are evaluated left to right. `&&` is higher in precedence thank `||` and both are lower than relational and equality operators

## Type Conversion

- `atoi()` converts string of integers to digits.
``` C
/* atoi: convert s to integer */
int atio(char s[])
{
  int i, n;
  n = 0;
  // iterate if char is a digit
  for (i=0; s[i]>='0' && s[i]<='9'; ++i)
  {
    n = 10 * n + (s[i] - '0');
  }
  return n;
}
```
- `lower()` converts uppercase letter to lowercase
```C
/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
  if (c>='A'&& c<='Z')
  {
    return c+ 'a'-'A';
  }
  else
  {
    return c;
  }
}
```
- standard library `<ctype.h>` is used for these sort of operations.
- implicit arithmetic conversions work by promoting the "lower" type to a "higher" type before the operation proceeds.
- for unsigned operands:
  - if either operand is `long double`, convert other to it
  - else if either operand is `double` convert other to it
  - else if operand is `float` convert other to it
  - else convert `char` and `short` to `int`
  - then, if either operand is `long` convert other to `long`
- comparison between signed and unsigned values are machine-dependent, because they depend on size of integer types. Lets say `int` is 16 bit and `long` 32 bit
  - `-1L<1U`: because `1U` which is an `int` is promoted to a signed long
  - `-1L>1UL`: because `-1L` is promoted to `unsigned long` and thus appears to be a larger positive number.
  - conversion from higher order to lower order (`double` to `float` or `int` to `char`) looses information by truncating the most significant bits.
  - type conversion takes place when arguments are passed to functions as well. This is why, even if functions types are `char` and `float` they are declared as `int` and `double` respectively.
  - explicit type conversions can be forced ("coerced") in any expression via a unary operator called a `cast`: `(type-name) expression`
    - eg: `sqrt()` expects `double` thus if we pass `int` we have to cast it as `sqrt((double) n);`
    - this is not needed per-say because `C` is smarter and automatically will cast the argument/s.

```C
/* pseudo-random number generator */
unsigned long int next = 1;
/* rand: return rand int */
int rand(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536)%32768;
}
/*srand: set seet for rand() */
void srand(unsigned int seed)
{
  next = seed;
}
```
## 8 Increment and Decrement Operators
- `++` and `--`, there is also post and pre increment/decrement.
- can only be applied to variable so `(i+j)++` is illegal.
```C
/*squeeze: delete all c form s*/
void squeeze(char s[], int c)
{
  int i, j;
  for (i=j=0; s[i]!='\0';i++)
  {
    if(s[i]!=c)
    {
      s[j++]=s[i];
    }
  }
  s[j] = '\0';
}
```
```C
/* concatenate two strings: s must be big enough */
void strcat(char s[], char t[])
{
  // i== index for s, and j== index for t
  int i, j;
  i=j=0;
  // find end of string
  while(s[i]!='\0'){i++;}
  
  // i== len(s)-1, j==0;
  // copy t to s
  while((s[i++]=t[j++])!='\0'){;}
}
```
