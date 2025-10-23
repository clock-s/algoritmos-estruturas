#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int int_pow(int i, int j){
    int key = 1;
    for(int k = 0 ; k < j ; k++){
        key *= i;
    }

    return key;
}


void countingSort(vector<float> &list, int d){
    int contador[10] = {};
    vector<float> B(list.size());

    for(int i = 0 ; i < list.size() ; i++){
        int digit = ((int)list[i] % int_pow(10, d))/int_pow(10, d-1);
        contador[digit]++;
    }

    for(int i = 1 ; i < 10 ; i++){
        contador[i] += contador[i-1];
    }

    for(int i = list.size()-1 ; i >= 0 ; i--){
        int digit = ((int)list[i] % int_pow(10, d) )/int_pow(10, d-1);

        B[contador[digit]-1] = list[i];
        contador[digit]--;
    }

    for(int i = 0 ; i < list.size() ; i++){
        list[i] = B[i];
    }
}



void radixSort(vector<float> &list){
    for(int i  = 0 ; i < list.size() ; i++){
        list[i] = list[i]*10;
    }

    for(int i = 1 ; i <= 3 ; i++){
        countingSort(list, i);
    }

    for(int i  = 0 ; i < list.size() ; i++){
        list[i] = list[i]/10;
    }
}


int main(int argc, char const *argv[])
{
    vector<float> list = {1.77, 17.82, 99.15, 42.67, 73.01, 8.94, 55.23, 88.49, 23.11, 60.05, 1.76, 
 36.98, 81.22, 14.50, 93.37, 49.99, 2.08, 68.61, 31.41, 75.57, 45.19};

    for(int i = 0 ; i < list.size() ; i++){
        cout << list[i] << " ";
    }

    cout << endl;

    radixSort(list);


    for(int i = 0 ; i < list.size() ; i++){
        cout << list[i] << " ";
    }

    cout << endl;

    return 0;
}
