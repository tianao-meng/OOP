#include "set.h"
#include <assert.h>
#include <stdlib.h>

int main(void) {
  
  struct set *set_a = empty_set();
  int b[4] = {3, 2, 1, 3};
  struct set *set_b = set_from_array(b, 4);
  struct set *set_c = singleton(2);
  
  set_print(set_a);
  set_print(set_b);
  set_print(set_c);
  /*
  [empty]
  {1,2,3}
  {2}
  */  
  
  struct set *set_d = set_union(set_a, set_b);
  struct set *set_e = set_intersect(set_b, set_c);
  struct set *set_f = set_diff(set_c, set_b);
  
  assert(cardinality(set_b) == 3);  
  assert(set_member(set_c, 2));
  assert(set_equal(set_d, set_b));
  assert(set_equal(set_e, set_c));
  assert(set_equal(set_f, set_a));
  
  int *z = set_to_array(set_c);
  assert(z[0] == 2);

  set_destroy(set_a);
  set_destroy(set_b);
  set_destroy(set_c);
  set_destroy(set_d);
  set_destroy(set_e);
  set_destroy(set_f);
  free(z);
}
