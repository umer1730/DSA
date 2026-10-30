#include<iostream>
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

void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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

    cout << "Preorder traversal: ";
    preorder(root);   
    cout << endl;

    return 0;
}
//  Node* A = new Node('A');
//     Node* B = new Node('B');
//     Node* C = new Node('C');
//     Node* D = new Node('D');
//     Node* E = new Node('E');
//     Node* F = new Node('F');
//     Node* G = new Node('G');
//     Node* H = new Node('H');
//     Node* I = new Node('I');

//     A->left = B; A->right = C;
//     B->left = D; B->right = E;
//     C->left = F; C->right = G;
//     E->left = H; E->right = I;
