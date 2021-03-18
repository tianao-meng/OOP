#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



int main() {

    int test;


    try
    {
        cin.exceptions( ios::eofbit|ios::failbit);
        cin >> test;
        //getline(cin, test);

        //throw ios::failure("worong");

    }
    catch (ios_base ::failure &e)
    {
        cout << "wrong" << endl;
        std::cout << e.what() << std::endl;
        //std::cout << std::cin.rdstate() << std::endl;

    }

    return 0;


}