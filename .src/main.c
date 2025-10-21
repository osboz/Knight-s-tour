#include "knights_tour.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  srand((unsigned int)time(NULL)); // seed the random number generator

  // run the diffrent tours
  puts("First");
  Tour_from_each_square(Tour_first);
  puts("\n\nRandom");
  Tour_from_each_square(Tour_random);
  puts("\n\nWarnsdorff");
  Tour_from_each_square(Tour_warnsdorff);
  puts("\n\nBrute force");
  Tour_from_each_square(Tour_brute_force);
}
