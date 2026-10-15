#include<iostream>
using namespace std;

class Node{
    public:
    char data;
    Node* left;
    Node* right;

    Node(char value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

void visit(Node* node){
    cout<<node->data<<" ";
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    visit(root);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    visit(root);
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    visit(root);
}

int main(){
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D'); 
    root->left->right = new Node('E'); 
    root->right->left = new Node('F'); 
    root->right->right = new Node('G'); 
    cout << "Preorder:  "; 
    preorder(root); 
    cout << "\nInorder:   "; 
    inorder(root); 
    cout << "\nPostorder: "; 
    postorder(root); 
    return 0; 

}