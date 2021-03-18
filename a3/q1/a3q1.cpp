#include <iostream>
#include <sstream>
#include "Mastermind.h"
using namespace std;

int main(int argc, char * argv[] ) {

    int seed;
    int codeLength;
    int guessLimit;
    stringstream ss;
    stringstream ss1;
    stringstream ss2;

    if (argc != 4){
        cerr << "not correct number of input" << endl;
    } else {

        ss << argv[1];
        ss >> seed;
        //cout << "seed " << seed;

        ss1 << argv[2];
        ss1 >> codeLength;
        //cout << "codeLength " << argv[2];

        if (codeLength < 0){
            cerr << "no negative number for codeLengtht" << endl;
        }

        ss2 << argv[3];
        ss2 >> guessLimit;

        //cout << "guess limit " << argv[3];

        if (guessLimit < 0){
            cerr << "no negative number for guessLimit" << endl;
        }

        Mastermind game (seed, codeLength, guessLimit);
        game.playGame();

    }



    return 0;
}
