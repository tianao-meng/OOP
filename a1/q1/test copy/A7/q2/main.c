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
#include <stdlib.h>
#include <string.h>

// mirror_mirror(s) returns a *new* string that contains
//   contents of s, followed by the contents of s reversed
// requires: s is not NULL
// effects:  allocates memory (caller must free)
// time:     O(n)
char *mirror_mirror(const char *s) {
  return NULL;
}

int main(void) {
  char *s = mirror_mirror("The Mandalorian");
  assert(!strcmp(s, "The MandaloriannairoladnaM ehT"));
  free(s);
}
