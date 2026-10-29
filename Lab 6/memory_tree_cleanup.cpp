#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void destroy(Node* node){
    if(node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);

    destroy(root);
    cout<<"Tree deleted successfully: "<<endl;
    return 0;
}