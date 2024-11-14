#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void separa(int *lista, int inicio, int fim);
void ordena(int *lista, const int &a, const int &b, const int &c);

void ordenandoVetor(int *vetor, int tamanho){
  separa(vetor, 0, tamanho-1);
}

int main(){
  srand(time(nullptr));
  int tamanho = rand()%100;
  int *vetor = new int[tamanho];
  

  for(int i = 0 ; i < tamanho ; i++){
    vetor[i] = rand()%100;
  }

  for(int i = 0 ; i < tamanho ; i++){
    cout << vetor[i] << " ";
  }

  cout << "\n\n";

  ordenandoVetor(vetor, tamanho);

  for(int i = 0 ; i < tamanho ; i++){
    cout << vetor[i] << " ";
  }

  cout << "\nFim\n";

  delete[] vetor;

  return 0;
}

void separa(int *lista, int inicio, int fim){
  int meio = (inicio+fim)/2;

  if(inicio == fim) return;
  else{
    separa(lista,inicio,meio);
    separa(lista,meio+1,fim);
  }
  

  ordena(lista,inicio, meio, fim);

}

void ordena(int *lista, const int &a, const int &b, const int &c){
  int tamanho = c-a+1;
  int *vetor = new int[tamanho];
  int i1 = a;
  int j1 = b;

  int i2 = b+1;
  int j2 = c;

  int posicao = 0;


  while(posicao < tamanho){

    if(i1 > j1){
      for(int i = i2 ; i <= j2 ; i++, posicao++){
        vetor[posicao] = lista[i];
      }
    }else if (i2 > j2){
      for(int i = i1 ; i <= j1 ; i++, posicao++){
        vetor[posicao] = lista[i];
      }
    }else{
      if(lista[i1] < lista[i2]){
        vetor[posicao] = lista[i1];
        i1++;
      }else if(lista[i2] < lista[i1]){
        vetor[posicao] = lista[i2];
        i2++;
      }else{
        vetor[posicao] = lista[i1];
        posicao++;
        vetor[posicao] = lista[i2];
        i1++; i2++;
      }
    }


    posicao++;

  }


  for(int i = 0 ; i < tamanho ; i++){
    lista[a + i] = vetor[i];
  }


  delete[] vetor;


}


