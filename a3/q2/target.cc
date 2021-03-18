//
// Created by 孟天奥 on 2020-09-12.
//

#include "target.h"
#include <string>
#include <utility>
using namespace std;

bool Target::isLeaf() const {

    return leaf != 0;
}

void Target::addDepend(Target *d) {

    int count = 0;

    for (int i = 0; i < maxDepends; i++){

        if (depend[i] ==  d){
            break;
        }

        if (depend[i] != nullptr){

            count ++;
            continue;
        } else {
            depend[i] = d;
            break;
        }

    }
//    if (count == maxDepends){
//        out << "Max dependencies exceeded" << endl;
//    }
}


void Target::addFirstDepend(Target *d) {

    int count = 0;

    for (int i = 0; i < maxDepends; i++){

        if (first_depend[i] ==  d){
            break;
        }

        if (first_depend[i] != nullptr){

            count ++;
            continue;
        } else {
            first_depend[i] = d;
            break;
        }

    }
    if (count == maxDepends){
        out << "Max dependencies exceeded" << endl;
    }
}

void Target::addParent(Target *d) {
    //cout << "in" << endl;

    for (int i = 0; i < (maxDepends - 1); i++){

        if (parent[i] ==  d){
            break;
        }

        if (parent[i] != nullptr){
            continue;
        } else {
            parent[i] = d;
            break;
        }

    }

}

void Target:: copy( const Target &rhs ) {

    name = rhs.name;
    leaf = rhs.leaf;
    time_update = rhs.time_update;
    for (unsigned int i = 0; i < maxDepends; i += 1){
        depend[i] = rhs.depend[i];
    }

    for (unsigned int i = 0; i < maxDepends; i += 1){
        parent[i] = rhs.parent[i];
    }

    for (unsigned int i = 0; i < maxDepends; i += 1){
        first_depend[i] = rhs.first_depend[i];
    }

}

//copy constructor
Target::Target( const Target &rhs, std::ostream &out) : out(out){

    copy( rhs );
}


//assignment operator
Target& Target:: operator=( const Target &rhs ) {
    copy( rhs );
    return *this;
}

bool Target :: operator==( Target * c ) {
    if (name == c -> name){
        return true;
    }
    return false;
}



Target::Target(const string name, ostream &out) : out(out), name(name) {

    time_update = 0;

    for (int i = 0; i < maxDepends; i++){
//        cout << maxDepends << endl;
//        cout << i << endl;
//        cout << "in" << endl;
        //depend[i] = new Target(name, std::cout);
        depend[i] = nullptr;
    }

    for (int i = 0; i < maxDepends; i++){

        //parent[i] = new Target(name, std::cout);
        parent[i] = nullptr;
    }

    for (int i = 0; i < maxDepends; i++){

        //parent[i] = new Target(name, std::cout);
        first_depend[i] = nullptr;
    }

    //cout << "in" << endl;

}

Target::~Target() {

    for (int i = 0; i < maxDepends; i++){
        delete depend[i];
    }

    for (int i = 0; i < maxDepends; i++){
        delete parent[i];
    }

    for (int i = 0; i < maxDepends; i++){
        delete first_depend[i];
    }
    delete parent[maxDepends];
    delete depend[maxDepends];
    delete first_depend[maxDepends];

}

void Target::update(int time) {
    time_update = time;
}

int Target::lastUpdated() const {
    return time_update;
}

void Target::build() {
    out << "Building " << name << endl;
    //time_update = time;
}