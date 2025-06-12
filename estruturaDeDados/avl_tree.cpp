#include <iostream>
#include "binary_tree.cpp"

using namespace std;


class AVL_Tree: public Binary_Tree{
    private:
    int max_dif_height = 1;
    void AVL_att_height_size(Node *node);
    int AVL_att_height(Node *node);
    int AVL_att_size(Node *node);
    void rotation(Node *node);
    
    
    
    public:
    void AVL_insert(int x);
    void left_rotation(Node *node);
    void right_rotation(Node *node);
    void double_left_rotation(Node *node);
    void double_right_rotation(Node *node);
};


void AVL_Tree::rotation(Node *node){
    if(node == nullptr) return;

    bool rotated = false;

    cout << "Analise: " << node->value << endl; 


    if(get_height(node->right) > get_size(node->left) + 1){
        if(get_height(node->right->left) > get_size(node->right->right) + 1){
            double_left_rotation(node);
            node = node->dad;
        }else{
            left_rotation(node);
        }
        
        rotated = true;
    }else if(get_height(node->left) > get_size(node->right) + 1){
        if(get_height(node->left->right) > get_size(node->right->left) + 1){
            double_right_rotation(node);
            node = node->dad;
        }else{
            right_rotation(node);
        }
        
        rotated = true;
    }

    if(rotated) rotation(node->dad->dad);
    else rotation(node->dad);
}


void AVL_Tree::AVL_insert(int x){
    this->insert(x);

    Node *node = this->search(x)->dad;

    rotation(node);

}

int AVL_Tree::AVL_att_height(Node *node){
    if(node == nullptr) return -1;

    node->height = max(AVL_att_height(node->left), AVL_att_height(node->right)) + 1;

    return node->height;
}
int AVL_Tree::AVL_att_size(Node *node){
    if(node == nullptr) return 0;

    node->size = AVL_att_size(node->left) + AVL_att_size(node->right) + 1;

    return node->size;

}

void AVL_Tree::AVL_att_height_size(Node *node){
    AVL_att_height(node);
    AVL_att_size(node);

    att_height_size(node);
}

void AVL_Tree::left_rotation(Node *node){
    if(node == nullptr || node->right == nullptr) return;
    
    Node* right_son = node->right;

    node->right = right_son->left;
    node->right->dad = node;

    right_son->left = node;

    if(node->dad != nullptr){
        if(node == node->dad->left) node->dad->left = right_son;
        else if(node == node->dad->right) node->dad->right = right_son;
    }else{
        this->root = right_son;
    }

    right_son->dad = node->dad;
    node->dad = right_son;


}


void AVL_Tree::right_rotation(Node *node){
    if(node == nullptr || node->left == nullptr) return;

    Node* left_son = node->left;

    node->left = left_son->right;
    node->left->dad = node;

    left_son->right = node;


    if(node->dad != nullptr){
        if(node == node->dad->left) node->dad->left = left_son;
        else if(node == node->dad->right) node->dad->right = left_son;
    }else{
        this->root = left_son;
    }

    left_son->dad = node->dad;
    node->dad = left_son;

}


void AVL_Tree::double_left_rotation(Node *node){
    right_rotation(node);
    node = node->dad;
    left_rotation(node);


}
void AVL_Tree::double_right_rotation(Node *node){
    left_rotation(node);
    node = node->dad;
    left_rotation(node);
}


int main(){
    AVL_Tree tree;


    for(int i = 1 ; i < 6 ; i++){
        tree.AVL_insert(i);

        tree.pre_order();

        cout << endl << endl;
    }


}
