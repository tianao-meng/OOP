#include <stdbool.h>

// An int stack ADT

struct stack;

// all functions require valid stacks

// stack_create() create an empty stack
// effects: allocates memory (caller must call stack_destroy)
// time:    O(1)
struct stack *stack_create(void);

// stack_destroy(s) destroys the stack s and frees all memory
// effects: s is no longer valid
// time:    O(n)
void stack_destroy(struct stack *s);

// stack_is_empty(s) determines if s is empty
// time: O(1)
bool stack_is_empty(const struct stack *s);

// stack_push(s, item) pushes item on to the stack s
// effects: modifies s
// time:    O(1)
void stack_push(struct stack *s, int item);

// stack_top(s) return the top of the stack s
// requires: s is not empty
// time:     O(1)
int stack_top(const struct stack *s);

// stack_pop(s) removes and returns the top of stack s
// requires: s is not empty
// effects:  modifies s
// time:     O(1)
int stack_pop(struct stack *s);

