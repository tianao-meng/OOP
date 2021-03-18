#include <assert.h>
#include "queue.h"

// very simple test client for queue ADT

int main(void) {
  struct queue *q = queue_create();
  queue_add_back(q, 42);
  assert(queue_front(q) == 42);
  assert(queue_remove_front(q) == 42);
  assert(queue_is_empty(q));
  queue_destroy(q);
}
