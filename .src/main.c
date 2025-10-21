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
  puts("\nrecursive");
  Tour_from_each_square(Tour_recursive);

  return 0;
}
