#include <iostream>

using namespace std;

int valor = 1;


void fibonacciLinear(int N, int anterior = 1, int posterior = 1);
int fibonacciArvore(int N);
long unsigned int fibonacciArvoreInteligente(int N, long unsigned int lista[]);


int main(){
  int N;

  cin >> N;

  long unsigned int* valores = new long unsigned int[N+1];
  for(int i = 0 ; i < N+1 ; i++) valores[i] = 0;

  fibonacciLinear(N);  cout << valor << endl;
  //cout << fibonacciArvore(N) << endl;
  cout << fibonacciArvoreInteligente(N, valores);



  delete[] valores;


  return 0;
}

void fibonacciLinear(int N, int anterior, int posterior){
  if(N <=1){
    return;
  }

  anterior = posterior + anterior;
  
  valor = posterior;
  
  fibonacciLinear(N-1,posterior,anterior);
}


int fibonacciArvore(int N){
  if(N <= 1) return N;

  return fibonacciArvore(N-1) + fibonacciArvore(N-2);

}


long unsigned int fibonacciArvoreInteligente(int N,long unsigned int lista[]){
  if(N <= 1) return N;
  if(lista[N] != 0) return lista[N];

  lista[N] = fibonacciArvoreInteligente(N-1, lista) + fibonacciArvoreInteligente(N-2,lista);

  return lista[N];

}



