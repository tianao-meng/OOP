#include <stdio.h>
#include <stdlib.h>
#include "phonetic.h"
#include "speak.h"
#include "slurp.h"

// a simple test client for speak_str

int main(void) {
  char s[10001];
  slurp(s, 10000);
  char *speak = speak_str(s, phonetic);
  printf("%s\n", speak);
  free(speak);
}
