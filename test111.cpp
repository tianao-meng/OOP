#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

string concat_building(string a, string b){


    string output;
    for (int i = 0;;){

        string::size_type posn = a.find_first_of('\n');

        if (posn == string :: npos){
            break;
        }

        string a_ele = a.substr(i, posn);
        output += a_ele;
        string::size_type posn_b = b.find_first_of('\n');
        string b_ele = b.substr(i + 1, posn_b - 1);
        output += b_ele;
        output += '\n';
        posn ++;
        posn_b ++;
        //i = posn;
        a = a.substr(posn);
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
    //output += '\n';
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


//void sq_func(sq_sub * a){
//    cout << a -> get_a() << endl;
//}

//class sq1 : public sq{
//public:
//    void set_a(){
//        a =
//    }
//
//};

bool check_if_prime(int num){

    for (int i = 3; i < num; i ++){

        if ((num % i) == 0){
            return false;
        }

    }
    return true;

}

int find_same(string s, string c){

    stringstream ss (s);
    string ele;
    int count = 0;
    while (ss >> ele){
        if (ele == c){
            count ++;
        }
    }

    return count;

}

string prime_factor(int num){

    string output = "";

    if (num == 1){
        output = "1";
        return output;
    }
    while (true){
        //cout << num << endl;
        //cout << " in" << endl;
        if (num == 1){
            break;
        }

        if (num == 2){
            string s;
            stringstream ss;
            ss << num;
            s = ss.str();
            output += s;
            num = num / 2;
            continue;
        }
        for (int i = 2; i < num + 1; i ++){
            //cout << i << endl;
            //cout << "in" << endl;
            if (check_if_prime(i)){

                if ((num % i) == 0){

                    string s;
                    stringstream ss;
                    ss << i;
                    s = ss.str();
                    output += s;
                    output += " ";
                    num = num / i;
                    //cout << num << endl;
                    break;

                }

            }

        }

    }
    //cout << "in" << endl;
    //cout << output << endl;
    return output;


}

string final_res(string s){

    string res;


    string last = "";
    string current;
    stringstream ss_1(s);
    while (ss_1 >> current){
        if (last == current){
            continue;
        }
        last = current;
        int occurance = find_same(s, current);

        if (occurance > 1){

            string a;
            stringstream ss;
            ss << occurance;
            a = ss.str();
            //cout << a << endl;
            string ele = "";

            ele += current;
            ele += '^';
            ele +=a + " x ";;
            res += ele;


        } else {
                string ele;
                ele += current;
                ele += " x ";
                res += ele;
                }

    }
    string::size_type l = res.length();
    res = res.substr(0, l - 2);
    return res;


}
int main() {
    string res_5 = prime_factor(1);
    //cout << res << endl;
    string final_5 = final_res(res_5);
    cout << final_5 << endl;

    string res = prime_factor(2);
    //cout << res << endl;
    string final = final_res(res);
    cout << final << endl;

    string res_1 = prime_factor(4);
    //cout << res << endl;
    string final_1 = final_res(res_1);
    cout << final_1 << endl;

    string res_2 = prime_factor(60);
    //cout << res << endl;
    string final_2 = final_res(res_2);
    cout << final_2 << endl;

    string res_3 = prime_factor(8320);
    //cout << res << endl;
    string final_3 = final_res(res_3);
    cout << final_3 << endl;



    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    int * a_A = nullptr;
    if (a_A == nullptr){
        cout << "11111"<< endl;
    }

    string upper = "-------------------------------------------------------------------------------------------\n";
    //string a = "-----------\n|         |\n|---------|\n|         |\n|         |\n|---------|\n";
    string b = "         \n|         |\n|---------|\n|         |\n|         |\n|---------|\n";
    //string first_s = "         \n           \n           \n           \n           \n           \n";
    string s = "         \n           \n           \n           \n           \n           \n";
    string last_s = "         \n|         |\n|         |\n|         |\n|         |\n|         |\n";
    string last_row_s = "         \n           \n           \n           \n           \n|---------|\n";
    string last_row_colume_s = "         \n|         |\n|         |\n|         |\n|         |\n|---------|\n";
//    string a = "_ _ _ _ _ _ _ _ _\n|               |\n|_ _ _ _ _ _ _ _|\n|               |\n|               |\n|_ _ _ _ _ _ _ _|\n";
//    //cout << concat_building(a, a) << endl;
//    string b = "                 \n|               |\n|- - - - - - - -|\n|               |\n|               |\n|_ _ _ _ _ _ _ _|\n";
//    string s = "                 \n                 \n                 \n                 \n                 \n                 \n";
//    string last_s = "                 \n|               |\n|               |\n|               |\n|               |\n|               |\n";
//    string last_row_s = "                 \n                 \n                 \n                 \n                 \n _ _ _ _ _ _ _ _ \n";
//    cout << last_s;
//    string last_row_colume_s = "                 \n|               |\n|               |\n|               |\n|               |\n|_ _ _ _ _ _ _ _|\n";
    //cout << concat_building(last_row_colume_s, b);
    string first_row = concat_building(b,b);
    first_row = concat_building(first_row, b);
    first_row = concat_building(first_row, b);
    first_row = concat_building(first_row, b);
    first_row = concat_building(first_row, b);
    first_row = concat_building(first_row, b);
    first_row = concat_building(first_row, b);
    first_row = concat_building(first_row, b);
    //cout << first_row;
    //cout << "--" << endl;
    //cout << "_ _" << endl;
    string second_row = concat_building(b,s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, s);
    second_row = concat_building(second_row, last_s);
    second_row = concat_building(second_row, b);

    //cout << second_row ;

    string third_row = concat_building(b,s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, s);
    third_row = concat_building(third_row, last_s);
    third_row = concat_building(third_row, b);

    string fourth_row = concat_building(b,last_row_s);
    fourth_row = concat_building(fourth_row, last_row_s);
    fourth_row = concat_building(fourth_row, last_row_s);
    fourth_row = concat_building(fourth_row, last_row_s);
    fourth_row = concat_building(fourth_row, last_row_s);
    fourth_row = concat_building(fourth_row, last_row_s);
    fourth_row = concat_building(fourth_row, last_row_colume_s);
    fourth_row = concat_building(fourth_row, b);

    string fifth_row = concat_building(b, b);
    fifth_row = concat_building(fifth_row, b);
    fifth_row = concat_building(fifth_row, b);
    fifth_row = concat_building(fifth_row, b);
    fifth_row = concat_building(fifth_row, b);
    fifth_row = concat_building(fifth_row, b);
    fifth_row = concat_building(fifth_row, b);
    fifth_row = concat_building(fifth_row, b);

    //string total = stack_building(first_row, second_row);
    string total = stack_building(upper, first_row);
    total = stack_building(total, second_row);
    total = stack_building(total, third_row);
    total = stack_building(total, fourth_row);
    total = stack_building(total, fifth_row);
    cout << total;
    cout << endl;

    string WA = "-----------\n|#   #  ## \n|#   # #  #\n|# # # ####\n|# # # #  #\n|##### #  #\n";

    string TO = "-----------\n| #####  ##\n|   #   #  \n|   #   #  \n|   #   #  \n|   #    ##\n";
    string OPO = "-----------\n|#   ###   \n| #  #  # #\n| #  ###  #\n| #  #    #\n|#   #     \n";
    string OL = "-----------\n|###  #    \n|   # #    \n|   # #    \n|   # #    \n|###  ## # \n";
    string Y = "--------   \n|#   # |   \n|#   # |   \n| # #  |   \n|  #   |   \n|  #   |   \n";
    string logo = concat_building(concat_building(concat_building(concat_building(WA, TO), OPO), OL), Y);
    //cout << logo << endl;
    string  lower_bound = "           \n-----------\n           \n           \n           \n           \n";
    string  lower_last = "           \n--------   \n           \n           \n           \n           \n";
    string lower = concat_building(concat_building(concat_building(concat_building(lower_bound, lower_bound), lower_bound), lower_bound), lower_last);

    string final_logo = stack_building(logo, lower);
    cout << final_logo;
    string ownable = "         \n|         |\n|---------|\n|         |\n|         |\n|---------|\n";
    ownable[35] = 'I';
    ownable[37] = 'i';
    ownable[39] = 'i';
    ownable[41] = 'i';
    ownable[43] = 'i';
    ownable[47] = 'i';
    ownable[49] = 'i';
    ownable[51] = 'i';
    ownable[53] = 'i';
    ownable[55

    ] = 'i';
    cout << ownable << endl;
    //string first = "-----------\n|         |\n|---------|\n|         |\n|         |\n|---------|\n";
    //first[37] = 'i';
    //cout << concat_building(first,first) << endl;
    //cout << first << endl;
//    string Goose_Nesting = "-----------\n|Goose    |\n|Nesting  |\n|         |\n|         |\n|---------|\n";
//    cout << Goose_Nesting ;
//    string EV1 = "-----------\n|         |\n|---------|\n|EV1      |\n|         |\n|---------|\n";
//    cout << EV1;

//    srand (time(NULL));
//    int iSecret = rand() % 10 + 1;
//    //srand (time(NULL));
//    int iSecret_1 = rand() % 10 + 1;
//    cout << iSecret << endl;
//    cout << iSecret_1 << endl;
//    sb[13] = 'I';
//    sb[15] = 'I';
//    sb[17] = 'I';
//    sb[19] = 'I';
//    sb[21] = 'I';
    //cout << Goose_Nesting;
//    a [19] = 'I';
//    a [21] = 'I';
//    a [23] = 'I';
//    a [25] = 'I';
//    a [27] = 'I';
//    cout << a;
//    class sq{
//        int a;
//    public:
//        sq (int b){
//            a = b;
//        }
//
//        int get_a(){
//            return a;
//        }
//    };
//
//    class sq_sub : public sq {
//        string c;
//
//    public:
//        sq_sub (int b, string d) : sq(b), c (d){
//
//        }
//
//        string get_str(){
//            return c;
//        }
//
//    };
//

//    sq_sub * sss = new sq_sub(2, "hh");
//    cout << sss ->get_a() << endl;
//    cout << sss ->get_str();
//    sss -> set_str("jhh");
//    cout << sss ->get_str();

    int * as;
    int bs = 0;
    as = &bs;

    int & cs = *as;

    string h = "         \n|NEEDLES  |\n|HALL     |\n|         |\n|         |\n|---------|\n";
    cout << h ;




//    char command;
//    string aaa;
//
//    string initial_command;
//    getline(cin, initial_command);
//    istringstream iss(initial_command);
//    iss >> aaa;
//    iss >> command;
//
//    cout << aaa << endl;
//    cout << command << endl;
//
//    string commands;
//    getline(cin, initial_command);
//    istringstream is(initial_command);
//    iss >> commands;
//    cout << commands << endl;
//
//    int l =1;
//    int bill = 0;
//    if (l == 1){
//        bill = 25;
//    }
//    cout << bill;
//    string ss;
//    getline(cin, ss);
//    cout << ss;
    //cout << "please issue \"raise\" or \"withdraw\"";
//    int  z = 'z' - 'a';
//    cout << "in" << z << endl;
//    std :: map <string, std :: vector <int > > improvement_dict{
//
//            {"AL", {2, 10, 30, 90, 160, 250}},
//            {"ML", {4, 20, 60, 180, 320, 450}},
//            {"ECH", {6, 30, 90, 270, 400, 550}},
//            {"PAS", {6, 30, 90, 270, 400, 550}},
//            {"HH", {8, 40, 100, 300, 450, 600}},
//            {"RCH", {10, 50, 150, 450, 625, 750}},
//            {"DWE", {10, 50, 150, 450, 625, 750}},
//            {"CPH", {12, 60, 180, 500, 700, 900}},
//            {"LHI", {14, 70, 200, 550, 750, 950}},
//            {"BMH", {14, 70, 200, 550, 750, 950}},
//            {"OPT", {16, 80, 220, 600, 800, 1000}},
//            {"EV1", {18, 90, 250, 700, 875, 1050}},
//            {"EV2", {18, 90, 250, 700, 875, 1050}},
//            {"EV3", {20, 100, 300, 750, 925, 1100}},
//            {"PHYS", {22, 110, 330, 800, 975, 1150}},
//            {"B1", {22, 110, 330, 800, 975, 1150}},
//            {"B2", {24, 120, 360, 850, 1025, 1200}},
//            {"EIT", {26, 130, 390, 900, 1100, 1275}},
//            {"ESC", {26, 130, 390, 900, 1100, 1275}},
//            {"C2", {28, 150, 450, 1000, 1200, 1400}},
//            {"MC", {35, 175, 500, 1100, 1300, 1500}},
//            {"DC", {50, 200, 600, 1400, 1700, 2000}}
//
//    };
//
//    cout << improvement_dict["DC"][1] << endl;

//    vector <int > ab = {1, 2, 3, 4};
//    cout << ab[1] << endl;
//    ab.erase(ab.begin() + 1);
//    cout << ab[1] << endl;
//
//    string abc;
//    cin >> abc;
//    cout << abc << endl;

//    srand (time(NULL));
//    int iSecret = rand() % 24 + 1;
//    cout << "iSecrete " << iSecret << endl;
//    //srand (time(NULL));
//    int iSecret_1 = rand() % 24 + 1;
//    cout << "iSecrete_1 " << iSecret_1 << endl;
    string osap = "         \n|COLLECT  |\n|OSAP     |\n|         |\n|         |\n|---------|\n";
    osap[35] = 'I';

    cout << osap << endl;

    class sq{
        int a;
    public:
        sq (int b){
            a = b;
        }
        sq (){};

        virtual int  get_a(){
            return a;
        }
    };

    class sq_sub : public sq {
        string c;
        int f;
    public:
        sq_sub (int b, string d, int e) : sq(b), c (d), f(e){

        }
        sq_sub() = default;

        void set_str (string d){
            c = d;
        }
        string get_str(){
            return c;
        }
//        int get_a (){
//            return f;
//        }


    };

    class sq_sub_dector : public sq_sub {
        sq_sub & component;
    public:
        sq_sub_dector (sq_sub & a) : component(a){

        }
        int get_a() override {
            cout << "in" << endl;
            return component.get_a();
        }
    };

    sq_sub * asd = new sq_sub(1, "ad" , 3);
    sq * abcdef = new sq_sub_dector(*asd);
    cout << abcdef -> get_a() << endl;

//    stringstream iss;
//    string dd = "aa";
//    iss.str(dd);
//
//    char d;
//    iss >> d;
//    cout << d << endl;

//    string dd;
//    string ee;
//    cin.exceptions(ios::failbit);
//    cin >> dd;
//    cout << dd << endl;
//    cin >> ee;
//    cout << ee << endl;
    string roll;
    getline(cin, roll);
    istringstream iss_roll(roll);
    string dd;
    iss_roll >> dd;
    iss_roll.ignore(INT_MAX);
//    cout << dd << endl;
//    cin >> roll;
//    istringstream iss_roll(roll);
//    iss_roll >> dd;
//    cout << dd << endl;


    return 0;


}
