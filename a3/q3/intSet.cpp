//
// Created by 孟天奥 on 2020-09-16.
//
#include "intSet.h"
#include <iostream>
#include <string>
using namespace std;
intSet ::intSet() {

    size = 0;
    capacity = 0;
    data = new int [capacity];

}

intSet ::~intSet() {

    delete [] data;

}

void intSet :: swap(intSet &is){


    size = is.size;
    capacity = is.capacity;

    //cout <<is.size << endl;
    for (int i = 0; i < size; i++){

        data[i] = is.data[i];

    }

}
//deep copy constructor
intSet :: intSet(const intSet& is){
    //cout << "in" << endl;
    //delete [] data;
    data = new int [is.capacity];
    swap(const_cast<intSet &>(is));

}

// copy constructor only works for right value
intSet :: intSet(intSet &&is){

    //delete [] data;
    data = new int [is.capacity];
    swap(is);
    is.~intSet();
}


// deep assignment operator, this method increase speed and get rid of self assignment problem

intSet& intSet :: operator=(const intSet& is){

    data = (int *)realloc(data, is.capacity * sizeof(is.data[0]));
    swap(const_cast<intSet &>(is));
    //cout <<"in" << endl;
    return  *this;
}

//assignment operator for right value

intSet& intSet :: operator=(intSet &&is){
    //cout << "in" << endl;
    data = (int *)realloc(data, is.capacity * sizeof(is.data[0]));
    swap(is);
    delete [] is.data;
    is.size = 0;
    is.capacity = 0;
    return * this;

}

void intSet :: add(int e){

    if (check_if_in(data, size , e)){
        return;
    }

    if (size == capacity){

        if (size == 0){
            capacity = 5;
            delete [] data;
            data = new int [capacity];
            data[size] = e;
            size ++;
        } else {

            capacity = 2 * capacity;

            int temp [capacity];
            for (int i = 0; i < size; i++){
                temp[i] = data[i];
            }
            delete [] data;
            data = new int [capacity];
            for (int i = 0; i < size; i++){
                data[i] = temp[i];
            }
            data[size] = e;
            size ++;

        }

    } else {
        //cout << "in" << endl;
        data[size] = e;
        size++;
    }

}

intSet intSet :: operator&(const intSet &other){

    int n;
    intSet res;
    if (size < other.size){
        n = size;
        for (int i = 0; i < n; i++){
            //cout << data[i] << endl;
            for (int j = 0; j < other.size; j++){

                if (data[i] == other.data[j]){

                    res.add(data[i]);
                    break;

                }
            }

        }
    } else {
        n = other.size;
        for (int i = 0; i < n; i++){
            //cout << data[i] << endl;
            for (int j = 0; j < size; j++){

                if (other.data[i] == data[j]){

                    res.add(other.data[i]);
                    break;

                }
            }

        }
    }
    //cout << n << endl;


    return res;

}

bool check_if_in(int * arr, int size, int ele){

    for (int i = 0; i < size; i++){
        if (arr[i] == ele){
            return true;
        }
    }

    return false;


}

intSet intSet :: operator|(const intSet &other){

    intSet res;

    for (int i = 0; i < size; i++){
        if (!check_if_in(res.data, res.size, data[i])){
            res.add(data[i]);
        } else {continue;}
    }

    for (int i = 0; i < other.size; i++){
        if (!check_if_in(res.data, res.size, other.data[i])){
            res.add(other.data[i]);
        } else {continue;}
    }

    return res;
}

bool intSet :: operator==(const intSet &other){

    if (size != other.size){
        return false;
    }

    for (int i = 0; i < size; i++){

        if (data[i] != other.data[i]){
            return false;
        }

    }
    return true;
}

bool intSet :: isSubset(intSet s){
    if (size < s.size){
        return false;
    }

    for (int i = 0; i < s.size; i++){

        if (!check_if_in(data, size, s.data[i])){
            return false;
        }

    }

    return true;
}

bool intSet :: contains(int e){

    for ( int i = 0; i < size; i++){
        if (data[i] == e){
            return true;
        }
    }
    return false;
}

void intSet :: remove(int e){
    if (!check_if_in(data, size, e)){
        return;
    } else {
        int * new_data = new int [capacity];

        int index = 0;

        for (int i = 0; i < size; i++){
            if (data[i] != e){
                new_data[index] = data[i];
                index++;
            }
        }

        delete [] data;
        data = new_data;
        size = index;
    }
}

void swap_1 (int & ele_1, int & ele_2){

    int temp = ele_1;
    ele_1 = ele_2;
    ele_2 = temp;

}

void bubble_sort(int * arr, int size){
    //cout << "in";

    for (int i = 0; i < (size - 1); i++){

        for (int j = 0; j < (size - i - 1); j++){
            if(arr[ j ] > arr[j + 1]){
                swap_1(arr[j], arr[j + 1]);
            }


        }


    }

}
std::ostream& operator<<(std::ostream& out, const intSet& is){
    //cout << is.size << endl;

    bubble_sort(is.data, is.size);
    //cout << "in";

    if (is.size == 0){
        cout << "()" ;
        return out;
    }

    if (is.size == 1){
        cout << "(" << is.data[0] << ")";
        return out;
    }

    for (int i = 0; i < is.size; i++){


        if (i == 0){
            cout << "(" << is.data[i] << ",";
            continue;
        }




        if (i == (is.size - 1)){

            cout << is.data[i] << ")";
            continue;

        }

        cout << is.data[i] << ",";

    }
    return out;

}

