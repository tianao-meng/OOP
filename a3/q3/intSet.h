//
// Created by 孟天奥 on 2020-09-16.
//

#ifndef _INTSET_H_
#define _INTSET_H_
#include <iostream>
struct intSet {
    int *data;
    int size;
    int capacity;

    intSet();
    intSet(const intSet& is);
    //void copy(const intSet& is);
    ~intSet();
    intSet(intSet &&is);
    intSet &operator=(const intSet& is);
    intSet &operator=(intSet &&is);
    void swap(intSet &is);
    intSet operator|(const intSet &other); // Set union
    intSet operator&(const intSet &other); // Set intersection.
    bool operator==(const intSet &other);  // Set equality.
    bool isSubset(intSet s);  // True if s is a subset of *this
    bool contains(int e);     // True if *this contains e
    void add(int e);          // Adds int e to this set.
    void remove(int e);       // Removes int e ot this set.
};
void swap_1 (int & ele_1, int & ele_2);
void bubble_sort(int * arr, int size);
bool check_if_in(int * arr, int size, int ele);
std::ostream& operator<<(std::ostream& out, const intSet& is);

#endif
