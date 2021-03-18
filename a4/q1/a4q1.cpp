#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char * argv[]) {

    //cin.exceptions(ios::eofbit|ios::failbit);
    int total_all_nums = 0;
    int num_of_non_numbers = 0;

    int num = 0;
    string buffer;

    string non_exist;

    for (int i = 1; i < argc; i ++){

        ifstream infile;
        infile.exceptions(ios::eofbit|ios::failbit);

        try{
            infile.open (argv[i]);
            while (true){

                try{

                    infile >> num;
                    total_all_nums += num;

                } catch(ifstream::failure &e){
                    if(!infile.eof()){

                        infile.clear();
                        infile >> buffer;
                        num_of_non_numbers ++;

                    } else {

                        break;
                    }

                }

            }

//            while(true){
//
//                if (infile >> num){
//
//                    total_all_nums += num;
//
//
//                } else{
//                    if(!infile.eof()){
//
//                        infile.clear();
//                        infile >> buffer;
//                        num_of_non_numbers ++;
//
//                    } else {
//                        break;
//                    }
//                }
//
//
//            }


        } catch (ifstream::failure &e){
            non_exist += argv[i];


            if (i != (argc - 1) ){
                non_exist += " ";
            }

        }



    }
    cout << "Non-existent files: " << non_exist << endl;
    cout << "Total of all numbers: " << total_all_nums << endl;
    cout << "Total number of non-numbers: " << num_of_non_numbers << endl;
    return 0;
}
