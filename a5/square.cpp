//
// Created by 孟天奥 on 2020-10-26.
//
#include "square.h"
#include <iostream>
#include "player.h"
using namespace std;

square :: square (int index, string representation, building_type type, string name): index(index), representation(representation), type(type), name(name){

}

int square :: get_index(){
    //cout << "in" << index << endl;
    return index;
}

std::string square :: get_representation(){
    return representation;
}

void square :: set_representation(std::string a){
    representation = a;
}
void square :: push_back(player * who_in){
    players.push_back(who_in);
    if (index != 10){
        who_in -> set_index(index);
    }

    if (type != building_type :: academic){
        if (players.size() == 1) {
            representation[35] = who_in ->get_representation();
        }

        if (players.size() == 2) {
            representation[37] = who_in ->get_representation();
        }

        if (players.size() == 3) {
            representation[39] = who_in ->get_representation();
        }

        if (players.size() == 4) {
            representation[41] = who_in ->get_representation();
        }

        if (players.size() == 5) {
            representation[43] = who_in ->get_representation();
        }

        if (players.size() == 6) {
            representation[47] = who_in ->get_representation();
        }

        if (players.size() == 7) {
            representation[49] = who_in ->get_representation();
        }

        if (players.size() == 8) {
            representation[51] = who_in ->get_representation();
        }

        if (players.size() == 9) {
            representation[53] = who_in ->get_representation();
        }


    } else {

        if (players.size() == 1) {
            representation[47] = who_in ->get_representation();
        }

        if (players.size() == 2) {
            representation[48] = who_in ->get_representation();
        }

        if (players.size() == 3) {
            representation[49] = who_in ->get_representation();
        }

        if (players.size() == 4) {
            representation[50] = who_in ->get_representation();
        }

        if (players.size() == 5) {
            representation[51] = who_in ->get_representation();
        }

        if (players.size() == 6) {
            representation[52] = who_in ->get_representation();
        }

        if (players.size() == 7) {
            representation[53] = who_in ->get_representation();
        }

        if (players.size() == 8) {
            representation[54] = who_in ->get_representation();
        }

        if (players.size() == 9) {
            representation[55] = who_in ->get_representation();
        }

    }


}

void square :: dattach(player * who_out){

    vector <player * > :: iterator it;

    if (type != building_type :: academic){
        int count = 1;

        for (it = players.begin(); it != players.end(); it++){

            if (count == 1){
                representation[35] = ' ';
                count ++;
                continue;
            }

            if (count == 2){
                representation[37] = ' ';
                count ++;
                continue;
            }

            if (count == 3){
                representation[39] = ' ';
                count ++;
                continue;
            }

            if (count == 4){
                representation[41] = ' ';
                count ++;
                continue;
            }

            if (count == 5){
                representation[43] = ' ';
                count ++;
                continue;
            }

            if (count == 6){
                representation[47] = ' ';
                count ++;
                continue;
            }

            if (count == 7){
                representation[49] = ' ';
                count ++;
                continue;
            }

            if (count == 8){
                representation[51] = ' ';
                count ++;
                continue;
            }

            if (count == 9){
                representation[53] = ' ';
                count ++;
                continue;
            }

        }

        count = 1;

        for (it = players.begin(); it != players.end(); it++){

            if ((*it) -> get_name() == who_out ->get_name()){

                players.erase(it);
                break;

            }



        }
        for (it = players.begin(); it != players.end(); it++){

            if (count == 1){
                representation[35] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 2){
                representation[37] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 3){
                representation[39] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 4){
                representation[41] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 5){
                representation[43] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 6){
                representation[47] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 7){
                representation[49] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 8){
                representation[51] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 9){
                representation[53] = (*it) ->get_representation();
                count ++;
                continue;
            }
        }

    } else {
        int count = 1;

        for (it = players.begin(); it != players.end(); it++){

            if (count == 1){
                representation[47] = ' ';
                count ++;
                continue;
            }

            if (count == 2){
                representation[48] = ' ';
                count ++;
                continue;
            }

            if (count == 3){
                representation[49] = ' ';
                count ++;
                continue;
            }

            if (count == 4){
                representation[50] = ' ';
                count ++;
                continue;
            }

            if (count == 5){
                representation[51] = ' ';
                count ++;
                continue;
            }

            if (count == 6){
                representation[52] = ' ';
                count ++;
                continue;
            }

            if (count == 7){
                representation[53] = ' ';
                count ++;
                continue;
            }

            if (count == 8){
                representation[54] = ' ';
                count ++;
                continue;
            }

            if (count == 9){
                representation[55] = ' ';
                count ++;
                continue;
            }

        }

        count = 1;

        for (it = players.begin(); it != players.end(); it++){

            if ((*it) -> get_name() == who_out ->get_name()){

                players.erase(it);
                break;

            }



        }
        for (it = players.begin(); it != players.end(); it++){

            if (count == 1){
                representation[47] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 2){
                representation[48] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 3){
                representation[49] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 4){
                representation[50] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 5){
                representation[51] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 6){
                representation[52] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 7){
                representation[53] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 8){
                representation[54] = (*it) ->get_representation();
                count ++;
                continue;
            }

            if (count == 9){
                representation[55] = (*it) ->get_representation();
                count ++;
                continue;
            }
        }
    }



}

void square :: notify(player * who_in){
    push_back(who_in);
    punish(who_in);

}

building_type square :: get_building_type(){
    return type;
}

void square :: set_building_type(building_type type_1){
    type = type_1;
}

board * square :: get_game_board(){
    return game_board;
}

void square ::set_game_board(board * board) {
    game_board = board;
}

square * square :: get_square(int index) {

    vector <square *> :: iterator it;
    board * board = get_game_board();
    vector <square *> game_board = board -> get_game_board();
    for (it=game_board.begin(); it != game_board.end(); it++){
        int square_index = (*it) ->get_index();
        //int square_y = (*it) ->get_y();
        if (square_index == index){
            return *it;
        }
    }


}



string square :: get_name(){
    return name;
}

void square :: check_overdraft(int bill, player * current_player){

    if (bill > current_player -> get_account()){

        int owed = bill;
        current_player -> set_money_owned(owed);
        current_player -> set_player_owned(get_owner());
        return;
    } else {
        return;
    }

}

bool square :: check_enough_to_pay(int bill, player * current_player, player * to){

    check_overdraft(bill, current_player);
    if (current_player ->  get_money_owned() > 0){

        cout << "you do not have enough money to pay for the payment : " << bill <<  " to " << to -> get_name() << endl;

        return false;
    }
    return true;

}
square ::~square()= default;
//void square :: set_bank(player * bank){
//    square :: bank = bank;
//}


