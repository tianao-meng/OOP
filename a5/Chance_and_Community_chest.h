//
// Created by 孟天奥 on 2020-10-28.
//

#ifndef A5_CHANCE_AND_COMMUNITY_CHEST_H
#define A5_CHANCE_AND_COMMUNITY_CHEST_H

#include "square.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"


class cards {

    std :: string on_card;
    virtual cards * get_card() = 0;
public:
    std :: string get_on_card();
    void set_on_card(std :: string a);
    virtual ~cards() = default;


};

class community_chest : public cards {

    cards * get_card() override;

public:
    community_chest();
};

class chance : public cards {

    cards * get_card() override;

public:
    chance();
};

class cards_maker {
public:
    enum kind {Community_Chest, Chance};
    virtual cards * order() = 0;
    virtual ~cards_maker() = default;

};

class community_chest_maker : public cards_maker {

public:
    cards * order() override ;
};

class chance_maker : public cards_maker {

public:
    cards * order() override ;
};

class cards_maker_factory {

public:
    virtual cards_maker * create() = 0;


};

class community_chest_maker_factory : public cards_maker_factory {

public:
    cards_maker * create() override;


};

class chance_maker_factory : public cards_maker_factory {

public:
    cards_maker * create() override;

};

class card : public square{

    //building_type type = building_type :: card;
    player * bank;
    cards_maker :: kind kind;

    //std :: vector <square *> game_board;
public:
    card(int index, std :: string representation, player * bank, cards_maker :: kind, std :: string name);
    //building_type get_building_type();
    //square * get_square(int index);
    void punish(player * punished);
    player * get_owner();
    ~card() = default;
};

#endif //A5_CHANCE_AND_COMMUNITY_CHEST_H
