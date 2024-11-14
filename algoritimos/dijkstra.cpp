#include <iostream>
#define max 1147483647


using namespace std;

enum estados {percorrido, nao_percorrido};

int main(){
  int N;
  cout << "N total de vertice: ";
  cin >> N; 

  int **vertice = new int*[N];
  for(int i = 0 ; i < N ; i++) vertice[i] = new int[N];
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      vertice[i][j] = -1;
    }
  }
  int *distancia = new int[N];
  estados *estado = new estados[N];


  while(true){
    int i, j, distancia;

    cout << "De: "; cin >> i;
    if(i == -1 ) break;
    cout << "Para: "; cin >> j;
    cout << "Distancia: "; cin >> distancia;

    vertice[i][j] = distancia;

  }

  for(int i = 0 ; i < N ; i++){
    distancia[i] = max;
    estado[i] = nao_percorrido;
  }

  int pontoZero;
  cout << "Escolha seu ponto de partida: "; cin >> pontoZero;
  distancia[pontoZero] = 0;


  while(true){
    int min = max; int analisado = -1;
    for(int i = 0 ; i < N ; i++){
      if(distancia[i] < min && estado[i] == nao_percorrido){
        min = distancia[i];
        analisado = i;
      }
    }

      if(analisado == -1) break;

      for(int i = 0 ; i < N ; i++){
        if(vertice[analisado][i] != -1){
          if(distancia[analisado] + vertice[analisado][i] < distancia[i]){
            distancia[i] = distancia[analisado] + vertice[analisado][i];
          }
        }
      }

      estado[analisado] = percorrido;
      cout << "Analise de " << analisado << " completa!" << endl;

  }




  for(int i = 0 ; i < N ; i++){
    cout << pontoZero << " >>>> " << i << " = ";
    if(distancia[i] != max) cout << distancia[i];
    else cout << "Infinito!"; 
    
    cout << endl;
  }

















  
  for(int i = 0 ; i < N ; i++) delete[] vertice[i];
  delete[] vertice;
  delete[] distancia;
  delete[] estado;


  return 0;
}
