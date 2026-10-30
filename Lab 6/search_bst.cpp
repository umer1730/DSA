#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

Node* root = NULL;   

// BST Insert 
Node* insertRec(Node* root, int value){
    if(root == NULL)
        return new Node(value);

    if(value < root->data)
        root->left = insertRec(root->left, value);
    else if(value > root->data)
        root->right = insertRec(root->right, value);

    return root;
}

// BST Search 
bool searchRec(Node* root, int value){
    if(root == NULL)
        return false;
    if(value == root->data)
        return true;
    if(value < root->data)
        return searchRec(root->left, value);
    else
        return searchRec(root->right, value);
}

bool search(int value){
    return searchRec(root, value);
}

int main(){
    // Insert nodes
    root = insertRec(root, 50);
    root = insertRec(root, 30);
    root = insertRec(root, 70);
    root = insertRec(root, 20);
    root = insertRec(root, 40);

    // Search test
    if(search(40))
        cout << "Value Found!";
    else
        cout << "Value Not Found!";

    return 0;
}