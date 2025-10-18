#include <iostream>
#include <queue>

using namespace std;


struct Node{
    Node *dad;
    Node *left;
    Node *right;
    int value;
    int size;
    int height; 

    Node(int value, Node *dad = nullptr);
};

Node::Node(int value, Node *dad){
    this->value = value;
    this->dad = dad;
    this->size = 0;
    this->height = 0;
}


class Binary_Tree{
    protected:
    Node *root;

    void delete_tree(Node *node);
    void pos_order_aux(Node *node);
    void pre_order_aux(Node *node);
    void in_order_aux(Node *node);
    void transplant(Node *removed, Node *transplanted);
    void att_height_size(Node *node);
    int get_height(Node *node);
    int get_size(Node *node);
    
    

    public:

    Binary_Tree();
    ~Binary_Tree();

    void insert(int value);
    Node* search(int key);
    void remove(int key);

    void pos_order();
    void pre_order();
    void in_order();
    void BFS();
    
    
    Node* find_min();
    Node* find_min_aux(Node *node);
    Node* find_max();
    Node* find_max_aux(Node *node);
    Node* sucessor(Node *node);
    Node* predecessor(Node *node);
    Node* element_by_position(int x);
    int position_by_element(Node *node);
    
};


void Binary_Tree::delete_tree(Node *node){
    if(node == nullptr) return;

    delete_tree(node->left);
    delete_tree(node->right);

    delete node;
}

Node* Binary_Tree::search(int key){
    Node *p = this->root;


    while(p != nullptr && p->value != key){
        if(p->value > key){
            p = p->left;
        }
        else if(p->value < key){
            p = p->right;
        }
    }

    return p;
}

int Binary_Tree:: get_height(Node *node){
    if(node == nullptr) return -1;
    else return node->height;
}

int Binary_Tree:: get_size(Node *node){
    if(node == nullptr) return 0;
    else return node->size;
}

void Binary_Tree::att_height_size(Node *node){
    if(node == nullptr) return;


    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    node->size = get_size(node->left) + get_size(node->right) + 1;

    att_height_size(node->dad);

}


void Binary_Tree::insert(int value){
    if(this->root == nullptr){
        this->root = new Node(value);
        return;
    }

    Node *son = this->root;
    Node *dad = this->root;


    while(son != nullptr){
        dad = son;

        if(son->value > value){
            son = son->left;
        }
        else if(son->value <= value){
            son = son->right;
        }
    }

    son = new Node(value, dad);

    if(son->value >= dad->value){
        dad->right = son;
    }
    else if(son->value < dad->value){
        dad->left = son;
    }

    att_height_size(son);

}


void Binary_Tree::transplant(Node *removed, Node *transplanted){
    

    if(removed->dad == nullptr){
            this->root = transplanted;
            transplanted->dad = nullptr;
    }else{
        if(removed == removed->dad->right) removed->dad->right = transplanted;
        else if(removed == removed->dad->left) removed->dad->left = transplanted;

        if(transplanted != nullptr) transplanted->dad = removed->dad;
    }

    if(transplanted != nullptr){
        if(removed->left != transplanted) transplanted->left = removed->left;
        if(removed->right != transplanted) transplanted->right = removed->right;
        if(removed->left != nullptr && removed->left != transplanted) removed->left->dad = transplanted;
        if(removed->right != nullptr && removed->right != transplanted) removed->right->dad = transplanted;
    }
    

    
    removed->left = nullptr;
    removed->right = nullptr;



}

void Binary_Tree::remove(int key){
    Node *node = search(key);

    if(node == nullptr) return;

    cout << endl << "Removendo o valor: " << node->value << endl;

    Node *dad = node->dad;

    if(node->left == nullptr && node->right == nullptr){
        
        transplant(node, nullptr);
        
        
    }else if(node->right != nullptr){
        Node *min = find_min_aux(node->right);
        Node *new_position = node->right;



        if(min == new_position){            

            transplant(node, min);

            att_height_size(min); //NOTE:CHECAR, MAS ACHO QUE DA CERTO
            
        }else if(min != new_position){
            min->dad->left = min->right;
            Node *min_dad = min->dad;

            if(min->right != nullptr){
                min->right->dad = min->dad;
            }
        
            transplant(node, min);

            att_height_size(min_dad); //NOTE:CHECAR, MAS ACHO QUE DA CERTO
        }

        

    }else if(node->left != nullptr){
        Node *new_position = node->left;

        transplant(node, new_position);

        att_height_size(new_position); //NOTE:CHECAR, MAS ACHO QUE DA CERTO
    }



    delete_tree(node);


}

Binary_Tree::Binary_Tree(){
    this->root = nullptr;
}

Binary_Tree::~Binary_Tree(){
    delete_tree(this->root);
}

void Binary_Tree::pos_order(){
    pos_order_aux(this->root);
}

void Binary_Tree::pos_order_aux(Node *node){
    if(node == nullptr) return;

    pos_order_aux(node->left);
    pos_order_aux(node->right);

    cout << node->value << " ";

}

