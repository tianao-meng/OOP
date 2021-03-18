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

#include <stdlib.h>
#include "dictionary.h"

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// IMPORTANT! You cannot modify these structures or constants:

struct bstnode {
  void *item;                // key
  void *value;               // additional value (augmentation)
  struct bstnode *left;
  struct bstnode *right;
  int size;                  // *** new augmentation (see notes)
};

struct dictionary {
  struct bstnode *root;
  // function pointers
  DictKeyCompare key_compare;
  FreeFunction free_key;
  FreeFunction free_val;
  PrintKeyVal print_keyval;  
};

const int PREORDER = -1;
const int INORDER = 0;
const int POSTORDER = 1;

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

Dictionary dict_create(DictKeyCompare cmp_function,
                       FreeFunction free_key_function,
                       FreeFunction free_val_function,
                       PrintKeyVal print_function) {
  return NULL;
}


void dict_insert(void *key, void *val, Dictionary d) {
}


void *dict_lookup(void *key, Dictionary d) {
  return NULL;
}


void dict_remove(void *key, Dictionary d) {
}


void dict_print(int order, Dictionary d) {
}


void *dict_select(int k, Dictionary d) {
  return NULL;
}


int dict_size(Dictionary d) {
  return 0;
}


void dict_destroy(Dictionary d) {
}
