//
// Created by 孟天奥 on 2020-10-27.
//

#ifndef A5_SQUARE_OWNABLE_H
#define A5_SQUARE_OWNABLE_H

#include "square.h"


class square_ownable : public square{
    player * owner = nullptr;
    int payment;
    int price;
    int mortgage_flag = 0;

    //building_type type = building_type :: ownable;

public:
    square_ownable() = default;
    square_ownable(int index, int payment, int price, std :: string representation, player * owner, std :: string name,building_type type = building_type :: ownable);
    virtual std :: string get_owner_name();
    virtual int get_payment();
    virtual int get_price();
    virtual void set_payment(int a);
    virtual void punish(player * punished);
    virtual void set_owner(player * buyer);
    virtual player * get_owner();
    virtual bool check_if_mortgage();
    virtual void set_mortgage_flag();
    virtual bool check_if_can_mortgage();
    virtual bool check_if_can_unmortgage();
    virtual ~square_ownable() = default;
    //int get_mortgage_flag();


};

#endif //A5_SQUARE_OWNABLE_H
