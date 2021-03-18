#include "set.h"
#include <assert.h>
#include <stdlib.h>

int main(void) {
  int arr1[] = {-46, -18, -1, 0, 25};
  int arr2[] = {-44, -2, 21, 36, 44};
  int arr3[] = {20, 23, 26, 28, 33};
  // int arr4[] = {-46,-44,-18,-2,-1,0,21,25,36,44}; // 1 and 2
  // int arr5[] = {-44,-2,20,21,23,26,28,33,36,44}; // 2 and 3

  struct set * set1 = set_from_array(arr1, 5);
  struct set * set2 = set_from_array(arr2, 5);
  struct set * set3 = set_from_array(arr3, 5);
  // struct set * set4 = set_from_array(arr4, 10);
  // struct set * set5 = set_from_array(arr5, 10);

  struct set * r1 = set_diff(set1, set2);
  struct set * r2 = set_diff(set2, set3);
  struct set * r3 = set_diff(set1, set3);

  assert(set_equal(r1, set1));
  assert(set_equal(r2, set2));
  assert(set_equal(r3, set1));

  assert(!set_equal(r1, set2));
  assert(!set_equal(r2, set3));

  set_destroy(set1);
  set_destroy(set2);
  set_destroy(set3);
  // set_destroy(set4);
  // set_destroy(set5);
  set_destroy(r1);
  set_destroy(r2);
  set_destroy(r3);
}
