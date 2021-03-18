#include <iostream>
#include <vector>
#include "player.h"
#include "board.h"
#include <sstream>
#include <fstream>
#include "square_ownable.h"
#include "academic.h"

using namespace std;

bool check_chosen (vector <string > name_chosen, string name){
    vector<string> :: iterator it ;
    for (it = name_chosen.begin(); it != name_chosen.end(); it ++){

        if (name == *it){
            return true;
        }

    }

    return false;
}

bool check_right_representation(string name, char representation){
    if ((name == "Goose") && (representation == 'G')) {

        return true;

    }

    if ((name == "GRT_Bus") && (representation == 'B')){

        return true;

    }

    if ((name == "Tim_Hortons_Doughnut") && (representation == 'D')){

        return true;

    }

    if ((name == "Professor") && (representation == 'P')){

        return true;

    }

    if ((name == "Student") && (representation == 'S')){

        return true;

    }

    if ((name == "Money") && (representation == '$')){

        return true;

    }

    if ((name == "Laptop") && (representation == 'L')){

        return true;

    }

    if ((name == "Pink_tie") && (representation == 'T')){

        return true;

    }

    return false;
}

player * get_player(const string & name, vector<player *> players, player * bank){

    vector<player *> :: iterator it;
    for (it = players.begin(); it != players.end(); it++){

        if ((*it) -> get_name() == name){
            return (*it);
        }

    }

    return bank;
}


//bool check_buliding(string building, player * owner){
//
//    vector <square_ownable *> own_buildings = owner -> get_own_buildings();
//    vector <square_ownable *> :: iterator building_it;
//
//    for (building_it = own_buildings.begin(); building_it != own_buildings.end(); building_it++){
//
//        if ((*building_it) -> get_name() == building){
//            return true;
//        }
//
//    }
//    return false;
//
//
//}


