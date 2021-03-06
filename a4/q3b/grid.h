

#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include "cell.h"
#include "textdisplay.h"
#include "GraphicsDisplay.h"

class Grid {
    std::vector<std::vector<Cell > > theGrid;  // The actual grid.
    int gridSize;    // Size of the grid.
    TextDisplay *td; // The text display.
    GraphicsDisplay * gd;
    // Add private members, if necessary.

    void clearGrid();   // Frees the grid.
    //void createGrid(int i);

public:
    Grid();
    ~Grid();


    bool isWon() const; // Call to determine if grid is in a winning state.
    void init(int n, Xwindow & w); // Sets up an n x n grid.  Clears old grid, if necessary.
    void turnOn(int r, int c);  // Sets cell at row r, col c to On.
    void toggle(int r, int c);  // Switches cell at (r, c) between On and Off.
    void init(int r, int c);
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif

