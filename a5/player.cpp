//
// Created by 孟天奥 on 2020-10-24.
//

#include "player.h"
#include "academic.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

bool check_in_namelist (vector <string > name_list, string name){

    vector<string> :: iterator it ;
    for (it = name_list.begin(); it != name_list.end(); it ++){

        if (name == (*it)){
            return true;
        }

    }

    return false;

}

player :: player(){
    name = "Bank";
    representation = '0';
    account = 1000000;
    bank = nullptr;
}

player :: player(string name, char representation, player * bank, int index, board * game_board) :name(name), representation(representation), bank(bank), index(index), game_board(game_board){

    account = 1500;
    Roll_Up_the_Rim_Cup = 0;

}

int player :: get_account(){
    return account;
}

void player :: set_account(int i){
    account = i;
}

char player :: get_representation(){

    return representation;

}

string player :: get_name(){
    return name;
}

void player :: increase_account(int payment){
    account += payment;
    cout << name << " increases " << payment << "$" << endl;
}

void player :: decrease_account(int payment) {
    account -= payment;
    cout << name << " decreases " << payment << "$" << endl;
}
void player :: set_index(int a) {

    index = a;

}

board * player :: get_game_board(){
    return game_board;
}

int player :: get_index(){
    return index;
}

int player :: get_total(){

    vector <square_ownable * > :: iterator it;
    int sum = account;
    for (it = own_buildings.begin(); it != own_buildings.end(); it++){

        if ((*it) -> get_building_type() == building_type :: academic){

            int improvements = dynamic_cast<academic * > (*it) -> get_improvements();
            int improvements_fee = dynamic_cast<academic * > (*it) -> get_monopoly() -> get_improvement_fee();
            sum += (improvements * improvements_fee);
            sum += dynamic_cast<academic * > (*it) -> get_price();
            continue;

        }

        sum += (*it) -> get_price();
    }

    return sum;
}
void player :: notify_square(){
    vector <square *> squares = game_board -> get_game_board();
    vector <square *> ::iterator it;
    for (it = squares.begin(); it != squares.end(); it++){

        if ((*it) -> get_index() == index){

            (*it) -> notify(this);
            break;

        }

    }
}

int player :: roll_dice(){
    int output = rand() % 6 + 1;
    return output;
}

int player :: get_Roll_Up_the_Rim_Cup(){
    return Roll_Up_the_Rim_Cup;
}

void player :: set_Roll_Up_the_Rim_Cup(int i){
    Roll_Up_the_Rim_Cup = i;
}

void player :: increase_Roll_Up_the_Rim_Cup(){
    Roll_Up_the_Rim_Cup ++;
}
void player :: decrease_Roll_Up_the_Rim_Cup() {
    Roll_Up_the_Rim_Cup --;
}

void player :: set_players(vector <player * > player_group){

    players = player_group;
}

int player :: join_bid(int current_bid){
    if (get_bankrupt() > 0){
        cout << name << ", you have been bankrupt, cannot join the bid" << endl;
        return -1;
    }
    string command;
    while (true){
        cout << "The bid now is "<< current_bid << endl;
        cout << name << R"( please issue "raise" or "withdraw")" << endl;
        cout << name << R"(, you can also issue issue "assets" and issue "all")" << endl;
        getline(cin, command);
        if (command == "raise") {

            while (true) {
                if (account < current_bid) {
                    cout << name << ", you do not enough money to join auction, please issue \"withdraw\" " << endl;
                    break;
                }
                int new_bid;
                string buffer;
                stringstream ss;
                ss.exceptions(ios::failbit);
                while (true) {
                    try {
                        cout << name << " please enter the new bid" << endl;
                        getline(cin, buffer);
                        ss.str(buffer);
                        ss >> new_bid;
                        break;
                    } catch (ios::failure) {
                        cout << name << "wrong amount of bid input" << endl;
                        ss.clear();
                        ss.ignore();
                    }

                }

                try{
                    ss >> buffer;
                    cout << "buffer: " << buffer << endl;
                    cout << name << " wrong amount of bid input" << endl;
                    ss.clear();
                    break;
                }  catch (ios::failure) {
                    ss.clear();
                }
                //cout << "in" << endl;
                if (new_bid <= current_bid) {
                    cout << name << " not valid for the bid, you should enter a number larger than the current one" << endl;
                    continue;
                }

                if (new_bid <= account) {
                    cout << name << " congraduation, you successfully join the auction" << endl;
                    return new_bid;
                } else {
                    cout << name << " not enough money for join the auction, please enter a new number" << endl;
                    continue;
                }

            }


        } else if (command == "withdraw"){

            cout << name << ", you choose to withdraw the auction" << endl;
            return -1;

        } else if (command == "assets"){

            assets();
        } else if (command == "all"){

            all();
        } else {
            cout << name << " not valid input, please try again" << endl;
        }

    }

}

void player :: auction(square_ownable * building){

    vector <player * > :: iterator it;
    int current_bid = 0;
    vector <player * > auction_player;

    for (it = players.begin(); it != players.end(); it++){

        auction_player.push_back((*it));

    }

    while (true){


        for (it = auction_player.begin(); it != auction_player.end(); it++){

            if (auction_player.size() == 1){
                (*auction_player.begin()) -> decrease_account(current_bid);
                (*auction_player.begin()) -> push_own_buidling(building);
                account += current_bid;
                building -> set_owner(*auction_player.begin());
                //cout << "after auction, the " << building -> get_name() << " is owned by " << (*auction_player.begin()) -> get_name() << endl;
                return;
            }

            int new_bid = (*it) -> join_bid(current_bid);
            if (new_bid == -1){
                auction_player.erase(it);
                if (it == auction_player.end()){
                    break;
                }

                it --;

            } else {
                current_bid = new_bid;
            }

        }

    }

}

void player :: buy_improve(academic * building) {

    int num_improvements = building -> get_improvements();
    if ((num_improvements + 1) > 5){

        cout << "you can not buy the improvements of " << building -> get_name() << endl;
        cout << "the max num of improvements is 5" << endl;
        return;

    } else {
        int improvement_fee = building -> get_monopoly() -> get_improvement_fee();
        decrease_account(improvement_fee);
        bank -> increase_account(improvement_fee);
        building -> improve();
        game_board -> draw();
        cout << name <<" successfully improve " << building -> get_name() << endl;
        return;
    }


}

void player :: sell_improve(academic * building){

    int num_improvements = building -> get_improvements();
    if ((num_improvements - 1) < 0){

        cout << "you can not sell the improvements of " << building -> get_name() << endl;
        cout << "the min num of improvements is 0" << endl;
        return;

    } else {
        int improvement_fee = building -> get_monopoly() -> get_improvement_fee();
        int player_get = 0.5 * improvement_fee;
        increase_account(player_get);
        bank -> decrease_account(player_get);
        building -> deprove();
        game_board -> draw();
        cout << name <<" successfully sell the improvements of " << building -> get_name() << endl;
        return;
    }

}

void player :: mortgage(string property){

    if (!check_buliding(property)){

        cout << "Hi, " << get_name() << ". The property you want to mortgage is not your owning or just non-exist of the property, please check" << endl;
        return;

    }

    square *building_to_mortgage = game_board->get_square(property);

   if (dynamic_cast<square_ownable * >(building_to_mortgage) -> check_if_mortgage()){
       cout << "The " << dynamic_cast<square_ownable * >(building_to_mortgage) -> get_name() << " has been mortgaged" << endl;
       return;
   } else {

       int bill = dynamic_cast<square_ownable * >(building_to_mortgage) -> get_price();
       dynamic_cast<square_ownable * >(building_to_mortgage) -> set_mortgage_flag();
       //mortgaged.push_back(building);
       cout << "you successfully mortgage " << building_to_mortgage -> get_name() << endl;
       increase_account(bill * 0.5);
       bank -> decrease_account(bill * 0.5);
       return;

   }

}

void player :: unmortgage(string property){

    if (!check_buliding(property)){

        cout << "Hi, " << get_name() << ". The property you want to mortgage is not your owning or just non-exist of the property, please check" << endl;
        return;

    }

    square *building_to_unmortgage = game_board->get_square(property);

    if (!dynamic_cast<square_ownable * >(building_to_unmortgage) -> check_if_can_unmortgage()){
        return;
    } else {

        if (in_transfer == 0){
            int bill = dynamic_cast<square_ownable * >(building_to_unmortgage) -> get_price();

            if ((bill * 0.6) > account){
                cout << "you do not have enough money to unmortgage " << building_to_unmortgage -> get_name() << endl;
                return;
            }
            dynamic_cast<square_ownable * >(building_to_unmortgage) -> set_mortgage_flag();
            cout << "you successfully unmortgage " << building_to_unmortgage -> get_name() << endl;
            decrease_account(bill * 0.6);
            bank -> increase_account(bill * 0.6);
            return;

        } else {

            int bill = dynamic_cast<square_ownable * >(building_to_unmortgage) -> get_price();

            if ((bill * 0.5) > account){
                cout << "you do not have enough money to unmortgage " << building_to_unmortgage -> get_name() << endl;
                return;
            }
            dynamic_cast<square_ownable * >(building_to_unmortgage) -> set_mortgage_flag();
            cout << "you successfully unmortgage " << building_to_unmortgage -> get_name() << endl;
            decrease_account(bill * 0.5);
            bank -> increase_account(bill * 0.5);
            in_transfer = 0;
            return;

        }


    }

}




void player :: push_own_buidling(square_ownable * building){

    //cout << building -> get_name() << " now is owned by "<< name << endl;
    own_buildings . push_back(building);

}

void player :: dattach_own_building(square_ownable * building){
    cout << "i am dattaching " << endl;
    std :: vector <square_ownable * > :: iterator it;
    for (it = own_buildings.begin(); it != own_buildings.end(); it++){

        if ((*it) -> get_name() == building -> get_name()){

            own_buildings.erase(it);
            break;
        }

    }

}

vector <square_ownable *> player :: get_own_buildings(){
    return own_buildings;
}



