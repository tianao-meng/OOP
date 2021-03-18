#include <assert.h>
#include "sequence.h"

// this is a very simple test for your sequence module

int main(void) {
  struct sequence *seq = sequence_create();
  sequence_print_reverse(seq); /* [empty] */  
  sequence_insert_at(seq, 0, 100);
  assert(sequence_item_at(seq, 0) == 100);
  sequence_insert_at(seq, 1, 200);
  sequence_insert_at(seq, 2, 300);
  assert(sequence_remove_front(seq) == 100);
  sequence_insert_front(seq, 100);
  assert(sequence_remove_back(seq) == 300);
  sequence_insert_back(seq, 300);
  assert(sequence_remove_at(seq, 1) == 200);
  assert(sequence_length(seq) == 2);
  sequence_print(seq); /* [100,300] */
  sequence_destroy(seq);
}