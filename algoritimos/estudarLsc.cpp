// -----------------------------------------------------------------
// ---- Algoritmos de Programação Dinâmica -------------------------
// ---- LCS (Longest Common Subsequence) ---------------------------
// ---- Calcular o tamanho da LCS(x,y) de duas strings x e y -------
// -----------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;


int LCS_pd (string x, string y);
int LCS_mem(string x, string y);

// -------------------------------------------------------------
// --- MAIN ----------------------------------------------------
// -------------------------------------------------------------
int main() {
    string x = "ABCBDAB";
    string y = "BDCABA";
    // LCS = BCBA, BCAB, BDAB,
    cout << "Entrada X = " << x << "\n";
    cout << "Entrada Y = " << y << "\n\n";

    cout << "LCS-pd : " << LCS_pd (x,y) << "\n";
    cout << "LCS-mem: " << LCS_mem(x,y) << "\n";

    return 0;
}


// --------------------------------------------
// PROGRAMAÇÃO DINÂMICA (não recursivo, melhor)
// --------------------------------------------
int LCS_pd(string x, string y) {
    int i, j;
    int m = x.size();
    int n = y.size();
    vector<vector<int>> c(m+1, vector<int>(n+1));//matriz c[m+1][n+1]

    for (i=0; i<=m; i++) c[i][0] = 0;
    for (j=0; j<=n; j++) c[0][j] = 0;

    for (i=1; i<=m; i++) {
        for (j=1; j<=n; j++) {
            if (x[i-1]==y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            } else if (c[i-1][j]>=c[i][j-1]) {
                c[i][j] = c[i-1][j];
            } else {
                c[i][j] = c[i][j-1];
            }
        }
    }
    return c[m][n];
}

// --------------------------------------------
// MEMOIZAÇÃO (recursivo com memória, bom)
// --------------------------------------------
int LCS_mem2(string x, string y, int i, int j, vector<vector<int>>& c) {
    if (c[i][j]>=0) return c[i][j];

    if (x[i-1]==y[j-1]) {
        int r = LCS_mem2(x,y,i-1,j-1,c);
        c[i][j] = r + 1;
    } else {
        int r1 = LCS_mem2(x,y,i-1,j,c);
        int r2 = LCS_mem2(x,y,i,j-1,c);
        if (r1>=r2) c[i][j]=r1; else c[i][j]=r2;
    }
    return c[i][j];
}

int LCS_mem(string x, string y) {
    int i, j;
    int m = x.size();
    int n = y.size();
    vector<vector<int>> c(m+1, vector<int>(n+1,-1));//matriz c[m+1][n+1]

    for (i=0; i<=m; i++) c[i][0] = 0;
    for (j=0; j<=n; j++) c[0][j] = 0;

    return LCS_mem2(x,y,m,n,c);
}
