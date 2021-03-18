#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;

struct IntArray {
    int size;
    int capacity;
    int *contents;
};


// readIntArray() read the ints and put them into array,return an IntArray
// effect: allocates heap for array
// time: O(n)
IntArray readIntArray();

// addToIntArray(intary)read original array and  add ints into array
// effect: allocates heap for array
// time: O(n)
void addToIntArray(IntArray& intary);

//printIntArray(a) print the item of the array
void printIntArray(const IntArray& a);

//copyary(size,oldar[],newar[]) coty the item of oldar to newar
// effect: delete oldar[]
// time: O(n)
void copyary(int size,int oldar[], int newar[]);

// Do not change this function!

int main() {  // Test harness for IntArray functions.
    bool done = false;
    IntArray a[4];
    a[0].contents = a[1].contents = a[2].contents = a[3].contents = 0;

    while (!done) {
        char c;
        char which;

        // Note:  prompt prints to stderr, so it should not occur in .out files
        //cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
        //                  +a, +b, +c, +d,
        //                  pa, pb, pc, pd, q
        cin >> c;  // Reads r, +, p, or q
        //cout << c << endl;
        if (cin.eof()) break;
        switch (c) {
            cout << c << endl;
            case 'r':
                cin >> which;  // Reads a, b, c, or d
                //cout << which;
                delete[] a[which - 'a'].contents;
                a[which - 'a'].contents = 0;
                a[which - 'a'] = readIntArray();
                //cout << which << endl;
                break;
            case '+':
                cin >> which;  // Reads a, b, c, or d
                addToIntArray(a[which - 'a']);
                break;
            case 'p':
                cin >> which;  // Reads a, b, c, or d
                printIntArray(a[which - 'a']);
                cout << "Capacity: " << a[which - 'a'].capacity << endl;
                break;
            case 'q':
                done = true;


        }
    }
    for (int i = 0; i < 4; ++i) delete [] a[i].contents;

}

//copyary(size,oldar[],newar[]) coty the item of oldar to newar
// effect: delete oldar[]
// time: O(n)
void copyary(int size,int oldar[], int newar[]){

    for (int i = 0; i < size; i ++){
        newar[i] = oldar[i];
    }

    delete [] oldar;
}

// readIntArray() read the ints and put them into array,return an IntArray
// effect: allocates heap for array
// time: O(n)
IntArray readIntArray(){

    int ele;
    IntArray  output;
    output.size = 0;
    output.capacity = 0;
    output.contents = new int [0];
    while (1){
        cin >> ele;
        if (cin.fail()){

            if (cin.eof()){
                break;
            }

            cin.clear();
            cin.ignore();
            break;
        }

        if (output.size == output.capacity){

            if (output.size == 0){
                int * newar = new int [5];
                output.capacity = 5;
                output.contents = newar;
                output.contents[0] = ele;
                output.size ++;
                continue;
            }


            int * newar = new int[(output.size) * 2];
            copyary(output.size,output.contents, newar);
            output.capacity = output.capacity * 2;
            output.contents = newar;
            output.contents[(output.size)] = ele;
            output.size ++;
            continue;
        }

        output.contents[(output.size)] = ele;
        output.size ++;


    }

    return output;
}



// addToIntArray(intary)read original array and  add ints into array
// effect: allocates heap for array
// time: O(n)
void addToIntArray(IntArray& intary){

    int ele;
    while (true){
        cin >> ele;
        if (cin.fail()){

            if (cin.eof()){
                break;
            }

            cin.clear();
            cin.ignore();
            break;
        }

        if (intary.size == intary.capacity){

            if (intary.size == 0){
                int * newar = new int [5];
                intary.capacity = 5;
                intary.contents = newar;
                intary.contents[0] = ele;
                intary.size ++;
                continue;
            }


            int * newar = new int[(intary.size) * 2];
            copyary(intary.size,intary.contents, newar);
            intary.capacity = intary.capacity * 2;
            intary.contents = newar;
            intary.contents[(intary.size)] = ele;
            intary.size ++;
            continue;
        }

        intary.contents[(intary.size)] = ele;
        intary.size ++;

    }

}


//printIntArray(a) print the item of the array
void printIntArray(const IntArray& a){

    if (a.size == 0){
        cout << endl;
    }

    for (int i = 0; i < a.size; i++){

        if ( i == (a.size - 1) ){

            cout << a.contents[i] << " " << endl;
            break;
        }

        cout << a.contents[i] << " ";


    }

}