int main( int argc, char *argv[]) {

    int num_player;
    vector<player *> players;
    player *bank = new player();
    string name;
    char representation;
    int TimCups;
    int money;
    int position;
    board *my_board = new board(bank);

    vector<player *>::iterator it_players;
    vector<string> name_chosen;
    vector<square *> game_board = my_board->get_game_board();
    vector<square *>::iterator it;

    int reload = 0;
    for (it = game_board.begin(); it != game_board.end(); it++) {
        (*it)->set_game_board(my_board);
    }

    stringstream ss_command_line;
    if (argc != 1){

        string command;
        ss_command_line << argv[1];
        ss_command_line >> command;
        cout << "command: " << command << endl;
        if (command == "-load"){

            if (argc != 3){
                cerr << "wrong command line, you should issue -load file" << endl;
            }

            string file;
            stringstream ss_command_file;
            ss_command_file << argv[2];
            ss_command_file >> file;
            cout << "file: " << file << endl;
            ifstream in( file );
            in.exceptions(ios::failbit);
            in >> num_player;
            cout << "num_player: " << num_player << endl;
            for(int i = 0; i < num_player; i++){
                in >> name;
                in >> representation;
                in >> TimCups;
                in >> money;
                in >> position;

                cout << name << endl;
                cout << representation << endl;
                cout << TimCups << endl;

                cout << money << endl;
                cout << position << endl;

                player *new_player = new player(name, representation, bank, position, my_board);
                new_player -> set_account(money);
                new_player -> set_Roll_Up_the_Rim_Cup(TimCups);

                if (position == 10){
                    int if_in_dc_tims_line;
                    in >> if_in_dc_tims_line;
                    new_player -> set_if_in_dc_tims_line(if_in_dc_tims_line);
                    if (new_player -> get_if_in_dc_tims_line()){

                        int in_dc_tims_line;
                        in >> in_dc_tims_line;
                        new_player -> set_in_dc_tims_line(in_dc_tims_line);

                    }
                }

                players.push_back(new_player);
                square * which_in = my_board -> get_square(position);
                which_in -> push_back(new_player);

            }

            int Roll_Up_the_Rim_Cup_Sent_total = 0;
            for(it_players = players.begin(); it_players != players.end(); it_players++) {

                (*it_players) -> set_players(players);
                if ((*it_players) -> get_Roll_Up_the_Rim_Cup() != 0){
                    Roll_Up_the_Rim_Cup_Sent_total += (*it_players) -> get_Roll_Up_the_Rim_Cup();
                }

            }
            player :: set_Roll_Up_the_Rim_Cup_Sent(Roll_Up_the_Rim_Cup_Sent_total);
            bank -> set_players(players);
            string square_name;
            string owner_name;
            int improvements;
            //cout << "i am here" << endl;
            while (true){
                try{
                    in >> square_name;
                } catch (ios :: failure){
                    in.clear();
                    break;
                }
                in >> owner_name;
                in >> improvements;

                cout << square_name << endl;
                cout << owner_name << endl;
                cout << improvements << endl;

                square * this_square = my_board -> get_square(square_name);

                player * owner = get_player(owner_name, players,bank);

                if ((this_square -> get_building_type() == building_type :: residence) || (this_square -> get_building_type() == building_type :: gym)){

                    dynamic_cast<square_ownable * > (this_square) -> set_owner(owner);
                    if (improvements == -1){
                        dynamic_cast<square_ownable * > (this_square) -> set_mortgage_flag();
                    }
                    owner -> push_own_buidling(dynamic_cast<square_ownable * > (this_square));
                    continue;

                }


                else if (this_square -> get_building_type() == building_type :: academic){

                    dynamic_cast<square_ownable * > (this_square) -> set_owner(owner);
                    if (improvements == -1){
                        dynamic_cast<square_ownable * > (this_square) -> set_mortgage_flag();
                    } else if (improvements > 0){

                        for (int i = 0; i < improvements; i++){
                            dynamic_cast<academic * > (this_square) -> improve();
                        }

                    }
                    owner -> push_own_buidling(dynamic_cast<square_ownable * > (this_square));
                    continue;

                } else {

                }

            }
            my_board -> draw();
            reload = 1;

        } else if (command == "-testing"){
            srand (time(NULL));
            if (argc > 4){
                cerr << "wrong test command" << endl;
            }

            player *new_player = new player("Testing", 'A', bank, 0, my_board);
            players.push_back(new_player);
            square * osap = my_board -> get_square(0);
            osap -> push_back(new_player);
            bank->set_players(players);
            stringstream ss_test;
            //ss_test.exceptions(ios::failbit);

            //cout << "you can issue quit to quit the testing mode" << endl;
            if (argc == 2){

                int dice_1 = new_player -> roll_dice();
                int dice_2 = new_player -> roll_dice();
                new_player -> move(dice_1 , dice_2);
                new_player -> assets();
                return 0 ;

            } else if (argc == 3){
                int dice_1;

                ss_test << argv[2];
                ss_test >> dice_1;
                int dice_2 = new_player -> roll_dice();
                new_player -> move(dice_1 , dice_2);
                new_player -> assets();
                return 0;

            } else {

                int dice_1 = stoi(argv[2]);
                int dice_2 = stoi(argv[3]);;

//                ss_test << argv[2];
//                ss_test >> dice_1;
//
//                ss_test << argv[3];
//                ss_test >> dice_2;
//                cout << "dice_1: " << dice_1 << endl;
//                cout << "dice_2: " << dice_2 << endl;
                new_player -> move(dice_1 , dice_2);
                new_player -> assets();
                return 0;

            }

        }

    } else {


        vector<string> name_list = {"Goose", "GRT_Bus", "Tim_Hortons_Doughnut", "Professor", "Student", "Money", "Laptop", "Pink_tie"};
        vector<char> representation_player;


        while (true){
            cout << "enter the number of players, followed by the name of each player and the character that will represent the player on the board." << endl;
            string initial_command;
            getline(cin, initial_command);
            istringstream iss(initial_command);
            iss.exceptions(ios::failbit);

            try {
                iss >> num_player;

            } catch (ios::failure) {
                iss.clear();
                cout << "wrong input for number of player" << endl;
                continue;
            }

            if (num_player > 9){
                cout << "the max number of players is 9" << endl;
                continue;
            }


            while (true) {
                //cout << "in" << endl;
                for (int count = 0; count < num_player; count++) {

                    iss >> name;
                    cout << name << endl;

                    if (!check_in_namelist(name_list, name)) {

                        cout << "wrong name for player or wrong initial command, please check" << endl;
                        iss.clear();
                        name_chosen.clear();
                        representation_player.clear();
                        break;
                    }
                    if (check_chosen(name_chosen, name)) {
                        cout << name <<" has been chosen, please choose another one" << endl;
                        iss.clear();
                        name_chosen.clear();
                        representation_player.clear();
                        break;
                    }
                    name_chosen.push_back(name);

                    try {
                        iss >> representation;
                    } catch (ios::failure) {
                        iss.clear();
                        name_chosen.clear();
                        representation_player.clear();
                        cout << "wrong initial command" << endl;
                        break;
                    }

                    if (!check_right_representation(name, representation)) {
                        cout << "wrong representation for the player, please check true one" << endl;
                        iss.clear();
                        name_chosen.clear();
                        representation_player.clear();
                        break;
                    }
                    representation_player.push_back(representation);
                }

                break;

            }

            try{
                iss >> name;
                cout << name << endl;
                //iss.ignore(INT_MAX);
                cout << "wrong command" << endl;
                name_chosen.clear();
                representation_player.clear();
                continue;

            } catch (ios::failure){

                iss.clear();

            }


//
//            if (iss.fail()){
//
//                if (!iss.eof()){
//                    cout << "wrong command" << endl;
//                    iss.ignore(INT_MAX);
//                    continue;
//                }
//                //cout << "in" << endl;
//            }

            if ((name_chosen.size() == num_player) && (representation_player.size() == num_player)){

                for(int i = 0; i < num_player; i++){

                    player *new_player = new player(name_chosen[i], representation_player[i], bank, 0, my_board);
                    players.push_back(new_player);

                }

                square * osap = my_board -> get_square(0);


                for (it_players = players.begin(); it_players != players.end(); it_players++) {
                    (*it_players)->set_players(players);
                    osap -> push_back((*it_players));

                }
                my_board->draw();
                bank->set_players(players);

                break;
            }

        }



    }

    //vector<square_ownable *>::iterator builidng_it;
    string command;
    int current_player = 0;
    int roll_flag = 0;
    while (true) {
        srand (time(NULL));
        if (players.size() == 1){
            cout << "congraduation, "<< players[0] -> get_name() << " win the game" << endl;
            delete my_board;

            for (it_players = players.begin(); it_players != players.end(); it_players++) {
                delete (*it_players);
            }
            break;

        }

        cout << players[current_player]->get_name() << ", please issue command" << endl;

        if ((players[current_player] -> get_bankrupt() > 0)){

            cout<< R"("bankrupt" or "assets" or "all" or "save <filename>")" << endl;

        }

        if ((players[current_player] -> get_if_in_dc_tims_line() == 1) && (roll_flag  == 0)){
            if ((reload != 1)){
                players[current_player]->move(0,0);
            } else {
                reload = 0;
            }

            roll_flag = 1;
        }
        reload = 0;
        if (players[current_player] -> get_money_owned() > 0){

            if (players[current_player] -> get_bankrupt() == 0){
                players[current_player] -> raise_money(name_chosen);
                continue;
            }

        } else {

            if (roll_flag == 0){
                cout<< R"("roll" or "next" or "trade <name> <give> <receive>" or "improve <property> buy/sell" or "mortgage <property>" or "unmortgage <property>" or "bankrupt" or "assets" or "all" or "save <filename>")" << endl;
            } else {
                cout<< R"("next" or "trade <name> <give> <receive>" or "improve <property> buy/sell" or "mortgage <property>" or "unmortgage <property>" or "bankrupt" or "assets" or "all" or "save <filename>")" << endl;
            }

        }


        getline(cin, command);
        istringstream iss_1(command);
        iss_1.exceptions(ios::failbit);
        string action;
        iss_1 >> action;
        if (action == "roll") {

            try{
                iss_1 >> action;
                cout << "wrong roll command" << endl;
                continue;

            } catch (ios::failure){

                iss_1.clear();

            }

            if (players[current_player] -> get_bankrupt() == 1){
                cout << players[current_player] -> get_name()<<", you must declare bankrupt" << endl;
                continue;
            }

            if (roll_flag == 0) {

                int count = 0;
                int dice_1;
                int dice_2;
                while(true){

                    dice_1 = players[current_player]->roll_dice();
                    dice_2 = players[current_player]->roll_dice();
                    if (dice_1 == dice_2){
                        cout << players[current_player] -> get_name()<<" roll doubles which is " << dice_1 << endl;
                        cout << "please roll again" << endl;
                        count++;
                        if (count == 3){
                            int index = players[current_player] -> get_index();
                            players[current_player] -> set_three_doubles();
                            players[current_player]->move((10 - index), 0);
                            //players[current_player] -> set_if_in_dc_tims_line(1);
                            roll_flag = 1;
                            break;
                        }

                        continue;
                    }
                    break;
                }

                if (players[current_player] -> get_three_doubles() == 1){
                    continue;
                }

                players[current_player]->move(dice_1 , dice_2);
                roll_flag = 1;
                continue;
            } else {

                cout << players[current_player]->get_name() << " have rolled the dice, please try another command" << endl;
                continue;

            }


        } else if (action == "next") {

            if (roll_flag == 0){
                cout << "you cannot issue next without moving" << endl;
                continue;
            }

            try{
                iss_1 >> action;
                cout << "wrong next command" << endl;
                continue;

            } catch (ios::failure){

                iss_1.clear();

            }

            if (players[current_player] -> get_bankrupt() == 1){
                cout << players[current_player] -> get_name()<<"you must declare bankrupt" << endl;
                continue;
            }

            roll_flag = 0;
            current_player++;
            if (current_player == num_player) {
                current_player = 0;
            }
            cout << "now, it is " << players[current_player]->get_name() << "'s turn" << endl;
            continue;

        } else if (action == "trade") {

            string trade_object;
            string give_name;
            string receive_name;

            try{
                iss_1 >> trade_object;


            } catch (ios::failure){

                cout << "wrong roll command" << endl;
                continue;

            }

            try{
                iss_1 >> give_name;


            } catch (ios::failure){

                cout << "wrong roll command" << endl;
                continue;

            }

            try{
                iss_1 >> receive_name;


            } catch (ios::failure){

                cout << "wrong roll command" << endl;
                continue;

            }



            try{
                iss_1 >> action;
                cout << "wrong trade command" << endl;
                continue;

            } catch (ios::failure){

                iss_1.clear();

            }

            if (players[current_player] -> get_bankrupt() == 1){
                cout << players[current_player] -> get_name()<<"you must declare bankrupt" << endl;
                continue;
            }


            players[current_player] -> trade(trade_object, give_name, receive_name, name_chosen);
            continue;

        } else if (action == "improve") {

            string property;
            string decision;

            try{
                iss_1 >> property;


            } catch (ios::failure){

                cout << "wrong improve command" << endl;
                continue;

            }

            try{
                iss_1 >> decision;


            } catch (ios::failure){

                cout << "wrong improve command" << endl;
                continue;

            }

            try{
                iss_1 >> action;
                cout << "wrong improve command" << endl;
                continue;

            } catch (ios::failure){

                iss_1.clear();

            }

            if (players[current_player] -> get_bankrupt() == 1){
                cout << players[current_player] -> get_name()<<"you must declare bankrupt" << endl;
                continue;
            }


            players[current_player] -> improve(property, decision);
            continue;

        } else if (action == "mortgage") {
            string property;

            iss_1 >> property;
            try{
                iss_1 >> action;
                cout << "wrong mortgage command" << endl;
                continue;

            } catch (ios::failure){

                iss_1.clear();

            }

            if (players[current_player] -> get_bankrupt() == 1){
                cout << players[current_player] -> get_name()<<"you must declare bankrupt" << endl;
                continue;
            }

            //cout << "in" << endl;
            players[current_player] -> mortgage(property);
            continue;

        } else if (action == "unmortgage") {

            string property;
            iss_1 >> property;
            try{
                iss_1 >> action;
                cout << "wrong unmortgage command" << endl;
                continue;

            } catch (ios::failure){

                iss_1.clear();

            }

            if (players[current_player] -> get_bankrupt() == 1){
                cout << players[current_player] -> get_name()<<"you must declare bankrupt" << endl;
                continue;
            }

            players[current_player] -> unmortgage(property);
            continue;

        } else if (action == "bankrupt") {
            roll_flag = 0;
            try{
                iss_1 >> action;
                cout << "wrong bankbrupt command" << endl;
                continue;

            } catch (ios::failure){

                iss_1.clear();

            }

            if (players[current_player] -> get_bankrupt() == 0){
                cout << players[current_player] -> get_name()<<", you cannot declare bankrupt" << endl;
                continue;
            }

            if (players[current_player] -> get_player_owned() != bank){

                int money_to_give = players[current_player] -> get_account();
                players[current_player] -> decrease_account(money_to_give);
                players[current_player] -> get_player_owned() -> increase_account(money_to_give);
                players[current_player] -> transfer_assets(name_chosen);

            } else {

                int money_to_give = players[current_player] -> get_account();
                players[current_player] -> decrease_account(money_to_give);
                players[current_player] -> get_player_owned() -> increase_account(money_to_give);

                vector <square_ownable *> :: iterator it_own_building;
                vector <square_ownable *> own_buildings = players[current_player] -> get_own_buildings();

                for (it_own_building = own_buildings.begin(); it_own_building != own_buildings.end(); it_own_building++){

                    (*it_own_building) -> set_mortgage_flag();
                    cout << "now auction the " << (*it_own_building) -> get_name() << endl;
                    bank -> auction(*it_own_building);
                    players[current_player] -> dattach_own_building(dynamic_cast<square_ownable * >(*it_own_building));

                }


                for (it_players = players.begin(); it_players != players.end(); it_players++){

                    if ((*it_players) -> get_Roll_Up_the_Rim_Cup() != 0){
                        (*it_players) -> set_Roll_Up_the_Rim_Cup(0);
                    }

                }
                player:: set_Roll_Up_the_Rim_Cup_Sent(0);
                cout << "all Roll_Up_the_Rim_Cups have been destroyed" << endl;
            }

            square * current_square = my_board -> get_square(players[current_player] -> get_index());

            current_square -> dattach(players[current_player]);

            vector<player *> :: iterator it_bankrupt;
            for (it_bankrupt = players.begin(); it_bankrupt != players.end(); it_bankrupt++){

                if ((*it_bankrupt) -> get_name() == players[current_player] -> get_name()){

                    player * to_delete = (*it_bankrupt);
                    players.erase(it_bankrupt);
                    delete to_delete;
                    break;
                }

            }
            num_player --;
            //update the players vector in the player class
            for (it_bankrupt = players.begin(); it_bankrupt != players.end(); it_bankrupt++){

                (*it_bankrupt) -> set_players(players);

            }

            continue;
        } else if (action == "assets"){
            try{
                iss_1 >> action;
                cout << "wrong assets command" << endl;
                continue;

            } catch (ios::failure){

                iss_1.clear();

            }
            players[current_player] -> assets();
            cout << endl;
            continue;

        } else if (action == "all"){

            try{
                iss_1 >> action;
                cout << "wrong all command" << endl;
                continue;

            } catch (ios::failure){

                iss_1.clear();

            }
            players[current_player] -> all();
            cout << endl;
            continue;

        } else if (action == "save"){

            if (roll_flag == 1){
                cout << "you cannot save file after rolling dices" << endl;
                continue;
            }

            string filename;
            //getline(iss_1, filename);


            try {
                iss_1 >> filename;


            } catch (ios :: failure){

                cout << players[current_player] -> get_name() << ", you should give a file name" << endl;

                iss_1.clear();
                continue;

            }

            string buffer;

            try {
                iss_1 >> buffer;
                cout << players[current_player] -> get_name() << ", you give a wrong save command" << endl;
                continue;

            } catch (ios :: failure){

                iss_1.clear();

            }


            ofstream out(filename);
            out << num_player << '\n';
            players[current_player] -> save(out);
            cout << "you successfully save the game" << endl;
            delete my_board;

            for (it_players = players.begin(); it_players != players.end(); it_players++) {
                delete (*it_players);
            }

        } else{
            cout << players[current_player]->get_name() << " give a wrong command" << endl;
            continue;
        }
        return 0;
    }
}