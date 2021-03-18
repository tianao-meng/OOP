//
// Created by 孟天奥 on 2020-09-12.
//
#include "makefile.h"
#include <iostream>
#include <string>
using namespace std;

Makefile::Makefile(ostream &out) : out(out) {

    for (int i = 0; i < maxTargets; i++){
        touched[i] = "-1";
    }
    //cout << checked[0] << endl;
}

Makefile::~Makefile() {
    //cout << "in" << endl;
//    delete checked[maxTargets];
}

void Makefile::addDepend(const string &t, const string &d) {

    int flag_exist_t = 0;
    int flag_exist_d = 0;
    int index_t = 0;
    int index_d = 0;
    //cout << "in" << endl;
    for (int i = 0; i < NumTargets; i++){

        if (t == targets[i]->name){
            flag_exist_t = 1;
            index_t = i;
            continue;
        }

        if (d == targets[i]->name){
            flag_exist_d = 1;
            index_d = i;
            continue;
        }

    }
    //cout << "in" << endl;

    if (flag_exist_d == 0){
        index_d = NumTargets;

        if ((NumTargets + 1) > maxTargets){
            out << "Max targets exceeded" << endl;
            return;
        };

        Target * depend = new Target(d);
        //cout << "in" << endl;
        targets[NumTargets] = depend;

        NumTargets ++;
        //cout << "in" << endl;

    }

    if (flag_exist_t == 0){

        index_t = NumTargets;
        if ((NumTargets + 1) > maxTargets){
            out << "Max targets exceeded" << endl;
            return;
        };

        Target * target = new Target(t);
        targets[NumTargets] = target;
        NumTargets ++;

    }
    if (targets[index_t]->leaf == 1){
        targets[index_t]->leaf = 0;
    }
    targets[index_t] -> addDepend(targets[index_d]);
    targets[index_t] -> addFirstDepend(targets[index_d]);

    targets[index_d] -> addParent(targets[index_t]);
    //cout << "in" << endl;
    index_t = find_index(t);

    for (int i = 0; i < NumTargets; i++){
        if (i == index_t){
            continue;
        }

        for (int j = 0; j < maxDepends; j++){
            if (targets[i] -> depend[j] != nullptr){
                targets[i] -> addDepend(targets[index_d]);
            }

        }


    }



}

int Makefile::find_index(const string &t){

    int index;
    for (int i = 0; i < NumTargets; i++){

        if (targets[i] == nullptr){
            break;
        }

        if (targets[i]->name == t){
            index = i;
            break;
        }

    }
    return index;

}



int get_untouched_index ( string touched[]){
    int count = 0;
    for (int i = 0; i < maxDepends; i++){
        if (touched[i] == "-1"){
            return count;
        }
        count ++;
    }
    return count;
}

bool check_if_touched (string touched[], string ele){

    for (int i = 0; i < maxDepends; i++){
        if (touched[i] == ele){
            return true;
        }

    }
    return false;

}
void Makefile::changeTarget(const string &t) {
    //cout << "in" << endl;
    int index_t = find_index(t);

    if (targets[index_t] -> isLeaf()){
        global_time ++;
        targets[index_t] -> update(global_time);
        if (check_if_touched (touched, t)){
            for (int i = 0; i < maxDepends; i++){
                if (touched[i] == t){
                    touched[i] = "-1";
                }

            }
        }
        out << t << " updated at time " << targets[index_t] -> time_update << endl;

    } else {
        global_time ++;
        out << "Cannot update non-leaf object" << endl;
    }

}

void Makefile::rebuild(const string &t) {


    int index_t = find_index(t);

    int original = targets[index_t] -> time_update;


    for (int i = 0; i < maxDepends;){
        if (targets[index_t] -> time_update == global_time){
            for (int j = 0; j < maxDepends; j++ ){
                if ((targets[index_t] -> depend[j] != nullptr)
                        && (targets[index_t] -> depend[j] -> time_update != global_time) && (!targets[index_t] -> depend[j] -> isLeaf())){
//                    cout << "in " << endl;
//                  count = 0;
//                    for (int x =0; x < maxDepends; x++){
//
//                    }
                    rebuild(targets[index_t] -> depend[j] -> name);
                    //cout << targets[index_t] -> depend[j] -> name << endl;


//                    targets[index_t] -> depend[j] -> update(global_time);
//                    targets[index_t] -> depend[j] -> build();
                }
            }
            break;

        }

        // && (targets[index_t] -> depend[i] -> lastUpdated() <= targets[index_t] -> lastUpdated())
        if (targets[index_t] -> depend[i]  != nullptr){
            //cout << "in" << endl;
            if (check_if_touched(touched, targets[index_t] -> depend[i] -> name)&&
            (targets[index_t] -> depend[i] -> lastUpdated() <= targets[index_t] -> lastUpdated())){

                i++;
                continue;
            }

            if (((targets[index_t] -> depend[i] -> lastUpdated() > targets[index_t] -> lastUpdated()) && (!targets[index_t] -> depend[i] -> isLeaf()))){

                if (!check_if_touched(touched, targets[index_t] -> depend[i] -> name)){
                    int index_uncheck = get_untouched_index(touched);
                    touched[index_uncheck] = targets[index_t] -> depend[i] -> name;
                }

                for (int j = 0; j < (maxDepends - 1); j++){

                    if (targets[index_t] -> depend[i] -> parent[j] != nullptr){
                        targets[index_t] -> depend[i] -> parent[j] -> update(global_time);

                        targets[index_t] -> depend[i] -> parent[j] -> build();

                        if ((targets[index_t] -> depend[i] -> parent[j] -> name == t)){

                            break;
                        }


                    } else {
                        break;
                    }

                }
                i = 0;
                continue;


            }

            if ((targets[index_t] -> depend[i] -> isLeaf())
            && (targets[index_t] -> depend[i] -> time_update <= global_time)
            && (targets[index_t] -> depend[i] -> time_update > original)){
                if (check_if_touched(touched, targets[index_t] -> depend[i] -> name)){

                    continue;
                }

                if (!check_if_touched(touched, targets[index_t] -> depend[i] -> name)){
                    int index_uncheck = get_untouched_index(touched);
                    touched[index_uncheck] = targets[index_t] -> depend[i] -> name;
                }

                for (int j = 0; j < (maxDepends - 1); j++){

                    if (targets[index_t] -> depend[i] -> parent[j] != nullptr){
                        targets[index_t] -> depend[i] -> parent[j] -> update(global_time);
                        targets[index_t] -> depend[i] -> parent[j] -> build();
                        if ((targets[index_t] -> depend[i] -> parent[j] -> name == t) ){
                            break;

                        }

                    } else {
                        break;
                    }
                }
                i = 0;
                continue;
            }


        } else {

            break;
        }

        i++;
    }




}


