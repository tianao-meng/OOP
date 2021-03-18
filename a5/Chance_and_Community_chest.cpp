//
// Created by 孟天奥 on 2020-10-28.
//
#include "Chance_and_Community_chest.h"
#include <iostream>


using namespace std;
string cards :: get_on_card(){
    return on_card;
}
void cards :: set_on_card(string a){
    on_card = a;
}

cards * community_chest :: get_card() {

    int iSecret = rand() % 24 + 1;

    int Roll_Up_the_Rim_Cup = rand() % 100 + 1;
    if (Roll_Up_the_Rim_Cup == 1){
        set_on_card("Roll_Up_the_Rim_Cup");
        return this;
    }

    if ((iSecret >= 1) && (iSecret <= 3)){
        set_on_card("Back 3");
    }
    else if ((iSecret >= 4) && (iSecret <= 7)){
        set_on_card("Back 2");
    }
    else if ((iSecret >= 8) && (iSecret <= 11)){
        set_on_card("Back 1");
    }
    else if ((iSecret >= 12) && (iSecret <= 14)){
        set_on_card("Forward 1");
    }
    else if ((iSecret >= 15) && (iSecret <= 18)){
        set_on_card("Forward 2");
    }
    else if ((iSecret >= 19) && (iSecret <= 22)){
        set_on_card("Forward 3");
    }
    else if (iSecret == 23){
        set_on_card("Go to DC Tims Line");
    }
    else{
        set_on_card("Advance to Collect OSAP");
    }

    return this;

}

community_chest :: community_chest(){
    set_on_card(community_chest :: get_card() -> get_on_card());
}

cards * chance :: get_card() {
    int iSecret = rand() % 18 + 1;

    int Roll_Up_the_Rim_Cup = rand() % 100 + 1;
    if (Roll_Up_the_Rim_Cup == 1){

        set_on_card("Roll_Up_the_Rim_Cup");
        return this;
    }
    if (iSecret == 1){
        set_on_card("-200");
    }
    else if ((iSecret >= 2) && (iSecret <= 3)){
        set_on_card("-100");
    }
    else if ((iSecret >= 4) && (iSecret <= 6)){
        set_on_card("-50");
    }
    else if ((iSecret >= 7) && (iSecret <= 12)){
        set_on_card("25");
    }
    else if ((iSecret >= 13) && (iSecret <= 15)){
        set_on_card("50");
    }
    else if ((iSecret >= 16) && (iSecret <= 17)){
        set_on_card("100");
    }
    else{
        set_on_card("200");
    }
    return this;



}

chance :: chance(){
    set_on_card(chance :: get_card() -> get_on_card());
}

cards * community_chest_maker :: order(){

    cards * output = new community_chest();
    return output;

}

cards * chance_maker :: order(){

    cards * output = new chance();
    return output;

}

cards_maker * community_chest_maker_factory :: create() {
    cards_maker * output = new community_chest_maker();
    return output;
}

cards_maker * chance_maker_factory :: create() {
    cards_maker * output = new chance_maker();
    return output;
}

card :: card (int index, string representation, player * bank, cards_maker :: kind kind, string name) : square(index, representation, building_type :: card, name), bank(bank), kind(kind){
    //cout << "index card : " << index;
}

//building_type card :: get_building_type(){
//    return type;
//}

cards * dispach(cards_maker :: kind card, cards_maker * community_chest_Hub, cards_maker * chance_Hub){


    switch (card){
        case cards_maker :: Community_Chest : return community_chest_Hub -> order();
        case cards_maker :: Chance : return chance_Hub -> order();
    }

}

//square * card :: get_square(int index) {
//
//    vector <square *> :: iterator it;
//    board * board = get_game_board();
//    vector <square *> game_board = board -> get_game_board();
//    for (it=game_board.begin(); it != game_board.end(); it++){
//        int square_index = (*it) ->get_index();
//        //int square_y = (*it) ->get_y();
//        if (square_index == index){
//            return *it;
//        }
//    }
//
//
//}

