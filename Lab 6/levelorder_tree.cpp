#include <iostream>
#include <queue>
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

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;        // Correct queue declaration
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)  q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
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

    cout << "Level Order traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
