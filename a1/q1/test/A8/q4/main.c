#include <assert.h>
#include "llfun.h"

// a simple test client for llfun.c

int sqr(int n) {
  return n*n;
}

bool is_even(int n) {
  return n % 2 == 0;
}

int main(void) {
  int a[6] = {4, 8, 15, 16, 23, 42};
  struct llist *lst = array_to_llist(a, 6);
  print_list(lst);
  // [4->8->15->16->23->42]
  int *b = llist_to_array(lst);
  for (int i = 0; i < 6; ++i) {
    assert(b[i] == a[i]);
  }
  free(b);
  map(sqr,lst);
  print_list(lst);
  // [16->64->225->256->529->1764]
  filter(is_even,lst);
  print_list(lst);
  // [16->64->256->1764]
  list_destroy(lst);
}
