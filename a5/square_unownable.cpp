//
// Created by 孟天奥 on 2020-10-27.
//
#include "square_unownable.h"
#include <iostream>
#include <sstream>
#include "player.h"
using namespace std;
square_unownable :: square_unownable(int index, int payment, std :: string  representation, player * bank , std :: string  name):
                    square(index, representation, building_type :: unownable, name), payment(payment), bank(bank){

}

int square_unownable :: get_payment() {

    return payment;

}

player * square_unownable :: get_owner(){
    return bank;
}

//building_type square_unownable :: get_building_type(){
//    return type;
//}

void square_unownable :: punish(player * punished) {

    cout << punished->get_name() << " arrived " << get_name() << endl;

    if (payment == -1) {

        cout << punished->get_name() << "attacked by a flock of nesting geese" << endl;
        return;

    }

    if (payment == -2) {
//        square * move_to = get_square(30);
//        dattach(punished);
//        move_to->notify(punished);
        cout << punished->get_name() << " arrive go to tims square, and be sent to dc tims line" << endl;
        punished->move(20, 0);
        //punished -> set_if_in_dc_tims_line(1);
        return;
    }

    if (payment == 200) {

        int bill = get_payment();
        cout << punished->get_name() << " pass by osap, collect 200$" << endl;
//        if (!check_enough_to_pay(bill, punished, get_owner())) {
//            return;
//        }
        punished->increase_account(bill);
        bank->decrease_account(bill);
        return;

    }

    if (payment == 50) {

        //int count = 0;
        if ((punished->get_if_in_dc_tims_line() == 0) && (punished->get_index() != 30) &&
            (punished->get_three_doubles() != 1) && (punished->get_card() != 1)) {

            cout << punished->get_name() << " is in DC Tims Line but nothing happens" << endl;
            punished->set_index(10);
            return;
        }

        if ((punished->get_if_in_dc_tims_line() == 0) && (punished->get_in_dc_tims_line() == 0)) {

//            if (punished -> get_three_doubles() == 1){
//                punished -> set_three_doubles();
//            }
            cout << "now " << punished->get_name() << " is jail in DC Tims Line" << endl;
            punished->set_if_in_dc_tims_line(1);
            punished->set_index(10);
            return;

        }

        cout << "now " << punished->get_name() << " is jail in DC Tims Line" << endl;
        punished->increase_in_dc_tims_line();
        //punished->set_index(10);

        string roll;
        string command;
        int dice_1;
        int dice_2;
        cout << "Please roll dice two times" << endl;
        while (true) {

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
        while (true) {
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

        if ((dice_1 == dice_2) && (punished->get_in_dc_tims_line() <= 3)) {
            cout << "congraduation, you roll doubles" << endl;

            cout << R"(Please choose your choice "pay 50$" or "pay Roll_Up_the_Rim_Cup")" << endl;
            while (true) {

//                string command;
                string action;
                string choice;
                while (true) {

                    getline(cin, command);
                    istringstream iss_1(command);
                    iss_1.exceptions(ios::failbit);

                    iss_1 >> action;

                    if ((action != "pay") && (action != "assets") && (action != "all")) {
                        cout << "wrong input, please enter again" << endl;
                        //iss_1.ignore(INT_MAX);
                        continue;
                    }

                    if ((action == "all") || (action == "assets")) {

                        string buffer;
                        try{
                            iss_1 >> buffer;
                            iss_1.ignore(INT_MAX);
                            cout << punished->get_name() << ", you give a wrong command" << endl;
                            continue;
                        } catch (ios :: failure){

                            iss_1.clear();
                            break;

                        }

                    }

                    if (action == "pay") {
                        iss_1 >> choice;
                    }

                    if ((choice != "50$") && (choice != "Roll_Up_the_Rim_Cup")) {

                        cout << "wrong input, please enter again" << endl;
                        //iss_1.ignore(INT_MAX);
                        continue;
                    } else {

                        string buffer;
                        try{
                            iss_1 >> buffer;
                            //iss_1.ignore(INT_MAX);
                            cout << punished->get_name() << ", you give a wrong command" << endl;
                            continue;
                        } catch (ios :: failure){

                            iss_1.clear();

                            break;

                        }

                    }

                }

                if ((punished->get_money_owned() > 0) && (punished->get_Roll_Up_the_Rim_Cup() == 0)) {

                    punished->set_in_dc_tims_line(0);
                    punished->set_if_in_dc_tims_line(0);
                    punished -> set_card(0);

                    return;

                }

                if (punished->get_money_owned() > 0) {

                    if ((action == "pay") && (choice == "50$")) {

                        cout << R"(You cannot issue "pay 50$")" << endl;
                        //cout << R"(Please try to issue "pay Roll_Up_the_Rim_Cup")" << endl;
                        continue;

                    }

                }

                if (punished->get_Roll_Up_the_Rim_Cup() == 0) {

                    if ((action == "pay") && (choice == "Roll_Up_the_Rim_Cup")) {

                        cout << R"(You cannot  issue "pay Roll_Up_the_Rim_Cup")" << endl;
                        //cout << R"(Please issue "pay Roll_Up_the_Rim_Cup")" << endl;
                        continue;

                    }

                }

                if (action == "pay") {
                    if (choice == "50$") {

                        if (!check_enough_to_pay(50, punished, bank)) {
                            cout << R"(you can only issue "pay Roll_Up_the_Rim_Cup")" << endl;
                            continue;
                        }
                        punished->decrease_account(50);
                        bank->increase_account(50);
                        //square * move_to = get_square(10 + (dice_1 * 2));
                        //dattach(punished);
                        //move_to->notify(punished);
                        punished->set_in_dc_tims_line(0);
                        punished->set_if_in_dc_tims_line(0);
                        punished -> set_card(0);
                        punished->move(dice_1 * 2, 0);

                        return;

                    } else {

                        punished->decrease_Roll_Up_the_Rim_Cup();
                        player::decrease_Roll_Up_the_Rim_Cup_Sent();
                        //square * move_to = get_square(30 + (dice_1 * 2));
                        //dattach(punished);
                        //move_to->notify(punished);
                        punished->set_in_dc_tims_line(0);
                        punished->set_money_owned(0);
                        punished->set_if_in_dc_tims_line(0);
                        punished -> set_card(0);
                        punished->move(dice_1 * 2, 0);
                        return;

                    }

                } else if (action == "assets") {
                    punished->assets();
                } else {
                    punished->all();
                }

            }

            //break;
        }

        if ((dice_1 != dice_2) && (punished->get_in_dc_tims_line() < 3)) {
            cout << punished->get_name() << " now in " << punished->get_in_dc_tims_line() << " turns in dc tims line"
                 << endl;

//            int in_dc_tims_line = punished -> get_in_dc_tims_line();
//            in_dc_tims_line++;
//            punished -> set_in_dc_tims_line(in_dc_tims_line);

            return;
        }

        //count ++;
        if (punished->get_in_dc_tims_line() == 3) {
            cout << punished->get_name() << " now in " << punished->get_in_dc_tims_line() << " turns in dc tims line"
                 << endl;

            cout << R"(Please choose your choice "pay 50$" or "pay Roll_Up_the_Rim_Cup")" << endl;

            while (true) {
//                string command;
                string action;
                string choice;
                while (true) {

                    getline(cin, command);
                    istringstream iss_1(command);
                    iss_1.exceptions(ios::failbit);

                    iss_1 >> action;

                    if ((action != "pay") && (action != "assets") && (action != "all")) {
                        cout << "wrong input, please enter again" << endl;
                        //iss_1.ignore(INT_MAX);
                        continue;
                    }

                    if ((action == "all") || (action == "assets")) {

                        string buffer;
                        try{
                            iss_1 >> buffer;
                            //iss_1.ignore(INT_MAX);
                            cout << punished->get_name() << ", you give a wrong command" << endl;
                            continue;
                        } catch (ios :: failure){

                            iss_1.clear();
                            break;

                        }

                    }

                    if (action == "pay") {
                        iss_1 >> choice;
                    }

                    if ((choice != "50$") && (choice != "Roll_Up_the_Rim_Cup")) {

                        cout << "wrong input, please enter again" << endl;
                        //iss_1.ignore(INT_MAX);
                        continue;
                    } else {

                        string buffer;
                        try{
                            iss_1 >> buffer;
                            //iss_1.ignore(INT_MAX);
                            cout << punished->get_name() << ", you give a wrong command" << endl;
                            continue;
                        } catch (ios :: failure){

                            iss_1.clear();
                            break;

                        }

                    }

                }

                if ((punished->get_money_owned() > 0) && (punished->get_Roll_Up_the_Rim_Cup() == 0)) {

                    punished->set_in_dc_tims_line(0);
                    punished->set_if_in_dc_tims_line(0);
                    punished -> set_card(0);
                    return;
                }

                if (punished->get_money_owned() > 0) {

                    if ((action == "pay") && (choice == "50$")) {

                        cout << R"(You cannot issue "pay $50")" << endl;
                        //cout << R"(Please issue "pay Roll_Up_the_Rim_Cup")" << endl;
                        continue;

                    }


                }

                if (punished->get_Roll_Up_the_Rim_Cup() == 0) {

                    if ((action == "pay") && (choice == "Roll_Up_the_Rim_Cup")) {

                        cout << R"(You cannot  issue "pay Roll_Up_the_Rim_Cup")" << endl;
                        //cout << R"(Please issue "pay Roll_Up_the_Rim_Cup")" << endl;
                        continue;

                    }


                }
                if (action == "pay") {

                    if (choice == "50$") {

                        if (!check_enough_to_pay(50, punished, bank)) {
                            cout << R"(you can only issue "pay Roll_Up_the_Rim_Cup")" << endl;
                            continue;
                        }

                        punished->decrease_account(50);
                        bank->increase_account(50);
                        //square * move_to = get_square(30 + (dice_1 + dice_2));
                        //dattach(punished);
                        //move_to->notify(punished);

                        punished->set_in_dc_tims_line(0);
                        punished->set_if_in_dc_tims_line(0);
                        punished -> set_card(0);
                        punished->move(dice_1 + dice_2, 0);
                        return;

                    } else {

                        punished->decrease_Roll_Up_the_Rim_Cup();
                        player::decrease_Roll_Up_the_Rim_Cup_Sent();

                        punished->set_in_dc_tims_line(0);
                        punished->set_money_owned(0);
                        punished -> set_card(0);
                        punished->set_if_in_dc_tims_line(0);
                        punished->move(dice_1 + dice_2, 0);
                        return;
                        //square * move_to = get_square(30 + (dice_1 + dice_2));
                        //dattach(punished);
                        //move_to->notify(punished);

                    }

                } else if (action == "assets") {
                    punished->assets();
                } else {
                    punished->all();
                }

            }


        }
    }
    if (payment == 300) {

        //cout << punished->get_name() << " is in tuition square" << endl;
        cout << R"(you cannot issue "assets" or "all")" << endl;
        string choice;
        string buffer;

        while (true) {
            cout << R"(Please choose your choice pay "300$" or "10%" of your total worth, )" << punished->get_name() << endl;
            getline(cin,buffer);
            stringstream ss(buffer);
            ss.exceptions(ios::failbit);
            ss >> choice;
            //cout << "choice: " << choice << endl;
            if ((choice != "300$") && (choice != "10%")) {
                cout << "wrong input, please enter again" << endl;
                continue;
            }

            try {
                ss >> buffer;
                //cout << "buffer: " << buffer << endl;
                cout << "wrong input, please enter again" << endl;
                continue;
            } catch (ios::failure){
                break;
            }


//            if (cin.eof()){
//                break;
//            } else {
//                cout << "wrong input, please enter again" << endl;
//                cin.ignore(INT_MAX);
//                continue;
//            }

        }

        if (choice == "300$") {
            int bill = get_payment();
            if (!check_enough_to_pay(bill, punished, bank)) {
                return;
            }
            bank->increase_account(bill);
            punished->decrease_account(bill);
            return;
        } else {
            int total = punished->get_total();
            cout << "total: " << total << endl;
            int bill = 0.1 * total;
            if (!check_enough_to_pay(bill, punished, bank)) {
                return;
            }
            bank->increase_account(bill);
            punished->decrease_account(bill);
            return;
        }
    }
        int bill = get_payment();
        if (!check_enough_to_pay(bill, punished, bank)){
            return;
        }
        bank->increase_account(bill);
        punished->decrease_account(bill);
}


