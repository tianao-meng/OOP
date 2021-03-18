//
// Created by 孟天奥 on 2020-10-28.
//

#ifndef A5_MONOPOLY_H
#define A5_MONOPOLY_H

#include <vector>
#include "academic.h"
#include "player.h"
class academic;
class player;
class monopoly {

    int improvement_fee;
    std::string name;
    std :: vector <academic *> composites;

public:
    monopoly(int improvement_fee, std:: string name);
    void add_building(academic * building);
    bool check_can_improve(player * improver);
    int get_improvement_fee();
    std:: string get_name();
    std :: vector <academic *> get_composites();
    bool check_equal_improve(academic * building);
    bool check_equal_sell(academic * building);


};

#endif //A5_MONOPOLY_H
