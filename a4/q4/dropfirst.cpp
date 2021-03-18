//
// Created by 孟天奥 on 2020-10-12.
//
#include "dropfirst.h"
#include "echo.h"

using namespace std;


Dropfirst :: Dropfirst(TextProcessor * component, int n): Decorator(component), n(n) {}

std::string Dropfirst :: getWord(){

    string s;
//    *source >> s;
    TextProcessor * component = get_component();

    s = component -> getWord();
    string::size_type l = s.length();
    if (l <= n){
        string output = "";
        return output;
    } else {

        string output = s.substr(n);
        return output;

    }


}

void Dropfirst :: setSource(std::istream *in){

    TextProcessor * component = get_component();
    component -> setSource(in);
}

