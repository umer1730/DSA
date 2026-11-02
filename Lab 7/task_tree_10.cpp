#include <iostream>
using namespace std;

// Node Class
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// BST Class
class BST
{
private:
    Node *root;

    Node* insertRec(Node *root, int value)
    {
        if(root == NULL)
            return new Node(value);

        if(value < root->data)
            root->left = insertRec(root->left, value);

        else if(value > root->data)
            root->right = insertRec(root->right, value);

        return root;
    }
    // search recursive function
    bool searchRec(Node *root, int value)
    {
        if(root == NULL)
            return false;

        if(root->data == value)
            return true;

        if(value < root->data)
            return searchRec(root->left, value);

        return searchRec(root->right, value);
    }
    void inorderRec(Node *root)
    {
        if(root == NULL)
            return;

        inorderRec(root->left);
        cout << root->data<<" ";
        inorderRec(root->right);
    }

    void preorderRec(Node *root)
    {
        if(root == NULL)
            return;

        cout<<root->data << " ";

        preorderRec(root->left);
        preorderRec(root->right);
    }

    void postorderRec(Node *root)
    {
        if(root == NULL)
            return;

        postorderRec(root->left);
        postorderRec(root->right);

        cout << root->data << " ";
    }
    // find for minimum value
    Node* findMin(Node *root)
    {
        if(root == NULL)
            return NULL;

        while(root->left != NULL)
            root = root->left;

        return root;
    }
    // find for maximum value
    Node* findMax(Node *root)
    {
        if(root == NULL)
            return NULL;

        while(root->right != NULL)
            root = root->right;

        return root;
    }

    int heightRec(Node *root)
    {
        if(root == NULL)
            return -1;

        int leftHeight = heightRec(root->left);
        int rightHeight = heightRec(root->right);

        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
    // for count nodes
    int countNodesRec(Node *root)
    {
        if(root == NULL)
            return 0;

        return 1 + countNodesRec(root->left) + countNodesRec(root->right);
    }

    int countLeavesRec(Node *root)
    {
        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL)
            return 1;

        return countLeavesRec(root->left) + countLeavesRec(root->right);
    }

public:

    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insertRec(root, value);
    }

    bool search(int value)
    {
        return searchRec(root, value);
    }

    void inorder()
    {
        inorderRec(root);
        cout << endl;
    }

    void preorder()
    {
        preorderRec(root);
        cout << endl;
    }

    void postorder()
    {
        postorderRec(root);
        cout << endl;
    }

    void minimum()
    {
        Node *temp = findMin(root);

        if(temp == NULL)
            cout << "Tree is Empty" << endl;
        else
            cout << "Minimum Value: " << temp->data << endl;
    }

    void maximum()
    {
        Node *temp = findMax(root);

        if(temp == NULL)
            cout << "Tree is Empty" << endl;
        else
            cout << "Maximum Value: " << temp->data << endl;
    }

    int height()
    {
        return heightRec(root);
    }

    int countNodes()
    {
        return countNodesRec(root);
    }

    int countLeaves()
    {
        return countLeavesRec(root);
    }
};

int main(){
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    tree.minimum();

    tree.maximum();

    cout << "Height of Tree: " << tree.height() << endl;

    cout << "Total Nodes: " << tree.countNodes() << endl;

    cout << "Leaf Nodes: " << tree.countLeaves() << endl;

    int key;

    cout << "Enter value to search: ";
    cin >> key;

    if(tree.search(key))
        cout << key << " found in BST." << endl;
    else
        cout << key << " not found in BST." << endl;

    return 0;
}