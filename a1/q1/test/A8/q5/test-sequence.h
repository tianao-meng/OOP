/*
 This is simple I/O test module for sequence that
 uses a very specific input format.

 Failure to follow format might lead to undefined behaviour.

 l: print sequence_length as "length: %d\n"
 a INT: print sequence_item_at as "item_at(%d): %d\n"
 i INT1 INT2: calls sequence_insert_at(..., INT1, INT2)
 r INT: calls sequence_remove_at(..., INT)
 p: calls sequence_print
 q: quit
*/


// test_sequence() implements the above I/O test client for sequence
// effects: reads input
//          produces output
//          may exit() if there is invalid input
void test_sequence(void);
