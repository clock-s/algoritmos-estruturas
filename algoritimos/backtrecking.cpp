#include <iostream>
#define N 11
using namespace std;
int contador = 0;
int tentativas = 0;
char mostrador[N][N];

void mata(char map[][N], int i, int j);
void volta(char map[][N], int i, int j);
void rainha(char map[][N], int number, int iNext);
void display(char map[][N]);

struct matriz {
  char auxiliar[N][N];
};

int main() {
  char mapa[N][N];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      mapa[i][j] = '#';
    }
  }

  rainha(mapa, -1, 0);

  display(mostrador);

  cout << "Max: " << contador << " | Mapas: " << tentativas << "\n";

  return 0;
}

void copia(char map[][N], char auxiliar[][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      auxiliar[i][j] = map[i][j];
    }
  }
}

void rainha(char map[][N], int number, int iNext) {

  tentativas++;

  number++;

  matriz *vetor = new matriz;

  copia(map, vetor->auxiliar);

  for (int i = iNext; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (vetor->auxiliar[i][j] == '#') {
        mata(vetor->auxiliar, i, j);
        rainha(vetor->auxiliar, number, i + 1);
        copia(map, vetor->auxiliar);
      }
    }
  }

  if (number > contador) {
    copia(vetor->auxiliar, mostrador);
    display(vetor->auxiliar);
    contador = number;
  }

  delete vetor;
}

void mata(char map[][N], int i, int j) {
  for (int r = 0; r < N; r++)
    map[r][j] = 'X';
  for (int c = 0; c < N; c++)
    map[i][c] = 'X';

  for (int c = j, r = i; r < N && c < N; r++, c++)
    map[r][c] = 'X';
  for (int c = j, r = i; r > -1 && c < N; r--, c++)
    map[r][c] = 'X';
  for (int c = j, r = i; r < N && c > -1; r++, c--)
    map[r][c] = 'X';
  for (int c = j, r = i; r > -1 && c > -1; r--, c--)
    map[r][c] = 'X';

  map[i][j] = '@';
}

void display(char map[][N]) {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << map[i][j] << " ";
    }
    cout << '\n';
  }

  cout << "\n ------------ \n";
}
