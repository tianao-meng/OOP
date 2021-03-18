#include <assert.h>
#include "stack.h"

// very simple test client for stack ADT

int main(void) {
  struct stack *s = stack_create();
  stack_push(s, 42);
  assert(stack_top(s) == 42);
  assert(stack_pop(s) == 42);
  assert(stack_is_empty(s));         
  stack_destroy(s);
}
