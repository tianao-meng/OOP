#include <stdbool.h>

// A module for an int[eger] set ADT

struct set;

// NOTE: All of the following functions REQUIRE:
//       pointers to a set (e.g., s) are valid sets (not NULL)

// empty_set() creates an empty set
// effects:  allocates memory for the new set (caller must call set_destroy)
// time:     O(1)
struct set *empty_set(void);

// singleton() creates a singleton set that contains just i
// effects:  allocates memory for the new set (caller must call set_destroy)
// time:     O(1)
struct set *singleton(int i);

// set_from_array(a, len) returns a new set that contains the elements of a
//   note: the cardinality will be <= len, as a may contain duplicates
// requires: len > 0
// effects:  allocates memory for the new set (caller must call set_destroy)
// time:     O(n*logn)
struct set *set_from_array(const int a[], int len);

// cardinality(s) returns the number of elements in s
// time: O(1)
int cardinality(const struct set *s);

// set_member(s, i) determines if i is in set s
// time: O(logn)
bool set_member(const struct set *s, int i);

// set_equal(s1, s2) determines if s1 is identical to s2
// time: O(n) where n is min(cardinality(s1),cardinality(s2))
bool set_equal(const struct set *s1, const struct set *s2); 

// set_union(s1, s2) returns a new set that is the union of s1 and s2
// effects: allocates memory for the new set (caller must call set_destroy)
// time:    O(n) where n is cardinality(s1) + cardinality(s2)
struct set *set_union(const struct set *s1, const struct set *s2);

// set_intersect(s1, s2) returns a new set that is the intersection of s1 and s2
// effects: allocates memory for the new set (caller must call set_destroy)
// time:    O(n) where n is cardinality(s1) + cardinality(s2)
struct set *set_intersect(const struct set *s1, const struct set *s2);

// set_diff(s1, s2) returns a new set that contains all elements in s1
//   that do not appear in s2
// effects: allocates memory for the new set (caller must call set_destroy)
// time:    O(n) where n is cardinality(s1) + cardinality(s2)
struct set *set_diff(const struct set *s1, const struct set *s2);

// set_print(s) prints the elements of set s to the screen in ascending order.
//   using the format: "{e_smallest,e_next,...,e_largest}\n"
//   or "[empty]\n"
// effects: displays out a message
// time:    O(n)
void set_print(const struct set *s);

// set_to_array(s) returns a new array that is the elements of s
//   in ascending order, or NULL if s is empty
// effects: may allocate memory for a new array (caller must call free)
// time:    O(n)
int *set_to_array(const struct set *s);

// set_destroy(s) frees all dynamically allocated memory for s
// effects: the memory at s is invalid (freed)
// time:    O(1)
void set_destroy(struct set *s);

