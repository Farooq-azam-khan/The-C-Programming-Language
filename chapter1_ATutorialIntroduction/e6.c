#include <stdio.h>

/* Verify that the expression getchar() != EOF is 0 or 1*/

main()
{
  int c = getchar();
  while(c != EOF)
  {
    printf("%i", getchar() != EOF);
  }
  return 0;
}
