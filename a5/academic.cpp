//
// Created by 孟天奥 on 2020-10-27.
//

#include "academic.h"
#include <string>
#include <iostream>
//#include "monopoly.h"
using namespace std;

academic :: academic( square_ownable & component, int improvements, int payments) : component(component), improvements(improvements){

    component.set_building_type(building_type :: academic);
    component.set_payment(payments);


}

int academic :: get_improvements() {

    return improvements;
}

int academic :: get_payment() {
    return component.get_payment();
}

building_type academic :: get_building_type(){
    return component.get_building_type();
}

std :: string academic :: get_owner_name(){
    return component.get_owner_name();
}

void academic :: set_owner(player * buyer){
    component.set_owner(buyer);
}

void academic :: set_monopoly(monopoly * a){
    belong = a;
}

std:: string academic :: get_monopoly_name(){
    return belong -> get_name();
}

void academic :: set_payment(int a){
    component.set_payment(a);
}

monopoly * academic :: get_monopoly(){
    return belong;
}

void academic :: punish(player * punished){
    //cout << punished -> get_name() << " arrived " << get_name() << endl;

    if (improvements == 0){

        if (belong -> check_can_improve(get_owner())){

            cout << "Because all the buildings in "<< belong -> get_name() << " owned by " << get_owner_name() << endl;
            cout << punished -> get_name() << " need to pay doubles fee although " << get_name() << " has no imprivements" << endl;
            int bill = improvement_dict[get_name()][improvements];
            component.set_payment(bill * 2);
            component.punish(punished);

        } else {

            component.punish(punished);

        }

    } else {
        component.punish(punished);
    }

}

int academic :: get_price(){
    return component.get_price();
}

std:: string academic :: get_name(){
    return component.get_name();
}

void academic :: deprove(){

    improvements --;
    string building_name = component.get_name();
    int payments = improvement_dict[building_name][improvements];
    cout << component.get_name() << " decrease its payments from " << improvement_dict[building_name][improvements + 1] << " to " <<  improvement_dict[building_name][improvements] << endl;

    if (improvements == 0){

        string representataion = component.get_representation();
        representataion[11] = ' ';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    if (improvements == 1){

        string representataion = component.get_representation();
        representataion[13] = ' ';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    if (improvements == 2){

        string representataion = component.get_representation();
        representataion[15] = ' ';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    if (improvements == 3){

        string representataion = component.get_representation();
        representataion[17] = ' ';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    if (improvements == 4){

        string representataion = component.get_representation();
        representataion[19] = ' ';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    cout << "you can only have improvements below 0" << endl;
    improvements++;

}

void academic:: improve() {


    improvements ++;
    string building_name = component.get_name();
    int payments = improvement_dict[building_name][improvements];
    cout << component.get_name() << " improve its payments from " << improvement_dict[building_name][improvements - 1] << " to " <<  improvement_dict[building_name][improvements] << endl;

    if (improvements == 1){

        string representataion = component.get_representation();
        representataion[11] = 'I';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    if (improvements == 2){

        string representataion = component.get_representation();
        representataion[13] = 'I';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    if (improvements == 3){

        string representataion = component.get_representation();
        representataion[15] = 'I';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    if (improvements == 4){

        string representataion = component.get_representation();
        representataion[17] = 'I';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    if (improvements == 5){

        string representataion = component.get_representation();
        representataion[19] = 'I';
        component.set_representation(representataion);
        component.set_payment(payments);
        return;

    }

    cout << "you can only have improvements at most 5" << endl;
    improvements--;

}

std::string academic :: get_representation(){
    return component.get_representation();
}

bool academic :: check_if_mortgage(){

    return component.check_if_mortgage();
}

void academic :: set_mortgage_flag(){


    component.set_mortgage_flag();


}

bool academic :: check_if_can_mortgage(){

    if (improvements != 0){
        cout << "you must sell all of the improvements before mortgage" << endl;
        return false;
    }

    if (check_if_mortgage()){
        cout << "you have mortgage this building " << endl;
        return false;
    }

    return true;

}

bool academic :: check_if_can_unmortgage(){

    return component.check_if_can_unmortgage();

}

void academic :: push_back(player * who_in){
    component.push_back(who_in);
}
void academic :: dattach(player * who_in){
    component.dattach(who_in);
}

player * academic :: get_owner(){
    return component.get_owner();
}

int academic :: get_index(){
    //cout << "in academic: " << component.get_index() << endl;
    return component.get_index();
}

academic :: ~academic(){
    delete &component;
}