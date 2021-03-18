//
// Created by 孟天奥 on 2020-10-26.
//
#include <iostream>
#include "square.h"
#include "academic.h"
#include "square_unownable.h"
#include "square_ownable.h"
#include "board.h"
using namespace std;

string concat_building(string long_str, string b){


    string output;
    for (int i = 0;;){

        string::size_type posn = long_str.find_first_of('\n');

        if (posn == string :: npos){
            break;
        }

        string a_ele = long_str.substr(i, posn);
        output += a_ele;
        string::size_type posn_b = b.find_first_of('\n');
        string b_ele = b.substr(i + 1, posn_b - 1);
        output += b_ele;
        output += '\n';
        posn ++;
        posn_b ++;
        //i = posn;
        long_str = long_str.substr(posn);
        b = b.substr(posn_b);

    }
    return output;

}

string stack_building(string a, string b){

    string output;

    //cout << "last: " << posn_last << endl;
    for (int i = 0;;){

        string::size_type posn = a.find_first_of('\n');
        string::size_type posn_last = a.find_last_of('\n');
        if (posn == string :: npos){
            break;
        }

        string a_ele = a.substr(i, posn);
        output += a_ele;
        //cout << "posn: " << posn << endl;
        if (posn != posn_last){
            output += '\n';
        }
        posn ++;
        //i = posn;
        a = a.substr(posn);
    }

    for (int i = 0;;){

        string::size_type posn = b.find_first_of('\n');

        if (posn == string :: npos){
            break;
        }

        string b_ele = b.substr(i, posn);
        output += b_ele;

        output += '\n';
        posn ++;
        //i = posn;
        b = b.substr(posn);
    }
    return output;

}

