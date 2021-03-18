//
// Created by 孟天奥 on 2020-10-12.
//

#include "allcaps.h"
#include "echo.h"

using namespace std;


Allcaps :: Allcaps(TextProcessor * component): Decorator(component){}

std::string Allcaps :: getWord(){

    string s;
//    *source >> s;
    TextProcessor * component = get_component();
    s = component -> getWord();
    string::size_type l = s.length();

    for (int i = 0; i < l; i++){

        if ((s[i] >= 'a') && (s[i] <= 'z')){
            s[i] = (s[i] - 'a') + 'A';
        } else {
            continue;
        }

    }

    return s;

}

void Allcaps :: setSource(std::istream *in){
    TextProcessor * component = get_component();
    component -> setSource(in);
}