#include <stdbool.h>

// An int queue ADT

struct queue;

// all functions require valid queues

// queue_create() create an empty queue
// effects: allocates memory (caller must call queue_destroy)
// time:    O(1)
struct queue *queue_create(void);

// queue_destroy(q) destroys the queue q and frees all memory
// effects: q is no longer valid
// time:    O(n)
void queue_destroy(struct queue *q);

// queue_is_empty(q) determines if q is empty
// time: O(1)
bool queue_is_empty(const struct queue *q);

// queue_add_back(q, item) adds item to the back of q
// effects: modifies q
// time:    O(1)
void queue_add_back(struct queue *q, int item);

// queue_front(q) return the item at the front of q
// requires: q is not empty
// time:     O(1)
int queue_front(const struct queue *q);

// queue_remove_front(q) removes and returns the front of q
// requires: q is not empty
// effects:  modifies q
// time:     O(1)
int queue_remove_front(struct queue *q);

