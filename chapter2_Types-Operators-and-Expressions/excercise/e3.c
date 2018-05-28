#include <stdio.h>
#include <math.h>

/* Excercise 2-3. Write the function htoi(s), which converts a string of hexadecimal digits
(including an optinal 0x/0X) into its equivalent integer value. The allowable digits are
0 through 9, a-f, and A-F. */
int len(char s[]);
int htoi(char s[]);

int main(void)
{
  // int val = htoi("0x0123456789abcdefABCDEF");
  int val = htoi("0xab32");
}

int htoi(char s[])
{
  int n, i=0; // define number and char index
  int len_char = len(s); // get len of character
  int index = len_char; // define index of base (16)
  int BASE_16 = 16;
  // printf("len: %d\n", len_char);
  if (len_char>=2) // safety check for chars
  {
    // check for hex definition
    if (s[0]=='0'&&(s[1]=='x'||s[1]=='X'))
    {
      // printf("truncate first 2 chars\n");
      i=2;
      // len_char = 2;
      // want index to go to zero not 1
      index -= 3;
    }
  }

  // check which type of letter it is
  int isDig = s[i]>='0' && s[i]<='9';
  int isLowerLetter = s[i]>='a'&& s[i]<='f';
  int isCapLetter = s[i]>='A'&& s[i]<='F';
  int isValidChar = (isDig)||(isLowerLetter)||(isCapLetter);

  n = 0;
  while(isValidChar && i<len_char)
  {
    // printf("%c ", s[i]);
    int val = 0;
    // get number based on type of character
    if (isDig)
    {
      val = s[i] - '0';
      // printf(": (dig_val) %d ", val);
    }
    // fro a-f or A-F it is 10-15
    else if (isCapLetter)
    {
      val = s[i] - 'A' + 10;
      // printf(": (cap_val) %d ", val);
    }
    else if (isLowerLetter)
    {
      val = s[i] - 'a' + 10;
      // printf(": (lower_val) %d ", val);
    }
    else
    {
      break;
    }
    // printf(": (val) %d ", val);
    // printf("\n");

    // get number add it to cumulation and go to next index
    // printf("index: %d\n", index);
    n += val*(pow(BASE_16, index--));

    // redefine for next char;
    ++i;
    isDig = s[i]>='0' && s[i]<='9';
    isLowerLetter = s[i]>='a'&& s[i]<='f';
    isCapLetter = s[i]>='A'&& s[i]<='F';
    isValidChar = (isDig)||(isLowerLetter)||(isCapLetter);
  }

  printf("Number: %d\n", n);
  return n;
}

int len(char s[])
{
  int counter =0;
  while(s[counter]!='\0')
  {
    ++counter;
  }
  return counter;
}
