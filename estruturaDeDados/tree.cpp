#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node{
    int value;

    Node *pai = nullptr;
    Node *filho_esquerdo = nullptr, *filho_direito = nullptr;
};


class Tree{
    Node *Raiz = nullptr;
    void apagar(Node* &node);
    void pre_order_aux(Node *node);
    void pos_order_aux(Node *node);
    void in_order_aux(Node *node);
    void apagar_ponteiro(Node* &key);

public:
    ~Tree();
    void refazer(int size);
    void criar(int size);
    void apagar_valor(int key);
    void apaga_tudo();
    void pre_order();
    void pre_order_nao_recursivo();
    void pos_order();
    void in_order();
    void por_nivel();

};


void Tree::refazer(int size){
    if(size <= 0) return;

    this->apaga_tudo();

    Node* top = new Node;
    Raiz = top;

    queue<Node*> tree_queue;
    tree_queue.push(Raiz);

    for(int i = 1; i <= size ; i++){
        Node *p = tree_queue.front(); tree_queue.pop();

        p->value = i;

        if(i*2 <= size){
            Node *esqr = new Node;
            p->filho_esquerdo = esqr;
            esqr->pai = p;
            tree_queue.push(esqr);          
        }

        if(i*2 + 1 <= size){
            Node *dir = new Node;
            p->filho_direito = dir;
            dir->pai = p;
            tree_queue.push(dir);   
        }



    }



}


void Tree::criar(int size){
    this->refazer(size);
}



void Tree::apagar_ponteiro(Node* &key){
    if(key == nullptr) return;

    apagar_ponteiro(key->filho_esquerdo);
    apagar_ponteiro(key->filho_direito);

    delete key;
    key = nullptr;

}


void Tree::apaga_tudo(){
    this->apagar_ponteiro(this->Raiz);
}

void Tree::pre_order(){
    this->pre_order_aux(this->Raiz);
    cout << endl;
}

void Tree::pre_order_aux(Node* node){
    if(node == nullptr) return;

    cout << node->value << " ";

    pre_order_aux(node->filho_esquerdo);
    pre_order_aux(node->filho_direito);
}

void Tree::pre_order_nao_recursivo(){
    if(this->Raiz == nullptr) return;

    stack<Node*> tree_stack; tree_stack.push(this->Raiz);

    while (!tree_stack.empty()){
        Node *p = tree_stack.top(); tree_stack.pop();

        while(p != nullptr){
            cout << p->value << " ";
            
            if(p->filho_direito != nullptr) tree_stack.push(p->filho_direito);

            p = p->filho_esquerdo;


        }
        
    }
    
    cout << endl;

}



void Tree::pos_order(){
    this->pos_order_aux(this->Raiz);
    cout << endl;
}

void Tree::pos_order_aux(Node* node){
    if(node == nullptr) return;


    pos_order_aux(node->filho_esquerdo);
    pos_order_aux(node->filho_direito);

    cout << node->value << " ";
}




void Tree::in_order(){
    this->in_order_aux(this->Raiz);
    cout << endl;
}

void Tree::in_order_aux(Node* node){
    if(node == nullptr) return;

    

    in_order_aux(node->filho_esquerdo);
    cout << node->value << " ";
    in_order_aux(node->filho_direito);
}


void Tree::por_nivel(){
    if(this->Raiz == nullptr) return;
    

    queue<Node*> queue_tree;
    queue_tree.push(this->Raiz);

    while(!queue_tree.empty()){
        Node *p = queue_tree.front(); queue_tree.pop();

        cout << p->value << " ";

        if(p->filho_esquerdo != nullptr) queue_tree.push(p->filho_esquerdo);
        if(p->filho_direito != nullptr) queue_tree.push(p->filho_direito);


    }

    cout << endl;


}


Tree::~Tree(){
    apaga_tudo();
}

int main(int argc, char const *argv[]){

    Tree arvore;

    arvore.criar(7);
    arvore.pre_order();
    arvore.in_order();
    arvore.pos_order();
    arvore.por_nivel();
    arvore.pre_order_nao_recursivo();

    return 0;
}
