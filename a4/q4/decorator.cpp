//
// Created by 孟天奥 on 2020-10-12.
//
#include "decorator.h"
#include <iostream>
using namespace std;
Decorator :: Decorator(TextProcessor * component): component (component){}
TextProcessor * Decorator :: get_component(){
    return component;
}


void Decorator :: setSource(std::istream *in){
    component -> setSource(in);
}

Decorator :: ~Decorator(){
    //cout << "in destructor" << endl;
    delete component;
};