#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;
    Node* insertRec(Node* root, int value);
    bool searchRec(Node* root, int value);
    void inorderRec(Node* root);
    void preorderRec(Node* root);
    void postorderRec(Node* root);
    Node* findMin(Node* root);
    Node* findMax(Node* root);
    int heightRec(Node* root);
    int countNodesRec(Node* root);
    int countLeavesRec(Node* root);
    void destroyTree(Node* root);
    Node* deleteRec(Node* root, int value);

public:
    BST();
    ~BST();

    void insert(int value);
    bool search(int value);
    void inorder();
    void preorder();
    void postorder();
    void minimum();
    void maximum();
    int height();
    int countNodes();
    int countLeaves();
    void remove(int value);
};

// Constructor & Destructor
BST::BST() 
{ 
    root = NULL; 
}
BST::~BST(){ 
    destroyTree(root);
}

void BST::destroyTree(Node* root) {
    if (root == NULL) 
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

// Insert
Node* BST::insertRec(Node* root, int value) {
    if (root == NULL) 
    {
        return new Node(value);
    }
    if(value < root->data) {
        root->left = insertRec(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertRec(root->right, value);
    }
    else {
        cout << "Duplicate value ignored: " << value << endl;
    }
        return root;
}
void BST::insert(int value){ 
    root = insertRec(root, value); 
}

// Search
bool BST::searchRec(Node* root, int value) {
    if (root == NULL) 
        return false;
    if (root->data == value) 
        return true;
    if (value < root->data) 
        return searchRec(root->left, value);
    else 
        return searchRec(root->right, value);
}
bool BST::search(int value){ 
    return searchRec(root, value); 
}

// Traversals
void BST::inorderRec(Node* root){
    if (root == NULL) 
        return;
    inorderRec(root->left);
    cout << root->data << " ";
    inorderRec(root->right);
}
void BST::preorderRec(Node* root) {
    if (root == NULL) 
        return;
    cout << root->data << " ";
    preorderRec(root->left);
    preorderRec(root->right);
}
void BST::postorderRec(Node* root) {
    if (root == NULL) 
        return;
    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->data << " ";
}
void BST::inorder() { 
    inorderRec(root); 
    cout << endl; 
}
void BST::preorder() { 
    preorderRec(root); 
    cout << endl; 
}
void BST::postorder() { 
    postorderRec(root); 
    cout << endl; 
}

// Min & Max
Node* BST::findMin(Node* root) {
    if (root == NULL) 
        return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* BST::findMax(Node* root) {
    if (root == NULL) 
        return NULL;
    while (root->right != NULL){ 
        root = root->right;
    }
    return root;
}
void BST::minimum() {
    Node* minNode = findMin(root);
    if (minNode == NULL) 
        cout << "Tree is empty" << endl;
    else 
        cout << "Minimum value: " << minNode->data << endl;
}
void BST::maximum() {
    Node* maxNode = findMax(root);
    if (maxNode == NULL) 
        cout << "Tree is empty" << endl;
    else 
        cout << "Maximum value: " << maxNode->data << endl;
}

// Height, Nodes, Leaves
int BST::heightRec(Node* root) {
    if (root == NULL) 
        return -1; // height in edges
    int leftHeight = heightRec(root->left);
    int rightHeight = heightRec(root->right);
    return max(leftHeight, rightHeight) + 1;
}
int BST::countNodesRec(Node* root) {
    if (root == NULL) 
        return 0;
    return 1 + countNodesRec(root->left) + countNodesRec(root->right);
}
int BST::countLeavesRec(Node* root) {
    if (root == NULL) 
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return 1;
    return countLeavesRec(root->left) + countLeavesRec(root->right);
}
int BST::height() { return heightRec(root); }
int BST::countNodes() { return countNodesRec(root); }
int BST::countLeaves() { return countLeavesRec(root); }

// Delete
Node* BST::deleteRec(Node* root, int value) {
    if (root == NULL) 
        return root;

    if (value < root->data) {
        root->left = deleteRec(root->left, value);
    } 
    else if (value > root->data){
        root->right = deleteRec(root->right, value);
    } 
    else {
        //  No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        //  One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //  Two children
        else {
            Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteRec(root->right, successor->data);
        }
    }
    return root;
}
void BST::remove(int value) { 
    root = deleteRec(root, value); 
}

// Main
int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

     cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    tree.minimum();
    tree.maximum();

    cout << "Height of tree: " << tree.height() << endl;
    cout << "Total nodes: " << tree.countNodes() << endl;
    cout << "Leaf nodes: " << tree.countLeaves() << endl;

    cout << "Inorder before deletion: "; tree.inorder();
    tree.remove(70);  // delete node with two children
    cout << "Inorder after deletion: "; tree.inorder();

    int key;
    cout << "Enter value to search: ";
    cin >> key;
    if (tree.search(key))
        cout << key << " found in BST" << endl;
    else
        cout << key << " not found in BST" << endl;

    return 0;
}
