#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
#include "textprocess.h"
#include "echo.h"
#include "count.h"
#include "decorator.h"
#include "doublewords.h"
#include "dropfirst.h"
#include "allcaps.h"


int main () {
    cin.exceptions(ios::failbit|ios::eofbit);
    string s;

    try {
        while(1) {

            getline(cin,s);

            istringstream iss{s};

            iss.exceptions(ios::failbit);
            string fname;
            iss >> fname;

            istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());

            in->exceptions(ios::failbit|ios::eofbit);

//            Echo echo = Echo();
//            TextProcessor *tp =  & echo;
            // must allocate heap memory;
            // delete chain
            TextProcessor *tp = new Echo();
            string dec;

            try {
                while (true) {

                    iss >> dec;
                    //cout << dec << endl;
                    if (dec == "dropfirst") {
                        int n;
                        iss >> n;
//                        Dropfirst dp = Dropfirst (tp, n);
//                        tp = &dp;
                        tp = new Dropfirst (tp, n);
                        // tp = ...
                    }
                    else if (dec == "doublewords") {
                        tp = new DoubleWords (tp);
//                        DoubleWords df = DoubleWords (tp);
//                        tp = &df;
                        // tp = ..
                    }
                    else if (dec == "allcaps") {
                        // tp = ...
//                        Allcaps dw = Allcaps (tp);
//                        tp = &dw;
                        tp = new Allcaps (tp);
                    }
                    else if (dec == "count") {
                        char c;
                        iss >> c;
//                        Count co = Count (tp, c);
//                        tp = &co;
                        tp = new Count(tp, c);
                        // tp = ...
                    }
                }
            }
            catch (ios::failure) {
                if (!iss.eof()){
                    cout << "wrong text process command" << endl;
                    break;
                }

            }

            tp->setSource(in);

            string word;

            try {
                int lineNum = 1;

                while (true) {

                    word = tp->getWord();
                    cout << lineNum++ << ' ' << word << endl;
                }
            }
            catch (ios::failure) {
                //end of file;
            }

            if (in != &cin) delete in;
            delete tp;
        }
    }
    catch (ios::failure) {
        cout << "not exist file name" << endl;

    }
}
