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

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);

    root->left->right = new Node(7);

    cout<<"Root: "<<root->data<<endl;
    cout<<"Left child: "<<root->left->data<<endl;
    cout<<"Right child: "<<root->right->data<<endl;
    cout<<"Left->Right: "<<root->left->right->data<<endl;
}