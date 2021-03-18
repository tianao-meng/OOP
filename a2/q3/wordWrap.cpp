#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char * argv[]) {

    stringstream ss;
    stringstream ss2;
    string to_print;
    string buffer;
    int word_width;

    if (argc == 1){

        word_width = 25;

    } else{
        ss << argv[1];
        ss >> word_width;
    }
    int now_length = 0;
    while (true){
        cin >> buffer；
        L1:if (cin.fail()) {
            if (cin.eof()){
                break;
            } else{
                cout << "unexpected input" << endl;
            }
        }
        string::size_type  l_word = buffer.length();
        if (now_length == 0 && l_word > word_width){

            string split = buffer.substr(0,word_width);
            cout << split << endl;
            buffer = buffer.substr(word_width,(l_word - word_width));
            now_length = 0;
            goto L1;

        }
        if (now_length == 0){
            to_print = buffer;
            now_length += l_word;

            continue;
        }
        now_length += l_word;
        if (now_length < word_width) {
            to_print +=  ' ' + buffer;
            now_length += 1;

            continue;
        }

        now_length = 0;
        cout << to_print << endl;
        to_print = "";
        goto L1;

    }
    cout << to_print << endl;



    return 0;

}
