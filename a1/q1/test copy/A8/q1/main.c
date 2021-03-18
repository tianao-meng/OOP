#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my-slurp.h"

int main(void) {
  char *s = slurp();
  if (s) {
    printf("%zd\n", strlen(s));  
    printf("%s", s);
    free(s);    
  } else {
    printf("0\n");
  }
  // after a slurp() there should be nothing else to get
  assert(slurp() == NULL);
}
