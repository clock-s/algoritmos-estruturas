#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>



using namespace std;



int main(int argc, char const *argv[])
{
    srand(time(nullptr));
    int tamanho = 10;
    vector<int> x1(tamanho);
    vector<int> x2(tamanho);
    vector<int> x3(tamanho * 2);

    for(int i = 0 ; i < tamanho ; i++){
        x1[i] = rand()%100;
        x2[i] = rand()%100;
        x3[i] = x1[i];
        x3[i + tamanho] = x2[i];
    }

    sort(x1.begin(), x1.end());
    sort(x2.begin(), x2.end());
    sort(x3.begin(), x3.end());

    for(int i = 0 ; i < tamanho ; i++){
        cout << x1[i] << " ";
    }

    cout << endl;


    for(int i = 0 ; i < tamanho ; i++){
        cout << x2[i] << " ";
    }

    cout << endl;

    for(int i = 0 ; i < 2*tamanho ; i++){
        cout << x3[i] << " ";
    }

    cout << endl;

    int i1, j1, i2, j2;
    i1 = i2 = 0;
    j1 = j2 = tamanho-1;

    int c1, c2;
    int t1, t2;

    while (true){
        c1 = (i1+j1)/2;
        c2 = (i2+j2)/2;

        t1 = j1 - i1 + 1;
        t2 = j2 - i2 + 1;
        

        if(t1 <= 3 && t2 <= 3) break;

        if (x1[c1] < x2[c2]) {
            i1 = c1;
            j2 = c2 + (t2 % 2 == 0 ? 1 : 0);
        }
        else {
            j1 = c1 + (t1 % 2 == 0 ? 1 : 0); 
            i2 = c2;
        }
    
    
    }

    vector<int> x4;

    for(int i = i1 ; i <= j1 ; i++){
        x4.push_back(x1[i]);
    }

    for(int i = i2 ; i <= j2 ; i++){
        x4.push_back(x2[i]);
    }

    sort(x4.begin(), x4.end());

    int t4 = x4.size();
    float m4;


    if(t4 % 2 == 1) m4 = x4[t4/2];
    else m4 = float(x4[t4/2] + x4[t4/2 -1])/2.0;
    

    int meio = x3.size()/2;

    float rmed = float(x3[meio-1] + x3[meio])/2.0;

    cout << "Prat: " << m4 << " | Teo: "  << rmed << endl;



    return 0;
}