board ::board(player * bank) : bank(bank) {

    monopoly * arts_1 = new monopoly(50, "arts_1");
    monopoly_blocks.push_back(arts_1);
    monopoly * arts_2 = new monopoly(50, "arts_2");
    monopoly_blocks.push_back(arts_2);
    monopoly * eng = new monopoly(100, "eng");
    monopoly_blocks.push_back(eng);
    monopoly * health = new monopoly(100, "health");
    monopoly_blocks.push_back(health);
    monopoly * env = new monopoly(150, "env");
    monopoly_blocks.push_back(env);
    monopoly * sci_1 = new monopoly(150, "sci_1");
    monopoly_blocks.push_back(sci_1);
    monopoly * sci_2 = new monopoly(200, "sci_2");
    monopoly_blocks.push_back(sci_2);
    monopoly * math = new monopoly(200, "math");
    monopoly_blocks.push_back(math);

    square_unownable * goose_nesting = new square_unownable( 20, -1, "         \n|Goose    |\n|Nesting  |\n|         |\n|         |\n|---------|\n", bank, "Goose Nesting");
    board ::game_board.push_back((square *)goose_nesting);


    square_ownable * ev1_component = new square_ownable (21, 18, 220, "         \n|         |\n|---------|\n|EV1      |\n|         |\n|---------|\n", bank, "EV1");
    academic * ev1 = new academic(*ev1_component, 0, 18);
    ev1 -> set_monopoly(env);
    board ::game_board.push_back((square *)ev1);
    env -> add_building(ev1);


    card * needles_1 = new card(22, "         \n|NEEDLES  |\n|HALL     |\n|         |\n|         |\n|---------|\n", bank, cards_maker :: Chance, "NEEDLES HALL");
    board ::game_board.push_back((square *)needles_1);


    square_ownable * ev2_component = new square_ownable (23, 18, 220, "         \n|         |\n|---------|\n|EV2      |\n|         |\n|---------|\n", bank, "EV2");
    academic * ev2 = new academic(*ev2_component, 0, 18);
    ev2 -> set_monopoly(env);
    board ::game_board.push_back((square *)ev2);
    env -> add_building(ev2);


    square_ownable * ev3_component = new square_ownable (24, 20, 240, "         \n|         |\n|---------|\n|EV3      |\n|         |\n|---------|\n", bank, "EV3");
    academic * ev3 = new academic(*ev3_component, 0, 20);
    ev3 -> set_monopoly(env);
    board ::game_board.push_back((square *)ev3);
    env -> add_building(ev3);


    square_ownable * v1 = new square_ownable (25, 25, 200, "         \n|V1       |\n|         |\n|         |\n|         |\n|---------|\n", bank, "V1",building_type::residence);
    board ::game_board.push_back((square *)v1);


    square_ownable * phys_component = new square_ownable (26, 22, 260, "         \n|         |\n|---------|\n|PHYS     |\n|         |\n|---------|\n", bank, "PHYS");
    academic * phys = new academic(*phys_component, 0, 22);
    phys -> set_monopoly(sci_1);
    board ::game_board.push_back((square *)phys);
    sci_1 -> add_building(phys);

    square_ownable * b1_component = new square_ownable (27, 22, 260, "         \n|         |\n|---------|\n|B1       |\n|         |\n|---------|\n", bank,"B1");
    academic * b1 = new academic(*b1_component, 0, 22);
    b1 -> set_monopoly(sci_1);
    board ::game_board.push_back((square *)b1);
    sci_1 -> add_building(b1);


    square_ownable * cif = new square_ownable (28, 0, 150, "         \n|CIF      |\n|         |\n|         |\n|         |\n|---------|\n", bank, "CIF",building_type::gym);
    board ::game_board.push_back((square *)cif);


    square_ownable * b2_component = new square_ownable (29, 24, 280, "         \n|         |\n|---------|\n|B2       |\n|         |\n|---------|\n", bank,"B2");
    academic * b2 = new academic(*b2_component, 0, 24);
    b2 -> set_monopoly(sci_1);
    board ::game_board.push_back((square *)b2);
    sci_1 -> add_building(b2);


    square_unownable * go_to_tims = new square_unownable( 30, -2, "         \n|GO TO    |\n|TIMS     |\n|         |\n|         |\n|---------|\n", bank,"Go To Tims");
    board ::game_board.push_back((square *)go_to_tims);

    square_ownable * eit_component = new square_ownable (31, 26, 300, "         \n|         |\n|---------|\n|EIT      |\n|         |\n|---------|\n", bank, "EIT");
    academic * eit = new academic(*eit_component, 0, 26);
    eit -> set_monopoly(sci_2);
    board ::game_board.push_back((square *)eit);
    sci_2 -> add_building(eit);

    square_ownable * esc_component = new square_ownable (32, 26, 300, "         \n|         |\n|---------|\n|ESC      |\n|         |\n|---------|\n", bank,"ESC");
    academic * esc = new academic(*esc_component, 0, 26);
    esc -> set_monopoly(sci_2);
    board ::game_board.push_back((square *)esc);
    sci_2 -> add_building(esc);

    card * slc_1 = new card(33, "         \n|SLC      |\n|         |\n|         |\n|         |\n|---------|\n", bank, cards_maker :: Community_Chest,"SLC");
    board ::game_board.push_back((square *)slc_1);

    square_ownable * c2_component = new square_ownable (34, 28, 320, "         \n|         |\n|---------|\n|C2       |\n|         |\n|---------|\n", bank,"C2");
    academic * c2 = new academic(*c2_component, 0, 28);
    c2 -> set_monopoly(sci_2);
    board ::game_board.push_back((square *)c2);
    sci_2 -> add_building(c2);

    square_ownable * rev = new square_ownable (35, 25, 200, "         \n|REV      |\n|         |\n|         |\n|         |\n|---------|\n", bank,"REV" ,building_type::residence);
    board ::game_board.push_back((square *)rev);

    card * needles_2 = new card(36, "         \n|NEEDLES  |\n|HALL     |\n|         |\n|         |\n|---------|\n", bank, cards_maker :: Chance,"NEEDLES HALL");
    board ::game_board.push_back((square *)needles_2);

    square_ownable * mc_component = new square_ownable (37, 35, 350, "         \n|         |\n|---------|\n|MC       |\n|         |\n|---------|\n", bank, "MC");
    academic * mc = new academic(*mc_component, 0, 35);
    mc -> set_monopoly(math);
    board ::game_board.push_back((square *)mc);
    math -> add_building(mc);

    square_unownable * coop_fee = new square_unownable( 38, 150, "         \n|Coop     |\n|Fee      |\n|         |\n|         |\n|---------|\n", bank,"COOP FEE");
    board ::game_board.push_back((square *)coop_fee);

    square_ownable * dc_component = new square_ownable (39, 50, 400, "         \n|         |\n|---------|\n|DC       |\n|         |\n|---------|\n", bank,"DC");
    academic * dc = new academic(*dc_component, 0, 50);
    dc -> set_monopoly(math);
    board ::game_board.push_back((square *)dc);
    math -> add_building(dc);

    square_unownable * collect_osap = new square_unownable( 0, 200, "         \n|COLLECT  |\n|OSAP     |\n|         |\n|         |\n|---------|\n", bank,"COLLECT OSAP");
    board ::game_board.push_back((square *)collect_osap);

    square_ownable * al_component = new square_ownable (1, 2, 40, "         \n|         |\n|---------|\n|AL       |\n|         |\n|---------|\n", bank, "AL");
    academic * al = new academic(*al_component, 0, 2);
    al -> set_monopoly(arts_1);
    board ::game_board.push_back((square *)al);
    arts_1 -> add_building(al);

    card * slc_2 = new card(2, "         \n|SLC      |\n|         |\n|         |\n|         |\n|---------|\n", bank, cards_maker :: Community_Chest,"SLC");
    board ::game_board.push_back((square *)slc_2);

    square_ownable * ml_component = new square_ownable (3, 4, 60, "         \n|         |\n|---------|\n|ML       |\n|         |\n|---------|\n", bank,"ML");
    academic * ml = new academic(*ml_component, 0, 4);
    ml -> set_monopoly(arts_1);
    board ::game_board.push_back((square *)ml);
    arts_1 -> add_building(ml);

    square_unownable * tuition = new square_unownable( 4, 300, "         \n|TUITION  |\n|         |\n|         |\n|         |\n|---------|\n", bank,"TUITION");
    board ::game_board.push_back((square *)tuition);

    square_ownable * mkv = new square_ownable (5, 25, 200, "         \n|MKV      |\n|         |\n|         |\n|         |\n|---------|\n", bank, "MKV",building_type::residence);
    board ::game_board.push_back((square *)mkv);

    square_ownable * ech_component = new square_ownable (6, 6, 100, "         \n|         |\n|---------|\n|ECH      |\n|         |\n|---------|\n", bank, "ECH");
    academic * ech = new academic(*ech_component, 0, 6);
    ech -> set_monopoly(arts_2);
    board ::game_board.push_back((square *)ech);
    arts_2 -> add_building(ech);

    card * needles_3 = new card(7, "         \n|NEEDLES  |\n|HALL     |\n|         |\n|         |\n|---------|\n", bank, cards_maker :: Chance, "NEEDLES HALL");
    board ::game_board.push_back((square *)needles_3);

    square_ownable * pas_component = new square_ownable (8, 6, 100, "         \n|         |\n|---------|\n|PAS      |\n|         |\n|---------|\n", bank,"PAS");
    academic * pas = new academic(*pas_component, 0, 6);
    pas -> set_monopoly(arts_2);
    board ::game_board.push_back((square *)pas);
    arts_2 -> add_building(pas);

    square_ownable * hh_component = new square_ownable (9, 8, 120, "         \n|         |\n|---------|\n|HH       |\n|         |\n|---------|\n", bank, "HH");
    academic * hh = new academic(*hh_component, 0, 8);
    hh -> set_monopoly(arts_2);
    board ::game_board.push_back((square *)hh);
    arts_2 -> add_building(hh);

    square_unownable * dc_tims_line = new square_unownable( 10, 50, "         \n|DC Tims  |\n|Line     |\n|         |\n|         |\n|---------|\n", bank, "DC TIMS LINE");
    board ::game_board.push_back((square *)dc_tims_line);

    square_ownable * rch_component = new square_ownable (11, 10, 140, "         \n|         |\n|---------|\n|RCH      |\n|         |\n|---------|\n", bank, "RCH");
    academic * rch = new academic(*rch_component, 0, 10);
    rch -> set_monopoly(eng);
    board ::game_board.push_back((square *)rch);
    eng -> add_building(rch);

    square_ownable * pac = new square_ownable (12, 0, 150, "         \n|PAC      |\n|         |\n|         |\n|         |\n|---------|\n", bank,"PAC", building_type::gym);
    board ::game_board.push_back((square *)pac);

    square_ownable * dwe_component = new square_ownable (13, 10, 140, "         \n|         |\n|---------|\n|DWE      |\n|         |\n|---------|\n", bank, "DWE");
    academic * dwe = new academic(*dwe_component, 0, 10);
    dwe -> set_monopoly(eng);
    board ::game_board.push_back((square *)dwe);
    eng -> add_building(dwe);

    square_ownable * cph_component = new square_ownable (14, 12, 160, "         \n|         |\n|---------|\n|CPH      |\n|         |\n|---------|\n", bank, "CPH");
    academic * cph = new academic(*cph_component, 0, 12);
    cph -> set_monopoly(eng);
    board ::game_board.push_back((square *)cph);
    eng -> add_building(cph);

    square_ownable * uwp = new square_ownable (15, 25, 200, "         \n|UWP      |\n|         |\n|         |\n|         |\n|---------|\n", bank, "UWP",building_type::residence);
    board ::game_board.push_back((square *)uwp);

    square_ownable * lhi_component = new square_ownable (16, 14, 180, "         \n|         |\n|---------|\n|LHI      |\n|         |\n|---------|\n", bank, "LHI");
    academic * lhi = new academic(*lhi_component, 0, 14);
    lhi -> set_monopoly(health);
    board ::game_board.push_back((square *)lhi);
    health -> add_building(lhi);

    card * slc_3 = new card(17, "         \n|SLC      |\n|         |\n|         |\n|         |\n|---------|\n", bank, cards_maker :: Community_Chest, "SLC");
    board ::game_board.push_back((square *)slc_3);

    square_ownable * bmh_component = new square_ownable (18, 14, 180, "         \n|         |\n|---------|\n|BMH      |\n|         |\n|---------|\n", bank, "BMH");
    academic * bmh = new academic(*bmh_component, 0, 14);
    bmh -> set_monopoly(health);
    board ::game_board.push_back((square *)bmh);
    health -> add_building(bmh);

    square_ownable * opt_component = new square_ownable (19, 16, 200, "         \n|         |\n|---------|\n|OPT      |\n|         |\n|---------|\n", bank, "OPT");
    academic * opt = new academic(*opt_component, 0, 16);
    opt -> set_monopoly(health);
    board ::game_board.push_back((square *)opt);
    health -> add_building(opt);

}

