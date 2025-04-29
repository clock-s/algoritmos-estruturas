#include <iostream>
#include <stack>

#define NORMAL 0
#define REVERSE 1

using namespace std;

void att_expressao(stack<string> &num, stack<string> &oper, const bool rev);
string polonesa_para_expressao(string polonesa, bool rev = REVERSE);
string expressao_para_polonesa(string expressao, bool rev = REVERSE);
string expressao_para_polonesa_complexa(string expressao, bool rev = REVERSE);
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


void att_expressao(stack<string> &num, stack<string> &oper, const bool rev){
    string B = num.top(); num.pop(); 
    string A = num.top(); num.pop(); 
    string operador = oper.top(); oper.pop(); 

    string expressao;
    if(rev) expressao =  A + B + operador;
    else if(!rev) expressao = operador + A + B;

    
    num.push(expressao);
}


string expressao_para_polonesa_complexa(string expressao, bool rev){
    stack<string> num;
    stack<string> oper;

    for(int i = 0 ; i < expressao.size() ; i++){
        string caracter(1, expressao[i]);

        cout << "i: " << i << " " << caracter;
        if(!oper.empty()) cout << " " << oper.top();
        cout << endl;
        if(caracter == " ") continue; //Não é necessário analisar caso em que é branco
        else if(caracter == "(") oper.push(caracter);


        //Faz as operações com base na prioridade das operações, se o operador no topo da pilha tem mais prioridade que o atual, faz todas as operações
        //Previstas e depois coloca o novo operador na pilha
        else if(!num.empty() && !oper.empty() && (operador(caracter[0]) > 0) && (operador(caracter[0]) < operador(oper.top()[0]))){
            while(!oper.empty() && oper.top() != "(") att_expressao(num, oper, rev);
            if(!oper.empty() && oper.top() == "(") oper.pop();
            oper.push(caracter);
        }
            
        
        else if(operador(caracter[0]) > 0) oper.push(caracter); //Coloca os operadores na lista de operador e pula para o pŕoximo loop

        else if(caracter == ")" && !num.empty() && !oper.empty()){ //Realiza a operação
            while(!oper.empty() && oper.top() != "("){
                att_expressao(num, oper, rev);
                
            }
            if(!oper.empty() && oper.top() == "(") oper.pop();
        }

        else if(caracter != ")") num.push(caracter); //O que sobrar ou é letra ou número, então fica sendo considerado número e vai para pilha de numero
                                                     //No final, existe a chance de a expressao ter só um ), então impede de adicionar esse )

        if(!num.empty()) cout << num.top() << endl;
    }

    
    //Checagem final se o usuário não colocar o parentese mais externo
    while(!oper.empty()){
        att_expressao(num, oper, rev);
        if(!oper.empty() && oper.top() == "(") oper.pop();
    }


    return num.top(); //No fim, a pilha só terá um elemento sendo ele a polonesa final

}




string expressao_para_polonesa(string expressao, bool rev){
    stack<string> num;
    stack<string> oper;

    for(int i = 0 ; i < expressao.size() ; i++){
        string caracter(1, expressao[i]);

        if(caracter == "(" || caracter == " ") continue; //Não é necessário analisar caso em que é branco ou um ()

        else if(operador(caracter[0]) > 0) oper.push(caracter); //Coloca os operadores na lista de operador e pula para o pŕoximo loop

        else if(caracter == ")" && !num.empty() && !oper.empty()){ //Realiza a operação
            att_expressao(num, oper, rev);
        }

        else if(caracter != ")") num.push(caracter); //O que sobrar ou é letra ou número, então fica sendo considerado número e vai para pilha de numero
                                                    //No final, existe a chance de a expressao ter só um ), então impede de adicionar esse )
    }


    //Checagem final se o usuário não colocar o parentese mais externo
    while(!oper.empty()){
        att_expressao(num, oper, rev);
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

    string expresao = "A+B*C^D + D^E*F+G";

    string polonesa = expressao_para_polonesa_complexa(expresao);

    cout <<"Polonesa: " << polonesa << endl;

    string nova_expressao = polonesa_para_expressao(polonesa);

    cout << nova_expressao << endl;

    
    return 0;
}
