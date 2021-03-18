#include <stdio.h>
#include "slurp.h"

// SEASHELL_READONLY

void slurp(char *s, int maxlen) {
  int i = 0;
  while (i < maxlen) {
    if (scanf("%c", &s[i]) != 1) break;
    ++i;
  }
  s[i] = '\0';
}
