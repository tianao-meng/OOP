//
// Created by 孟天奥 on 2020-10-27.
//

#ifndef A5_SQUARE_UNOWNABLE_H
#define A5_SQUARE_UNOWNABLE_H

#include "square.h"


class square_unownable : public square{
    int payment;
    //building_type type = building_type :: unownable;
    player * bank;

public:
    square_unownable(int index, int payment, std :: string  representation, player * bank, std :: string  name);
    int get_payment();
    //building_type get_building_type();
    void punish(player * punished);
    player * get_owner();
    ~square_unownable() = default;

};

#endif //A5_SQUARE_UNOWNABLE_H
