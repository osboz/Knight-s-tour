// In main.c
#include "knights_tour.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  unsigned int test = tour_greedy(0, 0);
  printf("%u\n", test);  // Use printf instead of puts
  return 0;
}
