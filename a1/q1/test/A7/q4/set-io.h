/*

INPUT FORMAT:

SET: letter from a..z  (you have 26 sets available, from a..z)
INT: integer
LEN: positive integer


empty SET                    SET = empty_set()
single SET INT               SET = singleton(INT)
create SET LEN INT1 INT2 ... SET = set_from_array(a, LEN)
card SET                     display cardinality(set)
eq SETx SETy                 display set_equal(SETx, SETy)
union SET SETx SETy          SET = set_union(SETx, SETy)
intersect SET SETx SETy      SET = set_intersect(SETx, SETy)
diff SET SETx SETy           SET = set_diff(SETx, SETy)
print SET                    call set_print(SET)
destroy SET                  call set_destroy(SET)
quit                         exit and call set_destroy(SETa ... SETz)

*/


// set_io_test() is an interactive I/O client for the set module
// effects: reads input
//          displays output
//          terminates program if there is invalid input
void set_io_test(void);
