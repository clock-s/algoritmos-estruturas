#include <iostream>
#include <vector>
#include <queue>

using namespace std;



struct Node{
    Node *dad;
    char value;
    Node *brother;
    Node *son;

    Node();
};


Node::Node(){
    this->son = this->brother = this->dad = nullptr;
}

class brothers_tree{
    private:
    Node *root = nullptr;

    void pre_order_aux(Node* node);
    Node* create_tree_aux(string &tree, int &index, Node* dad = nullptr);

    public:
    void create_tree(string &tree);
    void delete_tree(Node* node);
    void pre_order();
    

    brothers_tree();
    ~brothers_tree();
};


void brothers_tree::create_tree(string &tree){
    int i = 0;
    delete_tree(root);
    create_tree_aux(tree, i);
}



//(a (b(d)(e)) (c(f )(g)) )

Node* brothers_tree::create_tree_aux(string &tree, int &index, Node* dad){
    while(tree[index] == ' ') index++;
    if(index >= tree.size()) return nullptr;
    if(tree[index] == '(') return create_tree_aux(tree, ++index, dad);


    Node* node = new Node();

    if(dad == nullptr) this->root = node; 

    node->dad = dad;
    node->value = tree[index];

    Node *last_son = node->son;

    while(index+1 < tree.size() && tree[index+1] != ')' ){
        if(last_son == nullptr) {
            node->son = create_tree_aux(tree, ++index, node);
            last_son = node->son;
        }
        else{
            last_son->brother = create_tree_aux(tree, ++index, node);
            last_son = last_son->brother;
        }
    }

    index++;
    return node;
}


void brothers_tree::pre_order_aux(Node* node){
    if (node == nullptr) return;
    
    cout << node->value;
    pre_order_aux(node->son);
    pre_order_aux(node->brother);

}


void brothers_tree::pre_order(){
    pre_order_aux(root);
}


void brothers_tree::delete_tree(Node *node){
    if(node == nullptr) return;

    delete_tree(node->son);
    delete_tree(node->brother);

    delete node;
}




brothers_tree::brothers_tree(){
    root = nullptr;
}

brothers_tree::~brothers_tree(){
    delete_tree(root);
}



int main(int argc, char const *argv[]){
    brothers_tree tree;

    string string_tree = "(a(b(d)(e))(c(f)(g)))";

    cout << "start! " << string_tree.size() << endl;

    tree.create_tree(string_tree);

    tree.pre_order();




    return 0;
}
