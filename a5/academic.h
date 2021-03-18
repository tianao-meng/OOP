//
// Created by 孟天奥 on 2020-10-27.
//

#ifndef A5_ACADEMIC_H
#define A5_ACADEMIC_H

#include "square_ownable.h"
#include "monopoly.h"
#include <map>
#include <vector>
class monopoly;
class academic : public square_ownable {

    square_ownable & component;
    int improvements;
    monopoly * belong;
    std :: map <std :: string, std :: vector <int>> improvement_dict {

            {"AL", {2, 10, 30, 90, 160, 250}},
            {"ML", {4, 20, 60, 180, 320, 450}},
            {"ECH", {6, 30, 90, 270, 400, 550}},
            {"PAS", {6, 30, 90, 270, 400, 550}},
            {"HH", {8, 40, 100, 300, 450, 600}},
            {"RCH", {10, 50, 150, 450, 625, 750}},
            {"DWE", {10, 50, 150, 450, 625, 750}},
            {"CPH", {12, 60, 180, 500, 700, 900}},
            {"LHI", {14, 70, 200, 550, 750, 950}},
            {"BMH", {14, 70, 200, 550, 750, 950}},
            {"OPT", {16, 80, 220, 600, 800, 1000}},
            {"EV1", {18, 90, 250, 700, 875, 1050}},
            {"EV2", {18, 90, 250, 700, 875, 1050}},
            {"EV3", {20, 100, 300, 750, 925, 1100}},
            {"PHYS", {22, 110, 330, 800, 975, 1150}},
            {"B1", {22, 110, 330, 800, 975, 1150}},
            {"B2", {24, 120, 360, 850, 1025, 1200}},
            {"EIT", {26, 130, 390, 900, 1100, 1275}},
            {"ESC", {26, 130, 390, 900, 1100, 1275}},
            {"C2", {28, 150, 450, 1000, 1200, 1400}},
            {"MC", {35, 175, 500, 1100, 1300, 1500}},
            {"DC", {50, 200, 600, 1400, 1700, 2000}}

    };


public:

    academic(square_ownable & component, int improvements, int payments);
    academic() = default;
    //void improve(int payment);
    int get_index();
    int get_improvements();
    int get_payment();
    std :: string get_owner_name();
    void set_owner(player * buyer);
    building_type get_building_type();
    void set_monopoly(monopoly * a);
    void punish(player * punished);
    std:: string get_monopoly_name();
    void set_payment(int a);
    int get_price();
    std:: string get_name();
    monopoly * get_monopoly();
    void deprove();
    void improve();
    std::string get_representation();
    bool check_if_mortgage();
    void set_mortgage_flag();
    bool check_if_can_mortgage();
    bool check_if_can_unmortgage();
    void push_back(player * who_in);
    void dattach(player * who_in);
    player * get_owner();
    ~academic();

};




#endif //A5_ACADEMIC_H
