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
  puts("\n\nrandom");
  Tour_from_each_square(Tour_random);
  puts("\n\nwarnsdorff");
  Tour_from_each_square(Tour_warnsdorff);


  for (int i = 10; i < 100; ++i)
  {
    if (i > SIZE * SIZE)
      continue;

    unsigned int startTime = clock();
    printf_s("\n\nrecursive %i\n", i);
    /* column labels */
    printf("    "); /* left margin for row labels */
    for (int col = 0; col < SIZE; ++col)
      printf("%2c ", 'A' + col);
    printf("\n    ---------------------------\n");

    for (int y = 0; y < SIZE; ++y)
    {
      /* row label (1-based) */
      printf("%2d | ", y + 1);

      for (int x = 0; x < SIZE; ++x)
      {
        unsigned int count = Tour_brute_force(x, y, i);
        printf("%2u", count);
        if (x < SIZE - 1)
          putchar(' ');
      }
      printf("\n");
    }

    printf_s("time used, %ds\n", (clock() - startTime) / 1000);
  }
}
