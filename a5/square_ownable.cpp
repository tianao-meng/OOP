//
// Created by 孟天奥 on 2020-10-27.
//
#include "square_ownable.h"
#include <iostream>
#include "player.h"
#include <sstream>
using namespace std;

square_ownable :: square_ownable (int index, int payment, int price, string representation, player * owner, string name, building_type type):
                                square(index, representation, type, name), owner(owner), payment(payment), price(price){

}


std :: string square_ownable :: get_owner_name() {

    return owner -> get_name();
}

int square_ownable :: get_payment(){

    return payment;
}

int square_ownable :: get_price(){
    return price;

}

void square_ownable :: set_payment(int a){

    payment = a;
}

void square_ownable :: punish(player * punished){
    cout << punished -> get_name() << " arrived " << get_name() << ", which is owned by "<< get_owner_name() << endl;
    building_type type = get_building_type();

    if (type == building_type :: gym) {
        //cout << punished -> get_name() << ", you are in " << get_name() << endl;
        cout << "please roll dice two times to decide the punished money" << endl;
        string roll;
        string command;
        int dice_1;
        int dice_2;
        while (true){
            getline(cin, command);
            istringstream iss_roll_1(command);
            iss_roll_1.exceptions(ios::failbit);
            iss_roll_1 >> roll;

            if (roll != "roll") {
                cout << punished->get_name() << ", you give a wrong command" << endl;
                continue;
            } else {

                string buffer;
                try{
                    iss_roll_1 >> buffer;
                    cout << punished->get_name() << ", you give a wrong command" << endl;
                    continue;
                } catch (ios :: failure){

                    iss_roll_1.clear();

                }
                dice_1 = punished->roll_dice();
                cout << punished->get_name() << " roll " << dice_1 << endl;
                break;
            }
        }
        while (true){
            getline(cin, command);
            istringstream iss_roll_2(command);
            iss_roll_2.exceptions(ios::failbit);
            iss_roll_2 >> roll;

            if (roll != "roll") {
                cout << punished->get_name() << ", you give a wrong command" << endl;
                continue;
            } else {

                string buffer;
                try{
                    iss_roll_2 >> buffer;
                    cout << punished->get_name() << ", you give a wrong command" << endl;
                    continue;
                } catch (ios :: failure){

                    iss_roll_2.clear();

                }

                dice_2 = punished->roll_dice();
                cout << punished->get_name() << " roll " << dice_2 << endl;
                break;
            }
        }

        int times = 0;
        board * game_board = get_game_board();
        vector <square *> game_board_square = game_board -> get_game_board();
        vector <square *> :: iterator it;
        int count = 0;
        for (it = game_board_square.begin(); it != game_board_square.end(); it ++){

            if (((*it) -> get_building_type() == building_type :: gym) && (dynamic_cast<square_ownable * >(*it) -> get_owner_name() != "Bank")){

                if (dynamic_cast<square_ownable * >(*it) -> get_owner_name() == get_owner_name()){

                    if (!dynamic_cast<square_ownable * >(*it) -> check_if_mortgage()){
                        count ++;
                    } else {
                        cout << dynamic_cast<square_ownable * >(*it) -> get_name() << " has been mortgaged, will not count that" << endl;
                    }

                }

            }

        }
        cout << "The owner of "<< get_name() <<  " " <<get_owner_name() << " has " << count << " gyms" << endl;
        if (count == 1){
            times = 4;
        }

        if (count == 2){
            times = 10;
        }

        int bill = times * (dice_1 + dice_2);

        if (!check_enough_to_pay(bill, punished, owner)){
            return;
        }

        owner -> increase_account(bill);
        punished -> decrease_account(bill);
        return;

    }

    if (type == building_type :: residence) {

        //cout << punished -> get_name() << ", you are in " << get_name() << endl;
//        board * game_board = get_game_board();
//        vector <square *> game_board_square = game_board -> get_game_board();
        vector <square_ownable *> own_building = owner -> get_own_buildings();
        vector <square_ownable *> :: iterator it;
        int count = 0;
        for (it = own_building.begin(); it != own_building.end(); it ++){

            if ((*it) -> get_building_type()  == building_type :: residence){
                if (!dynamic_cast<square_ownable * >(*it) -> check_if_mortgage()){
                    count ++;
                } else {
                    cout << dynamic_cast<square_ownable * >(*it) -> get_name() << " has been mortgaged, will not count that" << endl;
                }
            }
//            if ((dynamic_cast<square_ownable * >(*it) -> get_owner_name() != "Bank") && (get_owner_name() != "Bank") && (dynamic_cast<square_ownable * >(*it) -> get_owner_name() == get_owner_name())){
//                count += 1;
//            }


        }
        cout << "The owner of "<< get_name() << " " << get_owner_name() << " has " << count << " residences" << endl;
        int bill = 0;
        if (count == 1){
            bill = 25;
        }

        if (count == 2){
            bill = 50;
        }

        if (count == 3){
            bill = 100;
        }

        if (count == 4){
            bill = 200;
        }
        if (!check_enough_to_pay(bill, punished, owner)){
            return;
        }
        owner -> increase_account(bill);
        punished -> decrease_account(bill);
        return;


    }
    int bill = get_payment();
    if (!check_enough_to_pay(bill, punished, owner)){
        return;
    }
    owner -> increase_account(bill);
    punished -> decrease_account(bill);
}

void square_ownable :: set_owner(player * buyer){

    cout << "The " << get_name() << " is now owned by " << buyer ->get_name() << endl;
    owner = buyer;
}

player * square_ownable :: get_owner(){
    return owner;
}

bool square_ownable :: check_if_mortgage(){
    return mortgage_flag != 0;
}

void square_ownable :: set_mortgage_flag(){

    if (mortgage_flag == 0){
        mortgage_flag = 1;
    } else {
        mortgage_flag = 0;
    }

}

bool square_ownable :: check_if_can_mortgage(){

    if (check_if_mortgage()){
        cout << "you have mortgage this building " << endl;
        return false;
    }

    return true;
}

bool square_ownable :: check_if_can_unmortgage(){

    if (check_if_mortgage()){
        return true;
    }

    cout << "you have not mortgage this building " << endl;
    return false;

}


//int square_ownable :: get_mortgage_flag(){
//    return mortgage_flag;
//}



//building_type square_ownable :: get_building_type(){
//    return type;
//}

//void square_ownable :: set_building_type(building_type type_1){
//    type = type_1;
//}
