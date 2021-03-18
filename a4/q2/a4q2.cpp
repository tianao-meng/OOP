#include <iostream>
#include "Expression.h"
#include <sstream>
#include <vector>
using namespace std;

int main() {
    //cin.exceptions(ios::eofbit|ios::failbit);

    cin.exceptions(ios::eofbit|ios::failbit);

    stack container;
    vector <expression *> junk;
    vector <expression *> :: iterator it;
    string s;
    string buffer;
    //while (cin >> s)
    while (true) {
        try {
            cin >> s;
            //cout << "in" << endl;
            stringstream ss(s);
            ss.exceptions(ios::failbit);
            //ss.exceptions(ios::failbit);
            int num;

//        if (ss >> num){
//            //cout << num << endl;
//            integers * ele = new integers (num);
//            //cout << ele << endl;
//            container.push(ele);
//
//        }

            try {
                ss >> num;
                integers *ele = new integers(num);
                //cout << ele << endl;
                container.push(ele);
            } catch (iostream::failure &e) {

                if ((s == "ABS") || (s == "NEG")) {

                    expression *i = container.pop();
                    unary *ele = new unary(s, i);
                    container.push(ele);
                    junk.push_back(i);
                    //delete i;
                    continue;
                }

                if ((s == "+") || (s == "-") || (s == "*") || (s == "/")) {

                    expression *i = container.pop();
                    expression *j = container.pop();
                    binary *ele = new binary(s, i, j);
                    //expression * ele = new binary (s, i, j);
                    container.push(ele);
                    junk.push_back(i);
                    junk.push_back(j);
                    //cout << s << endl;
                    //delete i;
                    //delete j;

                    continue;
                }
            }


        } catch (iostream::failure &e) {
            break;
        }

    }
//    } catch (iostream::failure &e) {
//        break;
//    }







    if (container.size != 1){
        cerr << "invalid input" << endl;
    }

    if (container.size == 1){
        expression * i = container.pop();
        i->prettyprint();
        cout << "= " << i -> evaluate() .val << endl;
        junk.push_back(i);
        //delete i;
    }

    for (it = junk.begin(); it != junk.end(); it++){
        delete *it;
    }

    return 0;
}
