//
// Created by 孟天奥 on 2020-10-28.
//

#include "monopoly.h"
#include <iostream>
using namespace std;

monopoly :: monopoly(int improvement_fee, string name) : improvement_fee(improvement_fee), name(name) {}

void monopoly :: add_building(academic * building) {

    composites.push_back(building);

}

bool monopoly :: check_can_improve(player * improver) {

    cout << "i am in check can improve of monopoly" << endl;
    vector<academic *>::iterator it;
    string improver_name = improver->get_name();
    for (it = composites.begin(); it != composites.end(); it++) {

        if ((*it) -> check_if_mortgage()){
            return false;
        }

        string owner_name = (*it) -> get_owner_name();
        if (owner_name != improver_name){
            return false;
        }

    }

    return true;

}
int monopoly :: get_improvement_fee() {
    return improvement_fee;
}

std:: string monopoly :: get_name(){
    return name;
}

vector <academic *> monopoly :: get_composites(){
    return composites;
}

bool monopoly :: check_equal_improve(academic * building){

    int now_improvements = building -> get_improvements();
    int new_improvements = now_improvements + 1;
    vector <academic *> :: iterator it;
    for (it = composites.begin(); it != composites.end(); it++){

        if ( ( new_improvements - (*it) -> get_improvements() ) >= 2){
            return false;
        }
    }

    return true;

}

bool monopoly :: check_equal_sell(academic * building){

    int now_improvements = building -> get_improvements();
    int new_improvements = now_improvements - 1;
    vector <academic *> :: iterator it;
    for (it = composites.begin(); it != composites.end(); it++){

        if ( ( (*it) -> get_improvements() - new_improvements ) >= 2){
            return false;
        }

    }

    return true;
}

