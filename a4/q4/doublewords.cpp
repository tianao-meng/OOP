//
// Created by 孟天奥 on 2020-10-12.
//

#include "doublewords.h"
#include "echo.h"
#include <sstream>

using namespace std;


DoubleWords :: DoubleWords(TextProcessor * component): Decorator(component) {}

std::string DoubleWords :: getWord(){

    string s;
//    *source >> s;
    TextProcessor * component = get_component();

    string output;
    ss.exceptions(ios::failbit);

    try {
        ss >> output;
        //cout << output << endl;
        return output;
    } catch (ios::failure) {

        s = component -> getWord();
        s = s + '\n' + s;
        ss.clear();
        ss.str(s);
        ss >> output;
        //cout << output << endl;

        return output;
    }
    //string output = s + "\n" + s;
    //return output;

}

void DoubleWords :: setSource(std::istream *in){
    TextProcessor * component = get_component();
    component -> setSource(in);
}
