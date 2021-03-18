//
// Created by 孟天奥 on 2020-10-26.
//

#ifndef A5_SQUARE_H
#define A5_SQUARE_H

#include <string>
#include <vector>
#include "building_type.h"
class player;
class board;

class square {

    int index;
    std :: string representation;
    //board & my_board;
    std :: vector <player * > players;
    building_type type;
    board * game_board = nullptr;
    std :: string name;


public:

    square(int index, std :: string representation, building_type type, std :: string name);
    square() = default;
    virtual int get_index();
    virtual std::string get_representation();
    void set_representation(std::string a);
    virtual void punish(player * punished) = 0;
    void notify(player * who_in);
    virtual void push_back(player * who_in);
    virtual void dattach(player * who_in);
    virtual building_type get_building_type();
    void set_building_type(building_type type_1);
    board * get_game_board();
    void set_game_board(board * board);
    square * get_square(int index);
    virtual std :: string get_name();

    void check_overdraft(int bill, player * current_player);
    virtual player * get_owner() = 0;
    bool check_enough_to_pay(int bill, player * current_player, player * to);
    virtual ~square() = 0;
    //board & get_board();
    //virtual void action(player a);

};

#endif //A5_SQUARE_H
