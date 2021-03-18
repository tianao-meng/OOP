// A module for working with phonetic alphabets

// SEASHELL_READONLY

// speak_io(s) displays the string s using
//   the phonetic alphabet (as described in the assignment)
// requires: alphabet[0] is not NULL
// effects:  displays a message
// time:     O(???)
void speak_io(const char *s, const char *alphabet[]);

// speak_str(s) returns a new string that contains
//   s using the phonetic alphabet
// requires: alphabet[0] is not NULL
// effects:  allocates memory (client must free)
// time:     O(???)
char *speak_str(const char *s, const char *alphabet[]);