void card :: punish(player * punished){
    cout << punished -> get_name() << " arrived " << get_name() << endl;
    community_chest_maker_factory community_chest_maker_factory;
    chance_maker_factory chance_maker_factory;

    cards_maker * community_chest_Hub = community_chest_maker_factory.create();
    cards_maker * chance_Hub = chance_maker_factory.create();
    cards * chosen_card = dispach(kind, community_chest_Hub, chance_Hub);
    string on_card = chosen_card -> get_on_card();

    cout << "you get " << on_card << " card" << endl;
    if (on_card == "Roll_Up_the_Rim_Cup"){
        std :: cout << "congraduations, you get Roll_Up_the_Rim_Cup" << endl;
        if ( (player::num_Roll_Up_the_Rim_Cup_Sent()) < 4){
            punished -> increase_Roll_Up_the_Rim_Cup();
            std :: cout << "congraduations, you get Roll_Up_the_Rim_Cup" << endl;
            player:: increase_Roll_Up_the_Rim_Cup_Sent();
            //punish(punished);
            return;
        }

    }

    if (kind == cards_maker :: Community_Chest){

        if (on_card == "Back 3") {
            cout << punished -> get_name() << " go back 3" << endl;
            punished -> move(-3, 0);
//            square * move_to = get_square((punished -> get_index() - 3));
//            dattach(punished);
//            move_to->notify(punished);

        }

        if (on_card == "Back 2") {
            cout << punished -> get_name() << " go back 2" << endl;
            punished -> move(-2, 0);
//            square * move_to = get_square((punished -> get_index() - 2));
//            dattach(punished);
//            move_to->notify(punished);

        }

        if (on_card == "Back 1") {
            cout << punished -> get_name() << " go back 1" << endl;
            punished -> move(-1, 0);
//            square * move_to = get_square((punished -> get_index() - 1));
//            dattach(punished);
//            move_to->notify(punished);

        }

        if (on_card == "Forward 1") {
            cout << punished -> get_name() << " forward 1" << endl;
            punished -> move(1, 0);
//            square * move_to = get_square((punished -> get_index() + 1));
//            dattach(punished);
//            move_to->notify(punished);

        }

        if (on_card == "Forward 2") {
            cout << punished -> get_name() << " forward 2" << endl;
            punished -> move(2, 0);
//            square * move_to = get_square((punished -> get_index() + 2));
//            dattach(punished);
//            move_to->notify(punished);

        }

        if (on_card == "Forward 3") {
            cout << punished -> get_name() << " forward 3" << endl;
            punished -> move(3, 0);
//            square * move_to = get_square((punished -> get_index() + 3));
//            dattach(punished);
//            move_to->notify(punished);

        }

        if (on_card == "Go to DC Tims Line") {
            cout << punished -> get_name() << " go to Go to DC Tims Line" << endl;
            punished -> set_card(1);
            punished -> move(10 - punished -> get_index(), 0);
//            square * move_to = get_square(30);
//            dattach(punished);
//            move_to->notify(punished);
        }

        if (on_card == "Advance to Collect OSAP") {
            cout << punished -> get_name() << " go to Collect OSAP" << endl;
            punished -> move(40 - punished -> get_index(), 0);
//            square * move_to = get_square(0);
//            dattach(punished);
//            move_to->notify(punished);
        }

    } else {
        if (on_card == "-200") {
            cout << punished -> get_name() << " is punished 200$" << endl;
            if (!check_enough_to_pay(200, punished, bank)){
                return;
            }
            punished -> decrease_account(200);
            bank -> increase_account(200);

        }

        if (on_card == "-100") {
            cout << punished -> get_name() << " is punished 100$" << endl;
            if (!check_enough_to_pay(100, punished, bank)){
                return;
            }
            punished -> decrease_account(100);
            bank -> increase_account(100);

        }

        if (on_card == "-50") {
            cout << punished -> get_name() << " is punished 50$" << endl;
            if (!check_enough_to_pay(50, punished, bank)){
                return;
            }
            punished -> decrease_account(50);
            bank -> increase_account(50);

        }

        if (on_card == "25") {
            cout << punished -> get_name() << " get 25$" << endl;
            punished -> increase_account(25);
            bank -> decrease_account(25);

        }

        if (on_card == "50") {
            cout << punished -> get_name() << " get 50$" << endl;
            punished -> increase_account(50);
            bank -> decrease_account(50);

        }

        if (on_card == "100") {
            cout << punished -> get_name() << " get 100$" << endl;
            punished -> increase_account(100);
            bank -> decrease_account(100);

        }

        if (on_card == "200") {
            cout << punished -> get_name() << " get 200$" << endl;
            punished -> increase_account(200);
            bank -> decrease_account(200);
        }

    }

    delete community_chest_Hub;
    delete chance_Hub;
    delete chosen_card;

}

player * card :: get_owner(){
    return bank;
}