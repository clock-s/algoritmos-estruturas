#include <iostream>
#include <vector>
#define max 1000000

using namespace std;

/*
  Na busca gulosa, usamos somente a Heuristica,
  no algoritimo A*, usamos heuristica como forma
  de auxiliar no trabalho de busca;
*/


/*
  arad - 0
  zerind - 1
  orades - 2
  sabiu - 3
  fragras - 4
  Rimicu - 5
  pristini 6
  Trimara - 7
  Lupoji - 8
  Mahdi - 9
  Dobreta - 10
  Clava - 11
  Bucareste - 12

*/

struct vertice{
  int cidade;
  int distancia;
};

int main (int argc, char *argv[]) {
  vector<vector<vertice>> cidades;

  int heuristica[] = {366,374,380,253,178,193,98,329,244,241,242,160,0};
  
  cidades.resize(13);
  
  cidades[0] = {{1,75},{7,118}, {3,140}};
  cidades[1] = {{2,71}};
  cidades[2] = {{3,151}};
  cidades[3] = {{4,99},{5,80}};
  cidades[4] = {{12,211}};
  cidades[5] = {{6,97},{11,146}};
  cidades[6] = {{12,101}, {11,138}};
  cidades[7] = {{8,11}};
  cidades[8] = {{9,70}};
  cidades[9] = {{10,75}};
  cidades[10] = {{11,120}};
  cidades[11] = {{5,145},{6,138}};
  cidades[12] = {{12,0}};

  
  int vertice = 0, distancia = max, min = -1;

  cout << vertice << endl;

  do{
    for(int i = 0 ; i < cidades[vertice].size() ; i++){
      if(cidades[vertice][i].distancia + 
        heuristica[cidades[vertice][i].cidade] < distancia){
        distancia = cidades[vertice][i].distancia + heuristica[cidades[vertice][i].cidade];
        min = cidades[vertice][i].cidade;
      }
    }
    vertice = min;  distancia = max;  min = -1;
    
    cout << vertice << endl;


  }while(vertice != 12);


  return 0;
}
