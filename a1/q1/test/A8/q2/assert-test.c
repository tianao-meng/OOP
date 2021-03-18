#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aos.h"

// this helper may help you

// print_aos(aos, len) prints the array of strings aos
// effects: produces output
void print_aos(char **aos, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d: %s\n", i, aos[i]);
  }
}


int main(void) {
  char s[] = "star wars: the rise of skywalker";
  int num_words = 0;
  char **aos = split(s, &num_words);
  assert(num_words == 6);
  assert(!strcmp(aos[0], "star"));
  assert(!strcmp(aos[5], "skywalker"));
  merge_sort(aos, num_words);
  assert(!strcmp(aos[3], "star"));
  assert(!strcmp(aos[2], "skywalker"));
  free(aos);
}