void player :: move(int dice_1, int dice_2){

    int steps = dice_1 + dice_2;
    cout << "steps: " << steps << endl;
    //cout << steps << endl;
    square * current_square = game_board -> get_square(index);
//    cout << "in" << endl;
//    cout << this << endl;
//    cout << current_square << endl;
    //cout << "steps: " << steps << endl;
    current_square -> dattach(this);

    int now_index;
    square * move_to;
    if (index + steps > 39){

        now_index = index + steps - 40;

        if (index != 30){

            if (get_back_flag() != 1){

                if (get_card() == 1){
                    move_to = game_board ->get_square(now_index);
                    move_to -> push_back(this);
                    game_board->draw();
                    set_card(0);
                    cout << name << "you cannot receive 200$ from osap" << endl;
                } else {
                    move_to = game_board ->get_square(now_index);
                    move_to -> push_back(this);
                    game_board->draw();
                    if (now_index != 0){
                        square * osap = game_board -> get_square(0);
                        osap -> punish(this);
                    }

                }


            } else {

                move_to = game_board ->get_square(now_index);
                move_to -> push_back(this);
                game_board->draw();
                set_back_flage(0);
                cout << name << ", a few time ago, you go back pass through osap; you cannot receive 200$ from osap" << endl;

            }



        } else {
            move_to = game_board ->get_square(now_index);
            move_to -> push_back(this);
            game_board->draw();
            if ((dice_1 != 0) && (dice_2 != 0)){

                cout << name << ", you roll " << dice_1 << endl;
                cout << name << ", you roll " << dice_2 << endl;

            }
            cout << "you pass by osap from go to tims, not collect 200$" << endl;
        }

    } else if (index + steps <= 0){

        now_index = 40 + (index + steps);
        if (now_index == 40){
            now_index = 0;
        }

        if (index == 2) {
            set_back_flage(1);
            cout << "you go back from from slc at index 2 , and pass by osap  , not collect 200$" << endl;
        }

        move_to = game_board ->get_square(now_index);
        move_to -> push_back(this);
        game_board->draw();
        if ((dice_1 != 0) && (dice_2 != 0)) {

            cout << name << ", you roll " << dice_1 << endl;
            cout << name << ", you roll " << dice_2 << endl;

        }


    } else {
        now_index = index + steps;
        move_to = game_board ->get_square(now_index);
//        if (if_in_dc_tims_line == 0){
//
//        }
        move_to -> push_back(this);
        game_board->draw();
        //move_to -> punish(this);
        if ((dice_1 != 0) && (dice_2 != 0)){

            cout << name << ", you roll " << dice_1 << endl;
            cout << name << ", you roll " << dice_2 << endl;

        }

    }

    //set_index(now_index);



    if ((move_to -> get_building_type() == building_type:: residence) || (move_to -> get_building_type() == building_type:: gym) || (move_to -> get_building_type() == building_type:: academic)){

        if ((dynamic_cast<square_ownable * >(move_to) -> check_if_mortgage()) && (dynamic_cast<square_ownable * >(move_to) -> get_owner_name() != name)){

            cout << move_to -> get_name() << " has been mortgaged by " << dynamic_cast<square_ownable * >(move_to) -> get_owner_name() << endl;
            cout <<name<< ", you do not have to be punished " << endl;
            return;
        }

        if (dynamic_cast<square_ownable * >(move_to) -> get_owner_name() == "Bank"){
            cout << (move_to) -> get_name() << " now owner: " << dynamic_cast<square_ownable * >(move_to) -> get_owner_name() << endl;
            string command;

            if (dynamic_cast<square_ownable * >(move_to) -> get_building_type() == building_type :: academic){

                cout << move_to -> get_name() << "\'s price is " << dynamic_cast<square_ownable * >(move_to) -> get_price() << endl;
                cout << name << ", if you want to buy " << move_to -> get_name() <<" in " << dynamic_cast<academic * >(move_to) -> get_monopoly_name() << ", issue \"buy\"" << endl;
                cout << name << ", if you do not want to buy " << move_to -> get_name()<<" in " << dynamic_cast<academic * >(move_to) -> get_monopoly_name()  << ", issue \"not buy\"" << endl;
                cout << name << R"(, you can also issue issue "assets" and issue "all")" << endl;

            } else if (dynamic_cast<square_ownable * >(move_to) -> get_building_type() == building_type :: residence){
                cout << move_to -> get_name() << "\'s price is " << dynamic_cast<square_ownable * >(move_to) -> get_price() << endl;
                cout << name << ", if you want to buy " << move_to -> get_name() <<" in residence"  << ", issue \"buy\"" << endl;
                cout << name << ", if you do not want to buy " << move_to -> get_name()<<" in residence" << ", issue \"not buy\"" << endl;
                cout << name << R"(, you can also issue issue "assets" and issue "all")" << endl;
            } else {
                cout << move_to -> get_name() << "\'s price is " << dynamic_cast<square_ownable * >(move_to) -> get_price() << endl;
                cout << name << ", if you want to buy " << move_to -> get_name() <<" in gym"  << ", issue \"buy\"" << endl;
                cout << name << ", if you do not want to buy " << move_to -> get_name()<<" in gym" << ", issue \"not buy\"" << endl;
                cout << name << R"(, you can also issue issue "assets" and issue "all")" << endl;

            }


            while (true){

                getline(cin, command);
                if (command == "buy"){
                    if (account < dynamic_cast<square_ownable * >(move_to) -> get_price()){
                        cout << name << ", you do not have enough to buy "<< move_to -> get_name() << endl;
                        cout << name << ", if you do not want to buy " << dynamic_cast<square_ownable * > (move_to) -> get_name() << ", issue \"not buy\"" << endl;
                        continue;
                    } else {

                        decrease_account(dynamic_cast<square_ownable * >(move_to) -> get_price()) ;
                        bank -> increase_account(dynamic_cast<square_ownable * >(move_to) -> get_price());
                        dynamic_cast<square_ownable * >(move_to) -> set_owner(this);
                        own_buildings .push_back((square_ownable *)move_to);
                        break;

                    }
                } else if (command == "not buy") {

                    bank -> auction(dynamic_cast<square_ownable * >(move_to));
                    break;

                } else if (command == "assets"){
                    assets();
                    cout << endl;
                    continue;
                } else if (command == "all"){
                    all();
                    cout << endl;
                    continue;
                } else {
                    cout << "not valid input " << endl;
                    continue;
                }


            }

        } else {

            if (dynamic_cast<square_ownable * >(move_to) -> get_owner_name() == name){
                cout << name << ", you arrive your owning" << endl;
                return;

            } else {
                cout << "i arrive the other player's owning" << endl;
                move_to -> punish(this);
            }

        }

    }

    if (move_to -> get_building_type() == building_type:: unownable){

        move_to -> punish(this);

    }

    if (move_to -> get_building_type() == building_type:: card){

        move_to -> punish(this);

    }
}

