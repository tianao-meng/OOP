#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "aos.h"
#include "slurp.h"

// This I/O test only tests word_freq

int main(void) {
  char *s = slurp();
  if (s) {
    word_freq(s);
    free(s);
  }
}
