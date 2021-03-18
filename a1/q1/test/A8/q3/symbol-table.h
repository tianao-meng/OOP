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

// symbol_print(st, symbol_id) prints the symbol corresponding to symbol_id
//   using "%s" (no newline)
// requires: symbol_id is a valid ID: 0 < symbol_id <= symbol_count()
// effects: displays a message
// time:    O(n)
void symbol_print(const struct symbol_table *st, int symbol_id);
