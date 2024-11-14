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




void ordenar(int *lista, const int &i, const int &size){
  int left = i*2 + 1;
  int righ = i*2 + 2;
  
  int high = i;

  
  //cout << "left: ";
  if(left < size && lista[left] > lista[high]){
    high = left;
  }
  //cout << "\nRigh: ";
  if(righ < size && lista[righ] > lista[high]){
    high = righ;
  }

  if(high != i){
    //cout << "Erro!";
    swap(lista[i],lista[high]);

    ordenar(lista, high, size);
  }
  
}


void escolhendo(int *lista, const int &size){
  for(int i = size/2-1 ; i >= 0 ; i--){
    ordenar(lista,i,size);
  }


  for(int i = size -1 ; i > 0 ; i--){
    swap(lista[0],lista[i]);

    ordenar(lista,0,i);


  }
}

int *array;

int makeArray(){
  int size = 1000000;
  array = new int[size];

  for(int i = 0 ; i < size ; i++){
    array[i] = rand()%size;
  }

  return size;
}

int main(){
  srand(time(nullptr));
  
  int tamanho = makeArray();
  
  //printVet(array, tamanho);

  escolhendo(array, tamanho);
  
  printVet(array,tamanho);
  
  return 0;
}
