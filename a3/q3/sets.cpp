//
// Created by 孟天奥 on 2020-09-16.
//

#include "sets.h"

Sets :: Sets() {

    size = 0;
    capacity = 0;
    data = new intSet [capacity];

}

Sets ::~Sets() {

    delete [] data;

}

void Sets :: add(intSet e){

    if (size == capacity){

        if (size == 0){
            capacity = 5;
            delete [] data;

            data = new intSet [capacity];
            //std :: cout << size << std :: endl;

            data[size] = e;
            //std :: cout << "in" << std :: endl;
            size ++;
            //std :: cout << size << std :: endl;

        } else {

            capacity = 2 * capacity;

            intSet  temp[capacity];
            for (int i = 0; i < size; i ++){
                temp[i] = data[i];
            }

            delete [] data;
            data = new intSet[capacity];
            for (int i = 0; i < size; i++){
                data[i] = temp[i];
            }

            data[size] = e;
            size++;
        }

    } else {
        data[size] = e;
        size++;
    }

}