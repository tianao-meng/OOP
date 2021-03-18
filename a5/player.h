//
// Created by 孟天奥 on 2020-10-24.
//

#ifndef A5_PLAYER_H
#define A5_PLAYER_H

#include <string>
#include "board.h"
#include <cstdlib>
#include <ctime>
#include "building_type.h"
#include <vector>


class square;
class square_ownable;
class academic;


static int Roll_Up_the_Rim_Cup_Sent = 0;
class player {

    std :: string name;
    char representation;
    int account;
    player * bank;
    std :: vector <square_ownable * > own_buildings;
    int index;
    board * game_board;
    int Roll_Up_the_Rim_Cup = 0;
    std :: vector <player * > players;
    int in_dc_tims_line = 0;
    int if_in_dc_tims_line = 0;
    int three_doubles = 0;
    int card = 0;
    int money_owned = 0;
    player * player_owned;
    int bankrupt = 0;
    int in_transfer = 0;
    int back_flage = 0;
    //vector <player *> players;
    //vector <square_ownable *> mortgaged;


public:

    player(std :: string name, char representation, player * bank, int index, board * game_board);
    player();
    int get_account();
    void set_account(int i);
    char get_representation();
    void increase_account(int payment);
    void decrease_account(int payment);
    std :: string get_name();
    void set_index (int a);
    int get_index();
    board * get_game_board();
    void notify_square();
    int get_total();
    int roll_dice();
    int get_Roll_Up_the_Rim_Cup();
    void set_Roll_Up_the_Rim_Cup(int i);
    void increase_Roll_Up_the_Rim_Cup();
    void decrease_Roll_Up_the_Rim_Cup();
    void move(int dice_1, int dice_2);
    void auction(square_ownable * building);
    void buy_improve(academic * building);
    void sell_improve(academic * building);
    void mortgage(std :: string property);
    void unmortgage(std :: string property);
    void push_own_buidling(square_ownable * building);
    void dattach_own_building(square_ownable * building);
    std :: vector <square_ownable *> get_own_buildings();
    static int num_Roll_Up_the_Rim_Cup_Sent(){
        return Roll_Up_the_Rim_Cup_Sent;
    };
    static void increase_Roll_Up_the_Rim_Cup_Sent(){
            Roll_Up_the_Rim_Cup_Sent++;
    };
    static void decrease_Roll_Up_the_Rim_Cup_Sent(){
        Roll_Up_the_Rim_Cup_Sent--;
    };
    static void set_Roll_Up_the_Rim_Cup_Sent(int i){
        Roll_Up_the_Rim_Cup_Sent = i;
    };

    void set_players(std :: vector <player * > player_group);
    int join_bid(int current_bid);
    void dattach(square_ownable * building);
    int get_in_dc_tims_line();
    int get_if_in_dc_tims_line();
    void set_if_in_dc_tims_line(int i);
    void increase_in_dc_tims_line();
    void set_in_dc_tims_line(int i);
    void set_three_doubles();
    int get_three_doubles();
    int get_card();
    void set_card( int i);
    void set_money_owned(int money);
    void set_player_owned(player * to_who);
    int get_money_owned();
    player * get_player_owned();
    bool check_all_mortgaged();
    void set_bankrupt();
    int get_bankrupt();
    void transfer_assets(std :: vector<std :: string> name_chosen);
    void raise_money(std :: vector<std :: string> name_chosen);
    void trade(std :: string trade_object, std :: string give_name, std :: string receive_name, std :: vector<std :: string> name_chosen);
    player * get_trade_object(std :: string player_name, std :: vector <player * > players);
    bool check_num(std :: string a);
    bool check_buliding(std :: string building);
    bool check_building_can_trade (square * building);
    void improve(std :: string property, std :: string decision);
    void assets();
    void all();
    void save(std :: ofstream &out);
    int get_back_flag();
    void set_back_flage(int i);
    void set_in_transfer(int i);
    int get_in_transfer();

    ~player();


//    void sell(square_ownable * a);
//    void mortgage(square_ownable * a);
//    void unmortgage(square_ownable * a);
//    void bankrupt();

};

bool check_in_namelist (std :: vector <std :: string > name_list, std :: string name);
bool check_buliding(std :: string building, player * owner);
#endif //A5_PLAYER_H
