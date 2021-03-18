
#include <iostream> // cin, cout, cerr
#include <iomanip> // manipulators
#include <sstream>
using namespace std;

void  merge(int arr[], int start_pos, int mid_pos, int end_pos){
    //cout << "in" << endl;
    int left_length = mid_pos - start_pos + 1;
    int right_length = end_pos - mid_pos;
    int left[left_length];
    int right [right_length];

    for (int i = 0; i < left_length; i += 1){
        left[i] = arr[start_pos + i];
    }

    for (int i = 0; i < right_length; i += 1){
        right[i] = arr[mid_pos + i + 1];
    }

    int left_index = 0;
    int right_index = 0;
    int i = 0;
    for (i; left_index < left_length && right_index <right_length; i+=1){
        //cout << i << endl;
        if (left[left_index] <= right[right_index]){

            arr[start_pos + i] = left[left_index];
            left_index += 1;
            continue;
        }

        if (left[left_index] > right[right_index]){

            arr[start_pos + i] = right[right_index];
            right_index += 1;
            continue;

        }

    }

    while (left_index < left_length){
        arr[ start_pos + i ] = left[left_index];
        i += 1;
        left_index += 1;
    }

    while (right_index < right_length){
        arr[ start_pos + i ] = right[right_index];
        i += 1;
        right_index += 1;
    }



}

void merge_sort(int arr[], int start_pos, int end_pos){

    if (start_pos < end_pos){
        int left_end_pos = start_pos + (end_pos - start_pos) / 2;
        merge_sort(arr, start_pos, left_end_pos);
        merge_sort(arr, (left_end_pos + 1), end_pos);
        //int mid_pos = start_pos + (end_pos - 1) / 2;
        merge(arr, start_pos, left_end_pos, end_pos);
    }


}


void change (int CoinDenArr [], int total, int CoinType, int res[]){



    for (int i = (CoinType - 1); i >= 0; i --) {
        //cout << i << endl;
        int Coin = CoinDenArr[i];

        //cout << Coin << endl;
        for (int j = 1; ; j ++) {
            //cout << j * Coin << endl;
            if ((j * Coin) > total) {
                //cout << i << endl;
                res[i] = (j - 1);
                total = total - ((j - 1) * Coin);
                //cout << res[0] << endl;
                break;
            }

        }

    }




}






int main() {



    int temp_array[10];
    int temp;
    int count = 0;
    while (cin >> temp){
        temp_array[count] = temp;
        count += 1;
    }

    int CoinType = temp_array[0];
    int total = temp_array[1 + CoinType];
    int CoinDenArr [CoinType];

    for (int i = 1; i <= CoinType; i += 1){
        CoinDenArr[i - 1] = temp_array[i];
    }
    merge_sort(CoinDenArr, 0, CoinType - 1);
    int res [CoinType];
    change(CoinDenArr, total, CoinType, res);

    int res_total = 0;
    for (int i = 0; i < CoinType; i++){

        res_total += (res[i] * CoinDenArr[i]);

    }

    if (res_total != total){
        cout << "Impossible" << endl;
    } else{

        for (int i = CoinType - 1; i >= 0; i --){

            if (res[i] != 0){
                cout << res[i] <<" " << "x" << " " << CoinDenArr[i] << endl;

            }

        }

    }
//    for (int i = 0; i < CoinType; i += 1){
//
//        cout << "CoinDen" << CoinDenArr[i] << ": " <<  res[i] << endl;
//    }


//    cout << "CoinType: " << CoinType << endl;
//
//    for (int i = 0; i < CoinType; i += 1){
//
//        cout << "CoinDen" << i << ": " <<  CoinDenArr[i] << endl;
//    }
//
//    cout << "Total: " << total << endl;

    return 0;

}