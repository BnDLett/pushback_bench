#include <stdio.h>
using namespace std;

int print_key(int tests = 0, float avg = 0) {
  printf("Key:\n\tPB: push back(s)\n\tms: milliseconds\n");
  printf("\nCommands:\n\tType \"exit\" in any input to exit.\n\n\n");
  printf("Average PB/s (%i tests): %g\n\n", tests, avg);
  return 0;
}