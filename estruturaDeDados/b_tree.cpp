#include <cstdio>
#include <vector>


using namespace std;




struct Node{
    Node *dad;
    int *values;
    Node* *keys; 
    int node_size;
    bool leaf;

    Node(unsigned int n);
};

Node::Node(unsigned int n){
    this->dad = nullptr;
    this->node_size = 0;

    this->values = new int[n];
    this->keys = new Node*[n + 1];
    this->leaf = true;

};




class B_Tree{
    private:
        Node *root;
        unsigned int max_node_size;
        unsigned int min_node_size;


        void pre_order_aux(Node *node);

    public:
        void insert(int value);
        void insert(int value, Node* &node);
        void search(Node *node);
        void pre_order();
        void split(Node *node);
        void shift(Node* &node, const int &index);
        

        B_Tree(int node_size){
            this->max_node_size = node_size;
            this->root = nullptr;
            this->min_node_size = node_size/2;
        }
};



void B_Tree::shift(Node* &node, const int &index){
    int j = node->node_size;
    while(j > index){
        node->values[j] = node->values[j-1]; 
        j--;
    }

    node->node_size++;
}


void B_Tree::split(Node* &node, const &index){
    Node *pai = new Node(this->max_node_size);
    Node *f2 = new Node(this->max_node_size);

    



}

void B_Tree::insert(int value, Node* &node){
    int index = 0;

    while(value > node->values[index] && index < node->node_size) index++;

    if(index < this->max_node_size){
        if(!node->leaf){
            insert(value, node->keys[index]);
        }

        else if(node->leaf){
            if(node->node_size + 1 <= this->max_node_size){
                printf("Adicionando %d\n", value);
                shift(node, index);
                node->values[index] = value;
            }
        }
    }

    if(node->node_size >= this->max_node_size){

    }
    

}


void B_Tree::insert(int value){
    if(this->root == nullptr){
        Node *node = new Node(this->max_node_size);
        node->values[0] = value;
        node->node_size++;
        
        this->root = node;

        return;
    }

    insert(value, this->root);

}

void B_Tree::search(Node *node){

}

void B_Tree::pre_order(){
    pre_order_aux(this->root);
}

void B_Tree::pre_order_aux(Node *node){
    if(node == nullptr) return;

    for(unsigned int i = 0 ; i < node->node_size; i++){
        printf("%d -", node->values[i]);
    }

    printf("\n");
    if(node->leaf == false){
        for(unsigned int i = 0 ; i < node->node_size ; i++){
        pre_order_aux(node->keys[i]);
    }
    }
    
    
}

void B_Tree::split(Node *node){
    printf("\nFULLLLLL!\n");
}


int main(int argc, char const *argv[]){

    B_Tree tree(5);

    for(int i = 0 ; i < 5 ; i++){
        tree.insert(i);
        tree.pre_order();
        printf("\n");
    }



    return 0;
}

