#include <iostream>
#include <vector>

using namespace std;


int particion(vector<int> &array, int i, int j){
    int r;
    r = j-1;
    int key = j;
    

    while(i <= r){
        if(array[i] <= array[key]){
            i++;
        }else{
            swap(array[i], array[r]);
            r--;
        }

    }

    swap(array[i], array[key]);

    return i;

}

void quickSort(vector<int> &array, int i, int j){

    if(i >= j) return;
    if(i < 0 || j >= array.size()) return;
    
    int q = particion(array, i, j);

    // for(int index = 0 ; index < array.size() ; index++){
    //     cout << array[index] << " ";
    // }

    quickSort(array, i, q - 1);
    quickSort(array, q+1, j);

}

int main(int argc, char const *argv[])
{
    vector<int> array = {0, 20, 5, 10, 15, 35, 10, 28, 9, 7, 8, 10, 11};

    for(int i = 0 ; i < array.size() ; i++){
        cout << array[i] << " ";
    }

    cout << endl;

    quickSort(array, 0, array.size() - 1);

    for(int i = 0 ; i < array.size() ; i++){
        cout << array[i] << " ";
    }

    cout << endl;


    return 0;
}
