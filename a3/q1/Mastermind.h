//
// Created by 孟天奥 on 2020-09-09.
//

#ifndef Q1_MASTERMIND_H
#define Q1_MASTERMIND_H

#include <string>
struct Mastermind {
    int seed;
    int codeLength;
    int guessLimit;
    int * white;
    int * black;
    std :: string Limit_char = "ABCDEF";
    char* code;
    char* code_guess;
    Mastermind(int seed, int codeLength, int guessCount);
    void playGame();
    void check_same(char * code, char * code_guess, int * white, int * black);
    bool check_win(char * code, char * code_guess);
    ~Mastermind();

};



#endif //Q1_MASTERMIND_H
