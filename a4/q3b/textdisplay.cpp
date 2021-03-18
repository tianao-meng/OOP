

#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize(n) {

    //theDisplay.resize(gridSize);
    vector<char> add (gridSize);
    for (int i = 0; i < gridSize; i++){

        //theDisplay[n].resize(n);
        theDisplay.push_back(add);

    }

    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){

            //cout << gridSize << " in" << endl;
            theDisplay[i][j] = '_';

        }

    }


}

void TextDisplay::notify(Subject &whoNotified) {

    Info notifier = whoNotified.getInfo();
    int row = notifier.row;
    int column = notifier.col;
    bool state = notifier.state;

    if (state){
        theDisplay[row][column] = 'X';
    } else {
        theDisplay[row][column] = '_';
    }

//    if (theDisplay[row][column] == 'X'){
//        theDisplay[row][column] = '_';
//    } else {
//        theDisplay[row][column] = 'X';
//    }
//
//    if (theDisplay[row - 1][column] == 'X'){
//        theDisplay[row - 1][column] = '_';
//    } else {
//        theDisplay[row - 1][column] = 'X';
//    }
//
//    if (theDisplay[row + 1][column] == 'X'){
//        theDisplay[row + 1][column] = '_';
//    } else {
//        theDisplay[row + 1][column] = 'X';
//    }
//
//    if (theDisplay[row][column - 1] == 'X'){
//        theDisplay[row][column - 1] = '_';
//    } else {
//        theDisplay[row][column - 1] = 'X';
//    }
//
//    if (theDisplay[row][column + 1] == 'X'){
//        theDisplay[row][column + 1] = '_';
//    } else {
//        theDisplay[row][column + 1] = 'X';
//    }

    //cout << *this;
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
    return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {

    for (int i = 0; i < td.gridSize; i ++){

        for (int j = 0; j< td.gridSize; j ++){

            if (j == (td.gridSize - 1) ){
                cout << td.theDisplay[i][j] << endl;
                break;
            }

            cout << td.theDisplay[i][j];

        }


    }

    return out;
}

