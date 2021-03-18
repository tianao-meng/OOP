#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    string line;
    string to_print;
    int layer = 0;
    for(;;){
        getline(cin, line);
        stringstream ss;
        string word;
        ss.str(line);
        int now_pos = 0;
        string::size_type length = line.length();
        //cout << length << endl;
        int len = 0;
        if (length == 0){
            //cout << "in" ;

            if (cin.fail()) {
                if (cin.eof()){
                    cout << "";
                    break;
                } else{
                    cout << "unexpected input" << endl;
                }
            }
            cout << "" << endl;

        }
        //cout << len << endl;
        while (ss >> word){
            //cout << len << endl;
            //cout << length_line << endl;

            if (word == ";"){

                cout << word << endl;
                now_pos = 0;
                len += 1;
                continue;
            }

            if (word == "{"){
                layer += 1;
                //cout << " " << "{" << endl;
                cout << "{" << endl;
                now_pos = 0;
                len += 1;
                continue;

            }

            if (word == "}"){

                if (now_pos != 0){
                    cout << endl;
                }
                layer -= 1;
                if (now_pos == 0){
                    for (int i = 0 ; i < layer; i++){
                        cout << " ";

                    }
                }

                cout << word << endl;
                len += 1;
                now_pos = 0;

                continue;
            }

            if (word == "//"){
                if (now_pos == 0){
                    for (int i = 0 ; i < layer; i++){
                        cout << " ";

                    }
                }

                string::size_type index = line.find( "//" );
                string to_print = line.substr(index,(length - index));
                cout << to_print << endl;
                now_pos = 0;
                break;
            }

            if (now_pos == 0){
                for (int i = 0 ; i < layer; i++){
                    cout << " ";
                    now_pos += 1;
                }
            }
            string::size_type length_word = word.length();
            if ((len + length_word) == length){

                if (cin.fail()) {
                    if (cin.eof()){
                        cout << word;
                        break;
                    } else{
                        cout << "unexpected input" << endl;
                    }
                }

                cout << word << endl;
                break;
            }
            cout << word << " ";


            len += length_word;
            len += 1;

            now_pos += 2;


        }



        if (cin.fail()) {
            if (cin.eof()){
                break;
            } else{
                cout << "unexpected input" << endl;
            }
        }


    }




    return 0;
}
