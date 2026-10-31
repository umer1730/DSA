#include <iostream> 
using namespace std; 
 
class Node { 
public: 
    char data; 
    Node* left; 
    Node* right; 
 
    Node(char value) { 
        data = value; 
        left = NULL; 
        right = NULL; 
    } 
}; 
 
int main() { 
    Node* root = new Node('A'); 
    root->left = new Node('B'); 
    root->right = new Node('C'); 
 
    root->left->left = new Node('D'); 
    root->left->right = new Node('E'); 
    root->right->left = new Node('F'); 
    root->right->right = new Node('G'); 
 
    cout << "Tree created successfully." << endl; 
    return 0; 
}