// In main.c
#include "knights_tour.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  srand((unsigned int)time(NULL)); // seed the random number generator
  // unsigned int test = tour_greedy(0, 0);
  // printf("%u\n", test);  // Use printf instead of puts
  puts("first");
  Tour_from_each_square(Tour_first);
  puts("\nrandom");
  Tour_from_each_square(Tour_random);
  puts("\ngreedy");
  Tour_from_each_square(Tour_greedy);

  for (int i = 1; i < 11; ++i)
  {
    printf_s("\nrecursive %i\n", i);

    unsigned int startTime = clock();

    /* column labels */
    printf("   "); /* left margin for row labels */
    for (int col = 0; col < SIZE; ++col)
      printf("%2c ", 'A' + col);
    printf("\n");

    for (int y = 0; y < SIZE; ++y)
    {
      /* row label (1-based) */
      printf("%2d  ", y + 1);

      for (int x = 0; x < SIZE; ++x)
      {
        unsigned int count = Tour_recursive(x, y, i);
        printf("%2u", count);
        if (x < SIZE - 1)
          putchar(' ');
      }
      printf("\n");
    }

    printf_s("time used, %ds\n", (clock() - startTime) / 1000);
  }
}
