#include <iostream>

#include <vector>
#include <stack>
using namespace std;
//void swap (int & ele_1, int & ele_2){
//
//    int temp = ele_1;
//    ele_1 = ele_2;
//    ele_2 = temp;
//
//}
//
//void bubble_sort(int * arr, int size){
//
//    for (int i = 0; i < (size - 1); i++){
//
//        for (int j = 0; j < (size - i - 1); j++){
//            if(arr[ j ] > arr[j + 1]){
//                swap(arr[j], arr[j + 1]);
//            }
//
//        }
//
//    }
//
//}

int main() {

    stack<int *> v;
    int a = 3;
    int b = 4;
    int * i = &a;
    int * j = &b;
    v.push(i);
    v.push(j);
    cout << *v.top() << endl;
    v.pop();

    cout << *v.top() << endl;
    v.pop();
    v.top();


//    int arr[5] = {2,5,6,1,3};
//    bubble_sort(arr, 5);
//
//    for (int i = 0; i < 5; i++){
//
//        std::cout << arr[i] << std::endl;
//    }

//    int * arr = new int [0];
//    delete [] arr;
//    arr = new int [5];
//    arr[0] = 1;
//    arr[1] = 2;
//    std :: cout << arr[1] << std :: endl;

    return 0;
}
