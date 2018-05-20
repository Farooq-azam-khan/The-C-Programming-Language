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
