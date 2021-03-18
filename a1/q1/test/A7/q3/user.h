#include <stdbool.h>
#include <stdlib.h>

// a USER ADT that simply stores a username and password

struct user;

// is_valid_username(username) determines if username only contains
//   lower case letters and has a length of at least 3
// time: O(n)
bool is_valid_username(const char *username);

// is_valid_password(password) determines if password contains only printable
//   ascii characters with no whitespace and has a length of at least 6
// time: O(n)
bool is_valid_password(const char *password);

// user_create(username, password) creates a new user with the given
//   username and password. If username/password are invalid, returns NULL
// note:    makes an internal "copy" of username and password
// effects: may allocate memory (client must call user_destroy if non-NULL)
// time:    O(n + m), where n,m are the length of username,password
struct user *user_create(const char *username, const char *password);

// get_username(user) returns the username from u
// requires: u is a valid user created by user_create;
const char *get_username(const struct user *u);

// is_correct_password(u, password) determines if the password for u
//   is identical
// requires: u is a valid user created by user_create;
// time:     O(n)
bool is_correct_password(const struct user *u, const char *password);

// user_destroy(u) destroys u and frees all memory for u
// requires: u is a valid user created by user_create;
// effects:  frees memory for u
void user_destroy(struct user *u);