void player :: dattach(square_ownable * building) {

    cout << building -> get_name() << " is not owned by " << name << endl;
    vector <square_ownable * > :: iterator it;
    vector <square_ownable * > new_one;
    for (it = own_buildings.begin(); it != own_buildings.end(); it++){

        if ((*it) -> get_index() == building ->get_index()){

            continue;

        }

        new_one.push_back(*it);

    }

    own_buildings.clear();
    own_buildings = new_one;


}

int player :: get_in_dc_tims_line(){
    return in_dc_tims_line;
}

int player :: get_if_in_dc_tims_line(){
    return if_in_dc_tims_line;
}
void player :: set_if_in_dc_tims_line(int i){
    if_in_dc_tims_line = i;
}

void player :: increase_in_dc_tims_line(){
    in_dc_tims_line ++;
}
void player :: set_in_dc_tims_line(int i ){
    in_dc_tims_line = i;
}

void player :: set_three_doubles(){
    if (three_doubles == 0){
        three_doubles = 1;
    } else {
        three_doubles = 0;
    }
}

int player :: get_three_doubles(){
    return three_doubles;
}

int player :: get_card(){

    return card;
}
void player :: set_card(int i){
    card = i;
}

void player :: set_money_owned(int money){

    money_owned = money;

}
void player :: set_player_owned(player * to_who){

    player_owned = to_who;

}

int player :: get_money_owned(){
    return money_owned;
}
player * player :: get_player_owned(){
    return player_owned;
}

bool player :: check_all_mortgaged(){

    vector <square_ownable *> :: iterator it;
    for (it = own_buildings.begin(); it != own_buildings.end(); it++){

        if (!((*it) -> check_if_mortgage())){
            return false;
        }

    }
    return true;

}

void player :: set_bankrupt() {

    bankrupt = 1;

}

int player :: get_bankrupt(){
    return bankrupt;
}

bool player :: check_buliding(string building){

    vector <square_ownable *> :: iterator building_it;

    for (building_it = own_buildings.begin(); building_it != own_buildings.end(); building_it++){

        if ((*building_it) -> get_name() == building){
            return true;
        }

    }
    return false;


}

bool check_buliding(string building, player * owner){

    vector <square_ownable *> own_buildings = owner -> get_own_buildings();
    vector <square_ownable *> :: iterator building_it;

    for (building_it = own_buildings.begin(); building_it != own_buildings.end(); building_it++){

        if ((*building_it) -> get_name() == building){
            return true;
        }

    }


    return false;


}



player * player :: get_trade_object(string player_name, vector <player * > players){

    vector <player * > :: iterator it;

    for ( it = players.begin(); it != players.end(); it++){

        if ((*it) -> get_name() == player_name){
            return (*it);
        }

    }

}

bool player :: check_num(string a){

    for (int i = 0; i < a.length(); i ++){

        if ((a[i] < '0') || (a[i] > '9')){
            return false;
        }

    }
    return true;

}

bool player :: check_building_can_trade (square * building){

    if (dynamic_cast<square_ownable * > (building) -> check_if_mortgage()) {
        cout << building -> get_name() << " has been mortgaged, cannot be traded" << endl;
        return false;
    }

    if ((building -> get_building_type() == building_type:: residence) || ( building -> get_building_type() == building_type:: gym)){
        return true;
    } else if ((building -> get_building_type() == building_type:: unownable) || ( building -> get_building_type() == building_type:: card)){
        return false;
    } else {

        monopoly * belong = dynamic_cast<academic * > (building) -> get_monopoly();
        vector <academic *> composites = belong ->get_composites();
        vector <academic *> :: iterator it;
        for (it = composites.begin(); it != composites.end(); it++){
            if ((*it) -> get_improvements() > 0){

                cout << "monopoly " << belong ->get_name() << " exists improvements in " << (*it) -> get_name() << endl;
                cout << "trade offer declined" << endl;
                return false;
            }
        }

        return true;

    }

}



