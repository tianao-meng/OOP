#include <assert.h>
#include <string.h>
#include "user.h"

int main(void) {
  char name[] = "harpo";
  char word[] = "Sw0rdFi$h";
  
  assert(is_valid_username(name));
  assert(is_valid_password(word));
  
  struct user *u = user_create(name, word);
  assert(u);
  
  assert(!strcmp(name, get_username(u)));
  assert(is_correct_password(u, word));

  user_destroy(u);
}
