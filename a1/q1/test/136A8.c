// slurp() reads in all input until EOF and returns a new string
//   with the contents (or NULL if EOF is encountered immediately)
// effects: may allocate memory (caller must free)
//          read inputs
// time:    O(n) [amortized]

char *slurp(void){
    char * ans = (char *)malloc(
}

// this is a module that deals with arrays of strings

// all string parameters must be valid strings

// a "word" is simply a sequence of non-whitespace characters
// and may includes characters that are not letters


// split(s, num_strings) returns an array of strings, corresponding
//   to the words in s in the order that they appear in s.
// notes: modifies s by replacing all whitespace chars with '\0'
//        each string in the array "points" to an address within s
//        *num_strings is modified to contain the length
//        returns NULL if s is empty or only contains whitespace
// effects: modifies s, *num_strings
//          allocates memory for the array (not for each string)
//          client must free the returned value
// time:    O(n), n is the length of s
char **split(char *s, int *num_strings);


// merge_sort(aos, len) sorts the array of strings aos in
//   lexicographical order
// effects: modifies a
// time:    O(m*n*logn), n is len, m is len of largest string
void merge_sort(char **aos, int len);


// word_freq(s) prints all of the unique words is s along with the
//   number of times each word occurs using "%s [%d]\n"
// notes: words are printed in descending order of the number of times
//          they occur (ties broken by lexicographical order)
//        prints nothing if s is empty or only contains whitespace
// time:  O(???) n is the number of words, m is len of largest word
//        [at most m*n^2 -- justify your time in  in your aos.c]
void word_freq(const char *s);


#include <stdbool.h>

// the symbol_table ADT assigns int IDs to strings, so they can
// be referenced as an integers instead of by strings

// To facilitate CS136 testing:
//   * INVALID_SYMBOL should be defined as -1
//   * valid symbols should be assigned the IDs 1, 2, 3, etc. (in order)
//   * so all IDs from 1 ... symbol_count() should be valid symbol IDs

// all symbol table parameters must be valid symbol tables

// for times, n is the string length, m is symbol_count()

struct symbol_table;

// is_valid_symbol_string(s) determines if the string in s is a valid
//   symbol according to the following naming rules:
//   * length is at least one
//   * only contain letters, underscores and numbers
//   * starts with a letter
// time: O(n)
bool is_valid_symbol(const char *s);

// symbol_table_create() creates an empty symbol table
// effects: allocates memory (must call symbol_table_destroy)
struct symbol_table *symbol_table_create(void);

// symbol_table_destroy(st) destroys the symbol table st
// effects: st is no longer valid
// time:    O(m)
void symbol_table_destroy(struct symbol_table *st);

// the constant INVALID_SYMBOL is returned by symbol_lookup & symbol_read when:
// * the string (parameter or from input) is not a valid symbol
// * the end of the input (e.g., EOF) is encountered in symbol_read
extern const int INVALID_SYMBOL;

// symbol_count(st) returns the number of symbol IDs that have been
//   generated
int symbol_count(const struct symbol_table *st);

// symbol_read(st) returns the ID for the next symbol from input
//   (which may be a new or existing ID) or INVALID_SYMBOL
// effects: reads from input
//          modifies st (if returns a "new" symbol)
// time:    O(n*m)
int symbol_read(struct symbol_table *st);

// symbol_lookup(st, symbol_string) returns the ID for symbol_string
//   (which may be a new or existing ID) or INVALID_SYMBOL
// effects: modifies st (if returns a "new" symbol)
// time:    O(n*m)
int symbol_lookup(struct symbol_table *st, const char *symbol_string);

// symbol_pri

// symbol_print(st, symbol_id) prints the symbol corresponding to symbol_id
//   using "%s" (no newline)
// requires: symbol_id is a valid ID: 0 < symbol_id <= symbol_count()
// effects: displays a message
// time:    O(n)
void symbol_print(const struct symbol_table *st, int symbol_id);

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

// A module for an int sequence ADT

struct sequence;

// NOTE: All of the following functions REQUIRE:
//       pointers to a sequence (e.g., seq) are valid (not NULL)

// sequence_create() returns a pointer to a new (empty) sequence
// effects: allocates memory (caller must call sequence_destroy)
// time: O(1)
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
// requires: and 0 <= pos <= sequence_length(seq)
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

// sequence_print(seq) prints out the items in seq
//   using the format: "[item_0,item_1,...,item_last]\n"
//   or "[empty]\n"
// effects: prints out a message
// time:    O(n)
void sequence_print(const struct sequence *seq);
