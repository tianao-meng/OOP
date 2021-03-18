#include <iostream>
#include <string>
#include "intSet.h"
#include "sets.h"
using namespace std;

int main() {

    char s;
    int e;
    int f;
    Sets sets;

    while (cin >> s) {
        //cout << s << endl;
        if (s ==  'n') {
            intSet set;

            while(true){
                cin >> e;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    break;
                }

                set . add(e);
            }
            //cout << "in" << endl;
            sets.add(set);
            //cout << "in" << endl;
            //cout << set.size << endl;
            //continue;
        }

        else if (s == 'd') {

            cin >> e;
            intSet  set;
            set =  sets.data[e];
            sets.add(set);

        }

        else if (s == 'p') {
            cin >> e;
            //cout << "in" << endl;
            cout << sets.data[e] << endl;

        }

        else if (s == '&') {
            cin >> e;
            cin >> f;
            intSet res = sets.data[e] & sets.data[f];
            cout << res << endl;

        }

        else if (s == '|') {
            cin >> e;
            cin >> f;
            intSet res = sets.data[e] | sets.data[f];
            cout << res << endl;

        }

        else if (s == '=') {
            cin >> e;
            cin >> f;
            if (sets.data[e] == sets.data[f]){
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }

        else if (s == 's') {
            cin >> e;
            cin >> f;
            if (sets.data[e].isSubset(sets.data[f])){
                cout << 1 << endl;
            } else{
                cout << 0 << endl;
            }
        }

        else if (s == 'c') {
            cin >> e;
            cin >> f;
            if (sets.data[e].contains(f)){
                cout << 1 << endl;
            } else{
                cout << 0 << endl;
            }
        }

        else if (s == 'a') {
            cin >> e;
            cin >> f;
            sets.data[e].add(f);
        }

        else if (s == 'r') {
            cin >> e;
            cin >> f;
            sets.data[e].remove(f);
        }

        else if (s == '<') {

            cin >> e;
            cin >> f;
            sets.data[e] = sets.data[f];

        }

        else if (s == 'm') {

            intSet temp;
            cin >> e;
            while(1){

                cin >> f;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    break;
                }

                temp.add(f);
            }
            sets.data[e] = move(temp);

        }



        else if (s == 'q') { // Quit
            break;
        }

//        else {
//            continue;
//        }
    }
    //cout << "i am here" << endl;


}
