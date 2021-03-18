/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS (v2)

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
//
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff, which you do not have to mention)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from and/or collaborated with:

// ERROR_NO_INTEGRITY_STATEMENT

// Name: ERROR_NO_NAME
// login ID: ERROR_NO_LOGIN
/////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "llfun.h"

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// provided from the notes for your convenience
struct llist *list_create(void) {
  struct llist *lst = malloc(sizeof(struct llist));
  lst->front = NULL;
  return lst;
}

void add_front(const int i, struct llist *lst) {
  assert(lst);
  struct llnode *node = malloc(sizeof(struct llnode));
  node->item = i;
  node->next = lst->front;
  lst->front = node;
}

int length(const struct llist *lst) {
  assert(lst);
  int length = 0;
  struct llnode *node = lst->front;
  while (node) {
    ++length;
    node = node->next;
  }
  return length;
}

void list_destroy(struct llist *lst) {
  assert(lst);
  struct llnode *curnode = lst->front;
  while (curnode) {
    struct llnode *nextnode = curnode->next;
    free(curnode);
    curnode = nextnode;
  }
  free(lst);
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void print_list(const struct llist *lst) {

}

struct llist *array_to_llist(const int a[], int len) {
  return NULL;
}

int *llist_to_array(const struct llist *lst) {
  return NULL;
}

void map(int (*f)(int), struct llist *lst) {
}

void filter(bool (*f)(int), struct llist *lst) {
}

