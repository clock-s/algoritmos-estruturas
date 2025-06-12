#include <iostream>
#include <vector>
#include <queue>

using namespace std;



struct Node_Vector{
    Node_Vector *dad;
    char value;
    vector<Node_Vector*> sons;

    Node_Vector();
};


Node_Vector::Node_Vector(){
    this->dad = nullptr;
}

class vector_tree{
    private:
    Node_Vector *root = nullptr;

    void pos_order_aux(Node_Vector* node);
    void pre_order_aux(Node_Vector* node);
    void BFS_aux(Node_Vector* node);
    Node_Vector* create_tree_aux(string &tree, int &index, Node_Vector* dad = nullptr);

    public:
    void create_tree(string &tree);
    void delete_tree(Node_Vector* node);
    void pos_order();
    void pre_order();
    void BFS();

    vector_tree();
    ~vector_tree();
};


void vector_tree::create_tree(string &tree){
    int i = 0;
    delete_tree(root);
    create_tree_aux(tree, i);
}





Node_Vector* vector_tree::create_tree_aux(string &tree, int &index, Node_Vector* dad){
    while(tree[index] == ' ') index++;
    if(index >= tree.size()) return nullptr;
    if(tree[index] == '(') return create_tree_aux(tree, ++index, dad);


    Node_Vector* node = new Node_Vector();

    if(dad == nullptr) this->root = node; 

    node->dad = dad;
    node->value = tree[index];


    while(index+1 < tree.size() && tree[index+1] != ')' ){
        node->sons.push_back(create_tree_aux(tree, ++index, node));
    }

    index++;
    return node;
}



void vector_tree::pre_order_aux(Node_Vector* node){
    if(node == nullptr) return;

    cout << node->value;

    for(Node_Vector* n : node->sons){
        pre_order_aux(n);
    }
}

void vector_tree::pre_order(){
    pre_order_aux(root);
}


void vector_tree::pos_order_aux(Node_Vector* node){
    if(node == nullptr) return;

    

    for(Node_Vector* n : node->sons){
        pos_order_aux(n);
    }

    cout << node->value;

}

void vector_tree::pos_order(){
    pos_order_aux(root);
}



void vector_tree::BFS(){
    queue<Node_Vector*> queue_tree;

    queue_tree.push(root);

    while (!queue_tree.empty()){
        Node_Vector* p = queue_tree.front(); queue_tree.pop();

        cout << p->value;

        for(Node_Vector* s : p->sons){
            if(s != nullptr) queue_tree.push(s);
        }

    }
    
}





void vector_tree::delete_tree(Node_Vector *node){
    if (node == nullptr) return;

    for(Node_Vector* n : node->sons){
        delete_tree(n);
    }

    delete node;

    return;
}




vector_tree::vector_tree(){
    root = nullptr;
}

vector_tree::~vector_tree(){
    delete_tree(root);
}



int main(int argc, char const *argv[]){
   vector_tree tree;

   string string_tree = "(a(b(d)(e))(c(f)(g)))";

   cout << "start! " << string_tree.size() << endl;

    tree.create_tree(string_tree);

    tree.pre_order();

    cout << endl;

    tree.BFS();

    cout << endl;

    tree.pos_order();


    return 0;
}
