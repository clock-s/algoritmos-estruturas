#include <iostream>
#include <stack>

#define NORMAL 0
#define REVERSE 1

using namespace std;


string polonesa_para_expressao(string polonesa, bool rev = 1);
string expressao_para_polonesa(string expressao, bool rev = 1);
int operador(char caracter);


int operador(char caracter){

    switch (caracter){
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;
    default: return 0;
    }

}




string expressao_para_polonesa(string expressao, bool rev){
    stack<string> num;
    stack<string> oper;

    for(int i = 0 ; i < expressao.size() ; i++){
        string caracter(1, expressao[i]);

        if(caracter == "(" || caracter == " ") continue; //Não é necessário analisar caso em que é branco ou um ()

        else if(operador(caracter[0]) > 0) oper.push(caracter); //Coloca os operadores na lista de operador e pula para o pŕoximo loop

        else if(caracter == ")" && !num.empty() && !oper.empty()){ //Realiza a operação
            string B = num.top(); num.pop();
            string A = num.top(); num.pop();
            string operador = oper.top(); oper.pop();

            string expressao;
            if(rev) expressao =  A + B + operador;
            else if(!rev) expressao = operador + A + B;

            num.push(expressao);
        }

        else num.push(caracter); //O que sobrar ou é letra ou número, então fica sendo considerado número e vai para pilha de numero

    }


    //Checagem final se o usuário não colocar o parentese mais externo
    while(!oper.empty()){
        string B = num.top(); num.pop();
        string A = num.top(); num.pop();
        string operador = oper.top(); oper.pop();

        string expressao;
        if(rev) expressao =  A + B + operador;
        else if(!rev) expressao = operador + A + B;

        num.push(expressao);
    }

    
    return num.top(); //No fim, a pilha só terá um elemento sendo ele a polonesa final
}


string polonesa_para_expressao(string polonesa, bool rev){
    stack<string> expressao;
    int i  = rev ? 0 : polonesa.size() - 1; //Como elas são invertidas, a normal começa do fim, e a reversa do começo

    while(i >= 0 && i < polonesa.size()){
        string caracter(1, polonesa[i]);
        
        if(rev) ++i; else --i; 

        if(caracter == " ") continue;

        else if(operador(caracter[0]) > 0){
            if(expressao.empty()) return "error"; //Se chegar num operador a lista de expressão estiver vaiza é pq ta estranho, sai da função
            
            string B = expressao.top(); expressao.pop();
            string A = expressao.top(); expressao.pop();
            
            string key;
            if(rev) key =  "(" + A + caracter + B + ")";
            else if (!rev) key = "(" + B + caracter + A + ")"; 

            expressao.push(key);

        }
        
        else expressao.push(caracter);


    }



    return expressao.top();
}




int main(int argc, char const *argv[]){

    string expresao = "(((R + S) * T) - U)";

    string polonesa = expressao_para_polonesa(expresao, NORMAL);

    cout << polonesa << endl;

    string nova_expressao = polonesa_para_expressao(polonesa, NORMAL);

    cout << nova_expressao << endl;

    
    return 0;
}
