#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = NULL;
    }
};

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);         
    cout << root->data << " ";   
    inorder(root->right);        
}

int main() {
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    
    root->left->left = new Node('D');
    root->left->right = new Node('E');

    root->right->left = new Node('F');
    root->right->right = new Node('G');

    root->left->right->left = new Node('H');
    root->left->right->right = new Node('I');

    cout << "Inorder traversal: ";
    inorder(root);   
    cout << endl;

    return 0;
}