void player :: trade(string trade_object, string give_name, string receive_name, vector<string> name_chosen){

    if (trade_object == name){

        cout << get_name() << " cannot trade with yourself" << endl;
        return;
    }

    if (!check_in_namelist(name_chosen, trade_object)) {

        cout << get_name() << " give a wrong player name for the trade, in this game" << endl;
        return;

    }
    player *aim = get_trade_object(trade_object, players);



    if (check_num(give_name) && check_num(receive_name)) {
        cout << "invalid trade offer, " << get_name() <<" cannot trade money for money" << endl;
        cout << "trade declined" << endl;
        return;
    }

    if (!check_num(give_name) && (!check_buliding(give_name))) {
        cout << get_name() << " give a wrong building name to give " << endl;
        cout << give_name << "might not a square name or not owned by you" << endl;
        cout << "trade declined" << endl;
        return;
    }

    if (!check_num(receive_name) && (!::check_buliding(receive_name, aim))) {
        //cout << "you give a wrong building name to give " << players[current_player]->get_name() << endl;
        cout << receive_name << "might not a square name or not owned by "
             << get_name() << endl;
        cout << "trade declined" << endl;
        return;
    }

    if (check_num(give_name) && ::check_buliding(receive_name, aim)) {

        square *building = game_board->get_square(receive_name);
        if (!(check_building_can_trade(building))) {
            return;
        } else {
            cout << "Do you want to accept the deal, " << trade_object << endl;
            string willing;
            string command;
            while (true) {

                cout << R"(If accept, enter "yes". If reject, enter "no" )" << endl;

                getline(cin, command);
                stringstream iss(command);
                iss.exceptions(ios::failbit);
                iss >> willing;

                string buffer;
                try{
                    iss >> buffer;
                    cout << "wrong command" << endl;
                    continue;

                } catch (ios::failure){

                    iss.clear();

                }
                if (willing == "yes") {

                    int i;
                    istringstream(give_name) >> i;
                    if (i <= account){
                        decrease_account(i);
                        aim->increase_account(i);
                        aim->dattach((square_ownable *) building);
                        push_own_buidling((square_ownable *) building);
                        dynamic_cast<square_ownable * >(building)->set_owner(this);

                    } else {
                        cout << name << ", you do not have enough money to offer the trade" << endl;
                    }

                    break;

                } else if (willing == "no") {

                    cout << "the trade is declined by " << trade_object << endl;
                    break;
                } else if (willing == "assets"){
                    aim -> assets();
                    continue;
                } else if (willing == "all"){
                    aim -> all();
                    continue;
                } else {
                    cout << "you enter a wrong command" << endl;
                    continue;
                }
            }
            cout << "trade is finished" << endl;
            return;

        }
    }

    if (check_num(receive_name) && check_buliding(give_name)) {

        square *building = game_board->get_square(give_name);
        if (!(check_building_can_trade(building))) {
            return;
        } else {
            cout << "Do you want to accept the deal, " << trade_object << endl;
            string willing;
            string command;
            while (true) {

                cout << R"(If accept, enter "yes". If reject, enter "no" )" << endl;

                getline(cin, command);
                stringstream iss(command);
                iss.exceptions(ios::failbit);
                iss >> willing;

                string buffer;
                try{
                    iss >> buffer;
                    cout << "wrong command" << endl;
                    continue;

                } catch (ios::failure){

                    iss.clear();

                }

                if (willing == "yes") {

                    int i;
                    istringstream(receive_name) >> i;

                    if ( i <= aim -> get_account()){
                        aim->decrease_account(i);
                        increase_account(i);
                        dattach((square_ownable *) building);
                        aim->push_own_buidling((square_ownable *) building);
                        dynamic_cast<square_ownable * >(building)->set_owner(aim);

                    } else {
                        cout << aim -> get_name() << ", you do not have enough money to accept the trade" << endl;
                        break;
                    }

                    break;

                } else if (willing == "no") {

                    cout << "the trade is declined by " << trade_object << endl;
                    break;
                } else if (willing == "assets"){
                    aim -> assets();
                    continue;
                } else if (willing == "all"){
                    aim -> all();
                    continue;
                } else {
                    cout << "you enter a wrong command" << endl;
                    continue;
                }
            }
            return;

        }

    }

    if (check_buliding(give_name) && ::check_buliding(receive_name, aim)) {

        square *building_give = game_board->get_square(give_name);
        square *building_receive = game_board->get_square(receive_name);
        if ((!check_building_can_trade(building_give)) || (!check_building_can_trade(building_receive))) {
            return;
        } else {
            cout << "Oo you want to accept the deal, " << trade_object << endl;
            string willing;
            string command;
            while (true) {

                cout << R"(If accept, enter "yes". If reject, enter "no" )" << endl;
                getline(cin, command);
                stringstream iss(command);
                iss.exceptions(ios::failbit);
                iss >> willing;

                string buffer;
                try{
                    iss >> buffer;
                    cout << "wrong command" << endl;
                    continue;

                } catch (ios::failure){

                    iss.clear();

                }

                if (willing == "yes") {

                    dattach((square_ownable *) building_give);
                    aim->dattach((square_ownable *) building_receive);


                    push_own_buidling((square_ownable *) building_receive);
                    dynamic_cast<square_ownable * >(building_receive)->set_owner(this);
                    aim->push_own_buidling((square_ownable *) building_give);
                    dynamic_cast<square_ownable * >(building_give)->set_owner(aim);
                    break;

                } else if (willing == "no") {

                    cout << "the trade is declined by " << trade_object << endl;
                    break;
                } else if (willing == "assets"){
                    aim -> assets();
                    continue;
                } else if (willing == "all"){
                    aim -> all();
                    continue;
                } else {
                    cout << "you enter a wrong command" << endl;
                    continue;
                }
            }
            return;

        }
    }

}

