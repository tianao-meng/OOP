//
// Created by 孟天奥 on 2020-09-16.
//

#ifndef Q3_SETS_H
#define Q3_SETS_H

#include "intSet.h"

struct Sets {

    int size;
    int capacity;
    intSet * data;
    Sets();
    ~Sets();
    void add(intSet  e);
};

#endif