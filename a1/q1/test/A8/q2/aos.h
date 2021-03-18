
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
