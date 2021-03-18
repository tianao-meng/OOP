// A module for an int sequence ADT

struct sequence;

// NOTE: All of the following functions REQUIRE:
//       pointers to a sequence (e.g., seq) are valid (not NULL)

// sequence_create() returns a pointer to a new (empty) sequence
// effects: allocates memory (caller must call sequence_destroy)
// time:    O(1)
struct sequence *sequence_create(void);

// sequence_destroy(seq) frees all dynamically allocated memory 
// effects: the memory at seq is invalid (freed)
// time:    O(n)
void sequence_destroy(struct sequence *seq);

// sequence_length(seq) returns the number of items in seq
// time: O(1)
int sequence_length(const struct sequence *seq);

// sequence_item_at(seq, pos) returns the item in seq at the given pos
// requires: 0 <= pos < sequence_length(seq)
// time:     O(n)
int sequence_item_at(const struct sequence *seq, int pos);

// sequence_insert_at(seq, pos, val) inserts a new item with value val
//   at position pos in seq
//   (changing the position of items at position >= pos)
// requires: 0 <= pos <= sequence_length(seq)
// effects:  modifies seq
// time:     O(n)
void sequence_insert_at(struct sequence *seq, int pos, int val);

// sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the removed value
//   (changing the position of items > pos)
// requires: 0 <= pos < sequence_length(seq)
// effects:  modifies seq
// time:     O(n)
int sequence_remove_at(struct sequence *seq, int pos);

// sequence_insert_front(seq, val) inserts val into front of seq
//   [equivalent to sequence_insert_at(seq, 0, val)]
// effects:  modifies seq
// time:     O(1)
void sequence_insert_front(struct sequence *seq, int val);

// sequence_remove_front(seq, pos) removes and returns the front of seq
//   and returns the removed value
//   [equivalent to sequence_remove_at(seq, 0)]
// requires: 0 < sequence_length(seq)
// effects:  modifies seq
// time:     O(1)
int sequence_remove_front(struct sequence *seq);

// sequence_insert_back(seq, val) inserts val at the end of seq
//   [equivalent to sequence_insert_at(seq, sequence_length(seq), val)]
// effects:  modifies seq
// time:     O(1)
void sequence_insert_back(struct sequence *seq, int val);

// sequence_remove_back(seq, pos) removes the last item in seq
//   and returns the removed value
//   [equivalent to sequence_remove_at(seq, sequence_length(seq) - 1)]
// requires: 0 < sequence_length(seq)
// effects:  modifies seq
// time:     O(1)
int sequence_remove_back(struct sequence *seq);

// sequence_print(seq) prints out the items in seq
//   using the format: "[item_0,item_1,...,item_last]\n"
//   or "[empty]\n"
// effects: prints out a message
// time:    O(n)
void sequence_print(const struct sequence *seq);

// sequence_print_reverse(seq) prints out the items in seq
//   in reverse order
//   using the format: "[item_last,...,item_1,item_0]\n"
//   or "[empty]\n"
// effects: prints out a message
// time:    O(n)
void sequence_print_reverse(const struct sequence *seq);
