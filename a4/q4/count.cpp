//
// Created by 孟天奥 on 2020-10-12.
//

#include "count.h"
#include "echo.h"

using namespace std;


Count :: Count(TextProcessor * component, char c): Decorator(component), c(c) {}

std::string Count :: getWord(){

    string s;

//    *source >> s;
    TextProcessor * component = get_component();

    s = component -> getWord();

    string::size_type l = s.length();

    for (int i = 0; i < l; i++){

        if (s[i] == c){
            n ++;
            s[i] = (n - 0) + '0';
        } else {
            continue;
        }

    }

    return s;


}
void Count :: setSource(std::istream *in){
    TextProcessor * component = get_component();
    component -> setSource(in);

}