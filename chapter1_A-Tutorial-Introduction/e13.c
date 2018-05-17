#include <stdio.h>
/* Exercise 1-13. Write a program to print a histogram of the lengths of words in
its input.*/

#define MAX_LEN 20
#define IN_WORD 1
#define OUT_WORD 0
int main(void)
{

  int word_len[MAX_LEN];
  // initalize word_len array
  for (int i=0; i<MAX_LEN; i++)
  {
    word_len[i] = 0;
  }

  // get input from user
  printf("Type at max %d words:\n", MAX_LEN);
  int word_status = OUT_WORD;
  int c;
  int num_words = 0;
  int char_in_word = 0;

  while((c=getchar())!=EOF)
  {
    // check if valid character
    if (c >='a'&& c<='z' || c>='A' && c<='Z')
    {
      // check if state is false
      if (word_status == OUT_WORD)
      {
        // make it true because new word is geing typed
        word_status = IN_WORD;
      }
      // increment character count for word
      ++char_in_word;
    }
    // check if new line, space, tab, ., ;, : are typed
    else if(c==' '||c=='\n'||c=='\t'||c=='.'||c==':'||c==';')
    {
      // add character count to word index and increment index
      word_len[num_words++] = char_in_word;
      word_status=OUT_WORD; // break out of word state
      char_in_word = 0; // reset character count for next word
    }
    // break if max_len has been reached
    if (num_words == MAX_LEN)
    {
      printf("array is full\n");
      break;
    }
  }


  // print histogram
  printf("index | frequency\n");
  for (int i=0; i<MAX_LEN; i++)
  {
    int val = word_len[i];
    printf("%6i|", i);
    for (int j=0; j<val; j++)
    {
      printf("%c ", '*');
    }
    printf("\n");
  }
}
