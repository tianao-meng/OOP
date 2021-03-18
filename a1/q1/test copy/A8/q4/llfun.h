#include <stdlib.h>
#include <stdbool.h>

struct llnode {
  int item;
  struct llnode *next;
};

struct llist {
  struct llnode *front;
};

// print_list(lst) pretty prints lst
//   using the format: "[first->second->...->last]\n"
//   or "[empty]\n"
// effects: prints out a message
// time : O(n)
void print_list(const struct llist *lst);

// array_to_list(a, len) generates a new linked list from array a
//   the first item of the list is a[0]... and the last is a[len-1]
// requires: len > 0
// effects: allocates memory (caller must call list_destroy)
// time: O(n)
struct llist *array_to_llist(const int a[], int len);

// list_to_array(lst) generates a new array from lst
//   a[0] is the first item of the list, etc.
//   returns NULL if lst is empty
// effects: allocates memory (caller must free)
// time: O(n)
int *llist_to_array(const struct llist *lst);

// map(f, lst) modifies each item of lst to be f(item)
// effects: modifies lst
void map(int (*f)(int), struct llist *lst);

// filter(f, lst) removes each item of lst where f(item) is false
// effects: modifies lst
void filter(bool (*f)(int), struct llist *lst);


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// provided from the notes for your convenience

// list_create() creates a new (empty) linked list
// effects: allocates memory (caller must call list_destroy)
// time: O(1)
struct llist *list_create(void);

// add_front(i, lst) adds i to the front of lst
// effects: modifies lst
// time: O(1)
void add_front(int i, struct llist *lst);

// length(lst) determines the length of lst
// time: O(n)
int length(const struct llist *lst);

// list_destroy(lst) frees all of the memory allocated in lst
// effects: lst is no longer valid
// time: O(n)
void list_destroy(struct llist *lst);
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