vector <square *> board :: get_game_board(){
    return game_board;
}

square * board :: get_square(int index) {

    vector <square *> :: iterator it;
    for (it=game_board.begin(); it != game_board.end(); it++){
        int square_index = (*it) ->get_index();
        //cout << "square_index: " <<  square_index << endl;
        //int square_y = (*it) ->get_y();
        if (square_index == index){

            return *it;
        }
    }

    return nullptr;
}

square * board :: get_square(const string& name){

    vector <square *> :: iterator it;
    for (it = game_board.begin(); it != game_board.end(); it++){

        if ((*it) -> get_name() == name){
            return (*it);
        }

    }
    return nullptr;
}

void board :: draw(){

    string upper = "---------------------------------------------------------------------------------------------------------------\n";
    string s = "         \n           \n           \n           \n           \n           \n";
    string last_s = "         \n|         |\n|         |\n|         |\n|         |\n|         |\n";
    string last_row_s = "         \n           \n           \n           \n           \n|---------|\n";
    string last_row_colume_s = "         \n|         |\n|         |\n|         |\n|         |\n|---------|\n";
    string WA = "           \n|#   #  ## \n|#   # #  #\n|# # # ####\n|# # # #  #\n|##### #  #\n";

    string TO = "           \n| #####  ##\n|   #   #  \n|   #   #  \n|   #   #  \n|   #    ##\n";
    string OPO = "           \n|#   ###   \n| #  #  # #\n| #  ###  #\n| #  #    #\n|#   #     \n";
    string OL = "           \n|###  #    \n|   # #    \n|   # #    \n|   # #    \n|###  ## # \n";
    string Y = "           \n|#   # |   \n|#   # |   \n| # #  |   \n|  #   |   \n|  #   |   \n";
    string  lower_bound = "           \n-----------\n           \n           \n           \n           \n";
    string  lower_last = "           \n--------   \n           \n           \n           \n           \n";
    string s_logo = "         \n          |\n          |\n          |\n          |\n          |\n";
    string  s_lower_bound = "           \n          -\n           \n           \n           \n           \n";
    string  upper_bound = "           \n           \n           \n           \n           \n-----------\n";
    string  upper_last = "           \n           \n           \n           \n           \n--------   \n";
    string  s_upper_bound = "           \n           \n           \n           \n           \n          -\n";

    string goose_nesting = get_square(20) ->get_representation();
    string ev1 = get_square(21) ->get_representation();
    string needles_hall_1 = get_square(22) ->get_representation();
    string ev2 = get_square(23) ->get_representation();
    string ev3 = get_square(24) ->get_representation();
    string v1 = get_square(25) ->get_representation();
    string phys = get_square(26) ->get_representation();
    string b1 = get_square(27) ->get_representation();
    string cif = get_square(28) ->get_representation();
    string b2 = get_square(29) ->get_representation();
    string go_to_tims = get_square(30) ->get_representation();

    string first_row = concat_building(goose_nesting,ev1);
    first_row = concat_building(first_row, needles_hall_1);
    first_row = concat_building(first_row, ev2);
    first_row = concat_building(first_row, ev3);
    first_row = concat_building(first_row, v1);
    first_row = concat_building(first_row, phys);
    first_row = concat_building(first_row, b1);
    first_row = concat_building(first_row, cif);
    first_row = concat_building(first_row, b2);
    first_row = concat_building(first_row, go_to_tims);

    string opt = get_square(19) -> get_representation();
    string eit = get_square(31) -> get_representation();

    string second_row = concat_building(opt,s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, last_s);
    second_row = concat_building(second_row, eit);

    string bmh = get_square(18) -> get_representation();
    string esc = get_square(32) -> get_representation();

    string third_row = concat_building(bmh,s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, last_s);
    third_row = concat_building(third_row, esc);

    string slc_1 = get_square(17) -> get_representation();
    string slc_2 = get_square(33) -> get_representation();

    string fourth_row = concat_building(slc_1,s);
    fourth_row = concat_building(fourth_row, s);
    fourth_row = concat_building(fourth_row, s);
    fourth_row = concat_building(fourth_row, s);
    fourth_row = concat_building(fourth_row, s);
    fourth_row = concat_building(fourth_row, s);
    fourth_row = concat_building(fourth_row, s);
    fourth_row = concat_building(fourth_row, s);
    fourth_row = concat_building(fourth_row, last_s);
    fourth_row = concat_building(fourth_row, slc_2);

    string lhi = get_square(16) -> get_representation();
    string c2 = get_square(34) -> get_representation();

    string fifth_row = concat_building(lhi,s);
    fifth_row = concat_building(fifth_row, s_upper_bound);
    fifth_row = concat_building(fifth_row, upper_bound);
    fifth_row = concat_building(fifth_row, upper_bound);
    fifth_row = concat_building(fifth_row, upper_bound);
    fifth_row = concat_building(fifth_row, upper_bound);
    fifth_row = concat_building(fifth_row, upper_last);
    fifth_row = concat_building(fifth_row, s);
    fifth_row = concat_building(fifth_row, last_s);
    fifth_row = concat_building(fifth_row, c2);

    string uwp = get_square(15) -> get_representation();
    string rev = get_square(35) -> get_representation();

    string sixth_row = concat_building(uwp,s);
    sixth_row = concat_building(sixth_row, s_logo);
    sixth_row = concat_building(sixth_row, WA);
    sixth_row = concat_building(sixth_row, TO);
    sixth_row = concat_building(sixth_row, OPO);
    sixth_row = concat_building(sixth_row, OL);
    sixth_row = concat_building(sixth_row, Y);
    sixth_row = concat_building(sixth_row, s);
    sixth_row = concat_building(sixth_row, last_s);
    sixth_row = concat_building(sixth_row, rev);

    string cph = get_square(14) -> get_representation();
    string needles_hall_2 = get_square(36) -> get_representation();

    string seventh_row = concat_building(cph,s);
    seventh_row = concat_building(seventh_row, s_lower_bound);
    seventh_row = concat_building(seventh_row, lower_bound);
    seventh_row = concat_building(seventh_row, lower_bound);
    seventh_row = concat_building(seventh_row, lower_bound);
    seventh_row = concat_building(seventh_row, lower_bound);
    seventh_row = concat_building(seventh_row, lower_last);
    seventh_row = concat_building(seventh_row, s);
    seventh_row = concat_building(seventh_row, last_s);
    seventh_row = concat_building(seventh_row, needles_hall_2);


    string dwe = get_square(13) -> get_representation();
    string mc = get_square(37) -> get_representation();

    string eighth_row = concat_building(dwe,s);
    eighth_row = concat_building(eighth_row, s);
    eighth_row = concat_building(eighth_row, s);
    eighth_row = concat_building(eighth_row, s);
    eighth_row = concat_building(eighth_row, s);
    eighth_row = concat_building(eighth_row, s);
    eighth_row = concat_building(eighth_row, s);
    eighth_row = concat_building(eighth_row, s);
    eighth_row = concat_building(eighth_row, last_s);
    eighth_row = concat_building(eighth_row, mc);

    string pac = get_square(12) -> get_representation();
    string coop_fee = get_square(38) -> get_representation();

    string ninth_row = concat_building(pac,s);
    ninth_row = concat_building(ninth_row, s);
    ninth_row = concat_building(ninth_row, s);
    ninth_row = concat_building(ninth_row, s);
    ninth_row = concat_building(ninth_row, s);
    ninth_row = concat_building(ninth_row, s);
    ninth_row = concat_building(ninth_row, s);
    ninth_row = concat_building(ninth_row, s);
    ninth_row = concat_building(ninth_row, last_s);
    ninth_row = concat_building(ninth_row, coop_fee);

    string rch = get_square(11) -> get_representation();
    string dc = get_square(39) -> get_representation();

    string tenth_row = concat_building(rch,last_row_s);
    tenth_row = concat_building(tenth_row, last_row_s);
    tenth_row = concat_building(tenth_row, last_row_s);
    tenth_row = concat_building(tenth_row, last_row_s);
    tenth_row = concat_building(tenth_row, last_row_s);
    tenth_row = concat_building(tenth_row, last_row_s);
    tenth_row = concat_building(tenth_row, last_row_s);
    tenth_row = concat_building(tenth_row, last_row_s);
    tenth_row = concat_building(tenth_row, last_row_colume_s);
    tenth_row = concat_building(tenth_row, dc);

    string dc_tims_line = get_square(10) -> get_representation();
    string hh = get_square(9) -> get_representation();
    string pas = get_square(8) -> get_representation();
    string needles_hall_3 = get_square(7) -> get_representation();
    string ech = get_square(6) -> get_representation();
    string mkv = get_square(5) -> get_representation();
    string tuition = get_square(4) -> get_representation();
    string ml = get_square(3) -> get_representation();
    string slc = get_square(2) -> get_representation();
    string al = get_square(1) -> get_representation();
    string collect_osap = get_square(0) -> get_representation();

    string last_row = concat_building(dc_tims_line,hh);
    last_row = concat_building(last_row, pas);
    last_row = concat_building(last_row, needles_hall_3);
    last_row = concat_building(last_row, ech);
    last_row = concat_building(last_row, mkv);
    last_row = concat_building(last_row, tuition);
    last_row = concat_building(last_row, ml);
    last_row = concat_building(last_row, slc);
    last_row = concat_building(last_row, al);
    last_row = concat_building(last_row, collect_osap);

    string total = stack_building(upper, first_row);
    total = stack_building(total, second_row);
    total = stack_building(total, third_row);
    total = stack_building(total, fourth_row);
    total = stack_building(total, fifth_row);
    total = stack_building(total, sixth_row);
    total = stack_building(total, seventh_row);
    total = stack_building(total, eighth_row);
    total = stack_building(total, ninth_row);
    total = stack_building(total, tenth_row);
    total = stack_building(total, last_row);
    cout << total;
    cout << endl;

}

board :: ~board() {

    vector <square *> :: iterator it;
    for (it = game_board.begin(); it != game_board.end(); it++){
        delete (*it);
    }

    game_board.clear();

    vector <monopoly *> :: iterator it_monopoly;
    for (it_monopoly = monopoly_blocks.begin(); it_monopoly != monopoly_blocks.end(); it_monopoly++){
        delete (*it_monopoly);
    }

    delete bank;

}