
// slurp() reads in all input until EOF and returns a new string 
//   with the contents (or NULL if EOF is encountered immediately)
// effects: may allocate memory (caller must free)
//          read inputs
// time:    O(n) [amortized]

char *slurp(void);