void player :: improve(std :: string property, std :: string decision){
    if (!check_buliding(property)){

        cout << "Hi, " << get_name()<< ".The property you want to improve is not your owning or just non-exist of the property, please check" << endl;
        return;

    }

    square *building_to_change = game_board->get_square(property);

    if (building_to_change -> get_building_type() != building_type :: academic){
        cout << "Hi, " << get_name()<< ". Your property is not academic building, you cannot improve it or sell the improvements" << endl;
        return;
    }


    if ((decision != "buy") && (decision != "sell")){
        cout << get_name() << " give the wrong input to improve, please give sell/buy" << endl;
        return;
    }

    if (decision == "buy"){

        monopoly * belong = dynamic_cast<academic * > (building_to_change)-> get_monopoly();
        if (!belong -> check_can_improve(this)){
            cout << get_name() <<" have not met the requirement to buy improvements for " << building_to_change -> get_name() << endl;
            cout <<"you must own all the buildings in the " << belong -> get_name() << endl;
            return;
        }

        if (!belong -> check_equal_improve(dynamic_cast<academic * > (building_to_change))){
            cout << get_name() << " need to balance your improvements for the buildings in the monopoly block " << belong -> get_name() << endl;
            return;
        }

        buy_improve(dynamic_cast<academic * > (building_to_change));

    }

    if (decision == "sell"){

        monopoly * belong = dynamic_cast<academic * > (building_to_change)-> get_monopoly();

        if (!belong -> check_equal_sell(dynamic_cast<academic * > (building_to_change))){
            cout << get_name() << " need to balance your improvements for the buildings in the monopoly block " << belong -> get_name() << endl;
            return;
        }

        sell_improve(dynamic_cast<academic * > (building_to_change));

    }

}


void player :: raise_money(vector<string> name_chosen){

    cout << get_name() << " need to raise enough money to pay for the money owned" << endl;

    while (account < money_owned){

        if (check_all_mortgaged()) {
            set_bankrupt();
            return;
        }

        cout << "you can mortgage the your buildings by issuing \"mortgage <property>\"" << endl;

        cout << "or you can sell your improvements of academic buildings by issing \"improve <property> sell\"" << endl;
        cout << "or you can trade by issing \"trade <name> <give> <receive>\"" << endl;

        string command;
        getline(cin, command);
        istringstream iss_1(command);
        iss_1.exceptions(ios::failbit);
        string action;
        iss_1 >> action;

        if (action == "improve"){
            string property;
            string decision;

            iss_1 >> property;
            iss_1 >> decision;

            string buffer;
            try{
                iss_1 >> buffer;
                cout << get_name() << ", you give a wrong command" << endl;
                continue;
            } catch (ios :: failure){

                iss_1.clear();

            }

            if (!check_buliding(property)){

                cout << "Hi, " << get_name()<< ".The property you want to improve is not your owning or just non-exist of the property, please check" << endl;
                continue;

            }

            square *building_to_change = game_board->get_square(property);

            if (building_to_change -> get_building_type() != building_type :: academic){
                cout << "Hi, " << get_name()<< ". Your property is not academic building, you cannot improve it or sell the improvements" << endl;
                continue;
            }


            if ((decision != "sell")){
                cout << get_name() << " give the wrong input to improve, please give sell" << endl;
                continue;
            }

            monopoly * belong = dynamic_cast<academic * > (building_to_change)-> get_monopoly();

            if (!belong -> check_equal_sell(dynamic_cast<academic * > (building_to_change))){
                cout << get_name() << " need to balance your improvements for the buildings in the monopoly block " << belong -> get_name() << endl;
                continue;
            }

            sell_improve(dynamic_cast<academic * > (building_to_change));


        } else if (action == "mortgage") {

            string property;
            iss_1 >> property;
            string buffer;
            try{
                iss_1 >> buffer;
                cout << get_name() << ", you give a wrong command" << endl;
                continue;
            } catch (ios :: failure){

                iss_1.clear();

            }
            mortgage(property);

        } else if (action == "trade"){
            string trade_object;
            string give_name;
            string receive_name;

            iss_1 >> trade_object;
            iss_1 >> give_name;
            iss_1 >> receive_name;

            string buffer;
            try{
                iss_1 >> buffer;
                cout << get_name() << ", you give a wrong command" << endl;
                continue;
            } catch (ios :: failure){

                iss_1.clear();

            }
            trade(trade_object, give_name, receive_name, name_chosen);
        }

        else if (action == "assets") {
            string buffer;
            try{
                iss_1 >> buffer;
                cout << get_name() << ", you give a wrong command" << endl;
                continue;
            } catch (ios :: failure){

                iss_1.clear();

            }
            assets();
        } else if (action == "all") {
            string buffer;
            try{
                iss_1 >> buffer;
                cout << get_name() << ", you give a wrong command" << endl;
                continue;
            } catch (ios :: failure){

                iss_1.clear();

            }
            all();
        } else {
            cout <<"you give a wrong command, please try another one" << endl;
        }


    }

    decrease_account(money_owned);
    player_owned -> increase_account(money_owned);
    money_owned = 0;
    player_owned = nullptr;

}

