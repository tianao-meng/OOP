//
// Created by 孟天奥 on 2020-10-25.
//

#ifndef A5_BOARD_H
#define A5_BOARD_H

#include <vector>


//#include "monopoly.h"
//#include "player.h"
#include <string>
#include "Chance_and_Community_chest.h"
#include "building_type.h"

//class square;
//class player;
class monopoly;

class board {

    std :: vector <square *> game_board;
    std :: vector <monopoly *> monopoly_blocks;
    player * bank;


public:

    board(player * bank);
    std :: vector <square *> get_game_board();
    square * get_square(int index);
    square * get_square(const std :: string& name);
    void draw();
    ~board();

};


#endif //A5_BOARD_H
