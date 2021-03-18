#include <assert.h>
#include <stdio.h>
#include "_symbol-table.h"

int main(void) {
  struct symbol_table *st = symbol_table_create();
  int first = symbol_lookup(st, "VeryFirstSymbol");
  assert(first == 1);
  assert(!is_valid_symbol("!invalid!"));
  assert(symbol_lookup(st, "!invalid!") == INVALID_SYMBOL);
  while (symbol_read(st) != INVALID_SYMBOL) {}
  int last = symbol_lookup(st, "VeryLastSymbol");
  assert(last == symbol_count(st));
  for (int i = 1; i <= last; ++i) {
    symbol_print(st, i);
    printf(" [%d]\n", i);
  }
  symbol_table_destroy(st);
}
