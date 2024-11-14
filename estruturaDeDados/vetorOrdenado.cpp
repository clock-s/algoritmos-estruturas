#include <iostream>

using namespace std;


class vetorOrdenado{
private:
  int quantidade = 0;
  int max;
  int *vetor;

public:
  vetorOrdenado(int tamanho)  : max(tamanho){
    vetor = new int[tamanho];
  }

  ~vetorOrdenado(){
    delete[] vetor;
  }

  void mostrar(){
    if(quantidade == 0){
      cout << "Não tem nada no vetor!\n";
      return;
    }

    for(int i = max-quantidade ; i < max ; i++){
      cout << vetor[i] << " - ";
    }
    cout << endl;
  }
  
  int busca(int i, int max, int min){

    int medio = (max+min)/2;

    if(max < min) return medio;

    if(vetor[medio] > i ) max = medio - 1;
    else if( vetor[medio] < i) min = medio + 1;
    else return medio;

    
    
    return busca(i,max,min);

  }

  void adicionar(int num){
    if(quantidade == 0){
      vetor[max-1] = num;
      quantidade++;
      return;

    } else if (quantidade == max){
      cout << "Vetor já está cheio!";
      return;

    } else {
      int posicao = busca(num,max-1,max-quantidade-1);
      
      for(int i = max-1-quantidade ; i < posicao+1 ; ++i){
        vetor[i-1] = vetor[i];
      }

      vetor[posicao] = num; 
      quantidade++;
      return;
    }
  }

};

int main(){
  vetorOrdenado vetor(12);

  vetor.mostrar();

  vetor.adicionar(1);
  vetor.mostrar();
  vetor.adicionar(3);
  vetor.mostrar();
  vetor.adicionar(2);
  vetor.mostrar();
  vetor.adicionar(4);
  vetor.mostrar();
  vetor.adicionar(10);
  vetor.mostrar();
  vetor.adicionar(51);
  vetor.mostrar();
  vetor.adicionar(52);
  vetor.mostrar();
  vetor.adicionar(10);
  vetor.mostrar();
  vetor.adicionar(5);
  vetor.mostrar();
  vetor.adicionar(25);
  vetor.mostrar();
  vetor.adicionar(103);
  vetor.mostrar();
  vetor.adicionar(1);
  vetor.mostrar();


}