void Binary_Tree::pre_order(){
    pre_order_aux(this->root);
}

void Binary_Tree::pre_order_aux(Node *node){
    if(node == nullptr) return;

    cout << node->value << " ";

    pre_order_aux(node->left);
    pre_order_aux(node->right);

}

void Binary_Tree::in_order(){
    in_order_aux(this->root);
}

void Binary_Tree::in_order_aux(Node *node){
    if(node == nullptr) return;

    in_order_aux(node->left);

    cout << node->value << " ";

    in_order_aux(node->right);

}


void Binary_Tree::BFS(){
    if(this->root == nullptr) return;

    queue<Node*> tree;

    tree.push(this->root);

    Node *p;

    int next_layer = 1;
    int actual_node = 1;


    while(!tree.empty()){
        p = tree.front(); tree.pop();

        cout << p->value << " ";
        
        if(p->left != nullptr) tree.push(p->left);
        if(p->right != nullptr) tree.push(p->right);

    }

}

Node* Binary_Tree::find_min_aux(Node *node){
    if(node == nullptr) return nullptr;

    if(node->left != nullptr) return find_min_aux(node->left);
    return node;
}

Node* Binary_Tree::find_min(){
    return find_min_aux(this->root);
}


Node* Binary_Tree::find_max_aux(Node *node){
    if(node == nullptr) return nullptr;

    if(node->right != nullptr) return find_max_aux(node->right);
    return node;
}

Node* Binary_Tree::find_max(){
    return find_max_aux(this->root);
}


Node* Binary_Tree::sucessor(Node *node){
    if(node == nullptr) return nullptr;

    if(node->right != nullptr) return find_min_aux(node->right);


    Node *son, *dad;

    son = node;
    dad = node->dad;



    while(dad != nullptr && son != dad->left){
        son = dad;
        dad = dad->dad;
    }


    return dad;


}

Node* Binary_Tree::predecessor(Node *node){
    if(node == nullptr) return nullptr;


    if(node->left != nullptr) return find_max_aux(node->left);

    Node *son = node;
    Node *dad = node->dad;


    while(dad != nullptr && son != dad->right){
        son = dad;
        dad = dad->dad;
    }

    
    return dad;
}


Node* Binary_Tree::element_by_position(int x){
    if(x <= 0 || x > this->root->size) return nullptr;
    if(this->root == nullptr) return nullptr;

    Node *node = this->root;

    while(node != nullptr){
        if(get_size(node->left) + 1 == x) break;
        
        else if(get_size(node->left) + 1 < x){
            x -= get_size(node->left) + 1;
            node = node->right;
        }
        else if(get_size(node->left) + 1 > x){
            node = node->left;
        }
    }

    return node;

}


int Binary_Tree::position_by_element(Node *node){
    if(node == nullptr) return -1;
    
    Node *jumper = node;
    int position = get_size(node->right) + 1;

    while(jumper->dad != nullptr){
        if(jumper == jumper->dad->left){
            jumper = jumper->dad;
        }
        else if(jumper == jumper->dad->right){
            jumper = jumper->dad;
            position += get_size(jumper->left) + 1;
        }
    }

    return position;


}





/*

int main(int argc, char const *argv[]){

    Binary_Tree tree;

    tree.insert(5);

    tree.insert(7);
    tree.insert(3);
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(8);

    tree.pre_order();

    cout << endl;

    tree.pos_order();

    cout << endl;

    tree.in_order();

    cout << endl;

    tree.BFS();

    cout << endl << endl;

    Node *p = tree.find_min();

    if(p != nullptr) cout << p->value << endl;

    p = tree.search(7);

    p = tree.find_min_aux(p);

    if(p != nullptr) cout << p->value << endl;

    cout << endl;


    p = tree.find_max();

    if(p != nullptr) cout << p->value << endl;

    p = tree.search(3);

    p = tree.find_max_aux(p);

    if(p != nullptr) cout << p->value << endl;

    
    cout << endl;


    p = tree.search(4);
    p = tree.sucessor(p);

    if(p != nullptr) cout << p->value << endl;


    cout << endl;

    p = tree.search(5);
    p = tree.predecessor(p);


    if(p != nullptr) cout << p->value << endl;


    cout << endl;

    
    // NOTE: TESTES DE REMOÇÃO
    // tree.remove(7);

    // cout << endl;

    // tree.pre_order();

    // cout << endl;

    
    //NOTE: TESTES DE REMOÇÃO
    // tree.remove(7);

    // cout << endl;

    // tree.pre_order();

    // cout << endl;
    for(int i = 0 ; i < 10 ; i++){
        p = nullptr;
        p = tree.element_by_position(i);

        if(p != nullptr) cout << "Elemento na posição " << i << ": " << p->value << endl;
    }

    cout << endl;

    for(int i = 0 ; i < 10 ; i++){
        p = nullptr;
        p = tree.search(i);

        if(p != nullptr) {
            int position = tree.position_by_element(p);
            cout << "Elemento " << p->value << " na posição: " << position << endl;
        }
    }

    
    



    return 0;
}


*/
