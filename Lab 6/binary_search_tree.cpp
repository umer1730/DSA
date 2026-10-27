#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* root, int value) {
        if (root == NULL) return new Node(value);

        if (value < root->data)
            root->left = insertRec(root->left, value);
        else if (value > root->data)
            root->right = insertRec(root->right, value);

        return root;
    }

    bool searchRec(Node* root, int value) {
        if (root == NULL) return false;
        if (value == root->data) return true;
        if (value < root->data) return searchRec(root->left, value);
        return searchRec(root->right, value);
    }

    void inorderRec(Node* root) {
        if (root == NULL) return;
        inorderRec(root->left);
        cout << root->data << " ";
        inorderRec(root->right);
    }

    Node* findMin(Node* root) {
        while (root != NULL && root->left != NULL)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == NULL) return root;

        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);
        else {
            // Case 1 & 2
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

public:
    BST() { root = NULL; }

    void insert(int value) { root = insertRec(root, value); }
    bool search(int value) { return searchRec(root, value); }
    void inorder() { inorderRec(root); }
    void remove(int value) { root = deleteNode(root, value); }
};

int main() {
    BST tree;

    // Insert values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal (Sorted): ";
    tree.inorder();
    cout << endl;

    // Search
    cout << "Search 60: " << (tree.search(60) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;

    // Delete
    cout << "Deleting 20...\n";
    tree.remove(20);
    cout << "Inorder after deletion: ";
    tree.inorder();
    cout << endl;

    cout << "Deleting 30...\n";
    tree.remove(30);
    cout << "Inorder after deletion: ";
    tree.inorder();
    cout << endl;

    cout << "Deleting 50...\n";
    tree.remove(50);
    cout << "Inorder after deletion: ";
    tree.inorder();
    cout << endl;

    return 0;
}
