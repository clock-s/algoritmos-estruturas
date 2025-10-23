#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

void printVet(int *array, const int &size){
  for(int i = 0 ; i < size ; i++){
    cout << array[i] << " ";
  }

  cout << endl;
}

int *array_list;

int makeArray(){
  int size = 1000000;
  array_list = new int[size];

  for(int i = 0 ; i < size ; i++){
    array_list[i] = rand()%size;
  }

  return size;
}

void ordenar(int *lista, const int &size){
  for(int i = 0 ; i < size ; i++){
    for(int j = i; j < size ; j++){
      if(lista[j] < lista[i]) swap(lista[i],lista[j]);
    }
  }

}

int main(){
  srand(time(nullptr));
  
  int tamanho = makeArray();
  
  //printVet(array, tamanho);

  ordenar(array_list, tamanho);
  
  printVet(array_list,tamanho);
  
  return 0;
}

