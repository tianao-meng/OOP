//
// Created by 孟天奥 on 2020-09-12.
//

#ifndef _TARGET_H_
#define _TARGET_H_
#include <iostream>
#include <string>

const int maxDepends = 10;

struct Target {  // You may add fields and methods as you see fit
    std::ostream &out;  // Stream where Target will print its output
    std::string name;
    Target * depend[maxDepends];
    Target * parent[maxDepends];
    Target * first_depend[maxDepends];

    int time_update = 0;
    int leaf = 1;
    Target(std::string name, std::ostream &out = std::cout);
    ~Target();
    Target( const Target &rhs, std::ostream &out = std::cout );
    void copy( const Target &rhs);
    Target &operator=( const Target &rhs );
    bool  operator==( Target * c );
    bool isLeaf() const;
    void addDepend(Target *d);
    void addFirstDepend(Target *d);
    void addParent(Target *d);
    void update(int time);
    int lastUpdated() const;
    void build();
};

#endif
