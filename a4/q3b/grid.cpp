
#include <iostream>
#include "grid.h"
#include "GraphicsDisplay.h"
using namespace std;

Grid::Grid() {
    gridSize = 0;
}

Grid::~Grid() {

    theGrid.clear();
    delete td;
    delete gd;

}

void Grid::clearGrid() {

    for (int i = 0; i < gridSize ; i++){

        theGrid[i].clear();
    }
    theGrid.clear();
    delete td;
    delete gd;
    gridSize = 0;
}
//void Grid :: createGrid(int n){
//
//
//}

bool Grid::isWon() const {

    for (int i = 0; i < gridSize; i++){

        for (int j = 0; j < gridSize; j++){

            if (theGrid[i][j] . getState()){
                return false;
            }

        }

    }

    return true;
}

void Grid::init(int n, Xwindow & w) {


    if (gridSize != 0){
        clearGrid();
    }


    td = new TextDisplay(n);
    gd = new GraphicsDisplay(w, n);
    gridSize = n;

//    theGrid.resize(n);
//    for (int i = 0; i < gridSize; i++){
//
//        theGrid[n].resize(n);
//
//    }
    vector<Cell> add (gridSize);

    for (int i = 0; i < gridSize; i++){

        //theDisplay[n].resize(n);
        theGrid.push_back(add);

    }

    for (int i = 0; i < gridSize; i++){

        for (int j = 0; j < gridSize; j++){

            theGrid[i][j].setCoords(i,j);

            if ((i - 1) >= 0){
                theGrid[i][j].attach(&theGrid[i - 1][j]);
            }

            if ((i + 1) < gridSize){
                theGrid[i][j].attach(&theGrid[i + 1][j]);
            }

            if ((j - 1) >= 0){
                theGrid[i][j].attach(&theGrid[i][j - 1]);
            }

            if ((j + 1) < gridSize){
                theGrid[i][j].attach(&theGrid[i][j + 1]);
            }

            theGrid[i][j].attach(td);
            theGrid[i][j].attach(gd);

        }
    }

}

void Grid::turnOn(int r, int c) {
    theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
    theGrid[r][c].toggle();
    theGrid[r][c].notifyObservers(SubscriptionType :: SwitchOnly);

}

void Grid::init(int r, int c) {

    turnOn(r,c);
    theGrid[r][c].notifyObservers(SubscriptionType :: All);
}

ostream &operator<<(ostream &out, const Grid &g) {

    cout << *(g.td);
    return out;
}
