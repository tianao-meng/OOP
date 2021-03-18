#include <iostream>
#include <string>
#include "echo.h"
using namespace std;

Echo::Echo(): source(0) {}

void Echo::setSource(istream *in) {
    //cout << "in" << endl;
    //cout << in << endl;
    source = in;
    //cout << source << endl;
}

string Echo::getWord() {

    string s;

    //cout << source << endl;
    *source >> s;

    return s;
}

