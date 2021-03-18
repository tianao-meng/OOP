//
// Created by 孟天奥 on 2020-09-09.
//
#include <cstdlib>
#include "Mastermind.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Mastermind::Mastermind(int seed, int codeLength, int guessCount) {

    //cout << "guess limit " << guessCount;
    Mastermind::seed = seed;
    Mastermind::codeLength = codeLength;
    Mastermind::guessLimit = guessCount;
    srand(Mastermind::seed);

    Mastermind::code = new char [codeLength];
    Mastermind::code_guess = new char [codeLength];
    Mastermind::black = new int;
    Mastermind::white = new int;
}


void Mastermind::playGame(){

    for (int i = 0; i < codeLength; i += 1){
        //cout << "in " << endl;
        char password = Limit_char[rand() % 6];
        //cout << "in " << endl;

        code[i] = password;

    }

    cout << "Welcome to Mastermind! Please enter your first guess." << endl;


    char input;
    int guess_num = 0;
    //int white, black = 0;

    while (guess_num < guessLimit){
        cout << '>';
        int index = 0;
        while(true){
            cin >> input;
            //cout << input << endl;

            if ((( input >= 'A' ) && (input <= 'F')) || (( input >= 'a' ) && (input <= 'f'))) {

                if ((( input >= 'a' ) && (input <= 'f'))){

                    code_guess[index] = 'A' + (input - 'a');
                    index += 1;
                    if (index == codeLength){
                        break;
                    }
                    continue;
                }

                code_guess[index] = input;
                index += 1;

                if (index == codeLength){
                    break;
                }

            } else {
                //cin.ignore();
                continue;
            }

        }

        guess_num += 1;

        //cout << "in" << endl;
        *white = 0;
        *black = 0;
        check_same(code, code_guess, white, black);
        if (check_win(code, code_guess)){
            cout << "You won in guessCount guesses!" << endl;
            cout << "Would you like to play again? (Y/N): ";
            char quit;
            cin >> quit;
            if ((quit == 'Y') || (quit == 'y')){
                playGame();
            }
            return;
        }
        fprintf( stdout,"%db, %dw\n", *black, *white);
        fprintf( stdout,"%d guesses left. Enter guess:\n",(guessLimit - guess_num));



    }

    cout << "You lost! The password was" << endl;
    for (int i = 0; i < codeLength; i++){
        cout << code[i];
    }
    cout << endl;
    cout << "Would you like to play again? (Y/N): ";
    char quit;
    cin >> quit;
    if ((quit == 'Y') || (quit == 'y')){
        playGame();
    }


}

void Mastermind ::check_same(char * code, char * code_guess, int * white, int * black){

    char pivot;

    for (int i = 0; i < codeLength; i++){

        pivot = code[i];

        if (pivot == code_guess[i]){
            (*black) ++;
            continue;
        }

        for (int j = 0; j < codeLength; j++){

            if (j == i){

                continue;

            } else {

                if ((code_guess[j] == pivot) && (code_guess[j] != code[j])){

                    (*white) ++;
                    break;
                }
            }

        }




    }
    //cout << "white" << " " << white;


}

bool Mastermind :: check_win(char * code, char * code_guess){

    int count = 0;
    for (int i = 0; i < codeLength; i++){

        if (code[i] == code_guess[i]){
            count ++;
        }
    }

    return count == codeLength;

}

Mastermind :: ~Mastermind(){

    delete [] code;
    delete [] code_guess;
    delete  white;
    delete  black;

}










