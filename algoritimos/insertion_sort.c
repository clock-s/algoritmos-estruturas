#include <stdio.h>


void print_array(int* array, int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]){

    int array[] = {9, 8, 7, 2, 5, 4, 3, 2, 1};
    int array_size = sizeof(array)/sizeof(int);


    print_array(array, array_size);

    for(int i = 1 ; i < array_size ; i++){
        int key = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j--; 
        }
        array[j + 1] = key;

        //print_array(array, array_size);
    }

    print_array(array, array_size);

    
    return 0;
}
