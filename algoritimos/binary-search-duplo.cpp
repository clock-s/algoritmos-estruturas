#include <iostream>
#include <vector>

using namespace std;




int par_search(vector<int> array, int key){
    int min = 0;
    int max = ((array.size()-1)/2) * 2;
    int index = -1;


    while(min <= max && array[index] != key){
        index = (min + max)/2;
        if((index & 1) == 1){
            if(index + 1 < array.size()) index++;
            else if(index - 1 >= 0) index--;
        }


        if (array[index] < key) min = index + 1;
        if (array[index] > key) max = index - 1;
    
        if(min > max ){
            index = -1;
            break;
        }

    }


    return index;
}


int impar_search(vector<int> array, int key){
    int min = 1;
    int max = array.size()-1;
    int index = -1;

    if((max & 1) == 0) max--;



    while(min <= max && array[index] != key){
        index = (min + max)/2;

        if((index & 1) == 0){
            if(index + 1 < array.size()) index++;
            else if(index - 1 >= 0) index--;
        }


        if (array[index] < key) max = index - 1;
        if (array[index] > key) min = index + 1;
    
        if(min > max ){
            index = -1;
            break;
        }

    }

    if(array[index] != key) index = -1;



    return index;
} 


int search(vector<int> &array, int &key){
    int index;
    
    index = par_search(array, key);
    if(index != -1) return index;

    index = impar_search(array, key);


    return index;
}


int main(int argc, char const *argv[]){
    vector<int> array = {1,50,2,40,3,30,4,20,5,10};

    

    for(int i = 0 ; i < array.size() ; i++){
        int index = search(array, array[i]);

        if(index != -1){
            cout << "Achei: " << array[index] << " index: " << index;
        }else{
            cout << "Não achei!";
        }
    
        cout << endl;
    }
    
    

    return 0;
}
