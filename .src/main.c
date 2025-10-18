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
  puts("greedy");
  tour_from_each_square(GREEDY);
  puts("\nrandom");
  tour_from_each_square(RANDOM);

  return 0;
}