void player :: transfer_assets (vector<string> name_chosen){


    vector <square_ownable *> :: iterator it;
    vector <square_ownable *> to_transfer;
    to_transfer = own_buildings;
    for (it = to_transfer.begin(); it != to_transfer.end(); it++) {

        int bill = (*it)->get_price() * 0.1;
        if (bill > player_owned->get_account()) {

            player_owned->set_money_owned(bill);
            player_owned->set_player_owned(bank);
            player_owned->raise_money(name_chosen);

        }
        (*it) -> set_owner(player_owned);
        player_owned -> push_own_buidling((*it));
        dattach_own_building(dynamic_cast<square_ownable * >(*it));
        string command;
        while (true) {
            cout << player_owned->get_name() << ", if you choose unmortgage " << (*it)->get_name() << " issue \"unmortgage\"" << endl;
            cout << "or you could issue \"nothing\" to choose to unmortgage them in the future" << endl;
            cout << "if you donot have enough money to unmortgage, you can trade or sell improvements" << endl;

            getline(cin, command);
            istringstream iss_1(command);
            iss_1.exceptions(ios::failbit);
            string action;
            iss_1 >> action;

            if ((action != "unmortgage") && (action != "nothing") && (action != "trade") && (action != "improve")&& (action != "assets")&& (action != "all")) {
                cout << name << " you give a wrong command" << endl;
                continue;
            }

            if (action == "unmortgage") {
                string buffer;
                try{
                    iss_1 >> buffer;
                    cout << "wrong unmotgage command" << endl;
                    continue;

                } catch (ios::failure){

                    iss_1.clear();

                }
                player_owned -> set_in_transfer(1);
                player_owned->unmortgage((*it)->get_name());
                if (player_owned -> get_in_transfer() == 0) {
                    break;
                } else {
                    player_owned -> set_in_transfer(0);
                    continue;
                }
            } else if (action == "trade") {
                string trade_object;
                string give_name;
                string receive_name;

                iss_1 >> trade_object;
                iss_1 >> give_name;
                iss_1 >> receive_name;

                string buffer;
                try{
                    iss_1 >> buffer;
                    cout << "wrong trade command" << endl;
                    continue;

                } catch (ios::failure){

                    iss_1.clear();

                }

                player_owned->trade(trade_object, give_name, receive_name, name_chosen);

            } else if (action == "improve") {
                string property;
                string decision;

                try{
                    iss_1 >> property;


                } catch (ios::failure){

                    cout << "wrong imrpove command" << endl;
                    continue;

                }

                try{
                    iss_1 >> decision;


                } catch (ios::failure){

                    cout << "wrong improve command" << endl;
                    continue;

                }
                string buffer;
                try{
                    iss_1 >> buffer;
                    cout << "wrong improve command" << endl;
                    continue;

                } catch (ios::failure){

                    iss_1.clear();

                }

                if (decision == "buy"){
                    cout << name << " , you can not buy improvements at this time" << endl;
                }
                player_owned->improve(property, decision);

            } else if (action == "assets"){
                try{
                    iss_1 >> action;
                    cout << "wrong assets command" << endl;
                    continue;

                } catch (ios::failure){

                    iss_1.clear();

                }
                player_owned->assets();
            } else if (action == "all"){
                if (!iss_1.eof()){
                    cout << "wrong command" << endl;
                    iss_1.ignore(INT_MAX);
                    continue;
                }
                all();
            } else if (action == "nothing") {
                try{
                    iss_1 >> action;
                    cout << "wrong all command" << endl;
                    continue;

                } catch (ios::failure){

                    iss_1.clear();

                }
                break;
            }

        }

    }

}

void player :: assets(){

    cout << name << ", you own " << get_account() << "$ " << endl;
    vector <square_ownable *> :: iterator it;
    for (it = own_buildings.begin(); it != own_buildings.end(); it++){

//        if ((it) == own_buildings.begin()) {
//
//            if ((*it) -> get_building_type() == building_type :: academic){
//                cout << name << " own the following building: " << (*it) -> get_name() << " with " << dynamic_cast<academic * > (*it) -> get_improvements() << " improvements ";
//            } else {
//                cout << name << " own the following building: " << (*it) -> get_name() <<" ";
//            }
//
//            continue;
//        }
//
//        if ((it) == (own_buildings.end() - 1)) {
//
//            if ((*it) -> get_building_type() == building_type :: academic){
//                cout << (*it) -> get_name() << " with " << dynamic_cast<academic * > (*it) -> get_improvements() << " improvements ";
//            } else {
//                cout << (*it) -> get_name() <<" ";
//            }
//            break;
//
//        }

        if ((*it) -> get_building_type() == building_type :: academic){

            if ((*it) -> check_if_mortgage()){
                cout << name << ", you own "<< (*it) -> get_name() << " mortgaged "  << " in "<< dynamic_cast<academic * > (*it) -> get_monopoly_name() << " monopoly"<< endl;
            } else {
                cout << name << ", you own "<< (*it) -> get_name() << " with " << dynamic_cast<academic * > (*it) -> get_improvements() << " improvements " << " in "<< dynamic_cast<academic * > (*it) -> get_monopoly_name() << " monopoly"<< endl;
            }

        } else if  ((*it) -> get_building_type() == building_type :: residence){

            if ((*it) -> check_if_mortgage()){
                cout << name << ", you own "<< (*it) -> get_name() << " mortgaged " << " in residence " <<endl;
            } else {
                cout << name << ", you own "<< (*it) -> get_name() << " in residence " << endl;
            }

        } else {
            if ((*it) -> check_if_mortgage()){
                cout << name << ", you own "<< (*it) -> get_name() << " mortgaged " << " in gym " <<endl;
            } else {
                cout << name << ", you own "<< (*it) -> get_name() << " in gym " << endl;
            }
        }


    }

}

void player :: all(){

    vector <player *> :: iterator it;

    for (it = players.begin(); it != players.end(); it++){

        (*it) -> assets();

        if ((it) != (players.end() - 1)){
            cout << endl;
        }

    }

}

void player :: save (ofstream & out){

    vector <player *> :: iterator it;

    int num_players = players.size();

    std :: vector <player * > players_to_save;
    string name_locate = name;
    int count = 0;
    while (count != num_players){

        for (it = players.begin(); it != players.end(); it++){

            if ( (*it) -> get_name() == name_locate) {

                players_to_save.push_back((*it));
                it ++;
                count ++;
                if (it == players.end()){

                    it = players.begin();
                    name_locate = (*it) -> get_name();
                    break;
                }
                name_locate = (*it) -> get_name();
                break;

            }

        }

    }

    for (it = players_to_save.begin(); it != players_to_save.end(); it++){

        if ((*it) -> get_index() == 10){

            if ((*it) -> get_if_in_dc_tims_line() == 0){
                out << (*it) -> get_name() << " " << (*it) -> get_representation() << " " << (*it) -> get_Roll_Up_the_Rim_Cup() << " "
                << (*it) -> get_account() << " " << (*it) -> get_index() << " " << (*it) -> get_if_in_dc_tims_line() <<endl;
            } else {
                out << (*it) -> get_name() << " " << (*it) -> get_representation() << " " << (*it) -> get_Roll_Up_the_Rim_Cup() << " "
                << (*it) -> get_account() << " " << (*it) -> get_index() << " " << (*it) -> get_if_in_dc_tims_line() << " " << (*it) -> get_in_dc_tims_line() << endl;
            }

            continue;
        }

        out << (*it) -> get_name() << " " << (*it) -> get_representation() << " " << (*it) -> get_Roll_Up_the_Rim_Cup() << " " << (*it) -> get_account() << " " << (*it) -> get_index() << endl;


    }

    vector <square *> my_board = game_board -> get_game_board();

    for (int square_index = 0; square_index < 40; square_index++){
        square * this_square = game_board -> get_square(square_index);
        if ((this_square -> get_building_type() == building_type :: residence) || (this_square -> get_building_type() == building_type :: gym)){

            if (dynamic_cast<square_ownable * > (this_square) -> check_if_mortgage()){
                out << this_square -> get_name() << " " << dynamic_cast<square_ownable * > (this_square) -> get_owner_name() << " " << -1 << endl;
                continue;
            }

            out << this_square -> get_name() << " " << dynamic_cast<square_ownable * > (this_square) -> get_owner_name() << " " << 0 << endl;
            continue;
        }
        if (this_square -> get_index() == square_index){

            if (this_square -> get_building_type() == building_type :: academic) {

                if (dynamic_cast<academic * > (this_square) -> check_if_mortgage()){
                    out << this_square -> get_name() << " " << dynamic_cast<academic * > (this_square) -> get_owner_name() << " " << -1 << endl;
                    continue;
                }

                out << this_square -> get_name() << " " << dynamic_cast<academic * > (this_square) -> get_owner_name() << " " << dynamic_cast<academic * > (this_square) -> get_improvements() << endl;
                continue;
            }

        }

    }


}

int player :: get_back_flag(){
    return back_flage;
}
void player :: set_back_flage(int i){

    back_flage = i;

}

void player :: set_in_transfer(int i){
    in_transfer = i;
}

int player :: get_in_transfer(){
    return in_transfer;
}


player :: ~player() {

    own_buildings.clear();

}