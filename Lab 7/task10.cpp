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

    Node *insertRec(Node *root, int value)
    {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->left = insertRec(root->left, value);
        else if (value > root->data)
            root->right = insertRec(root->right, value);

        return root;
    }

    bool searchRec(Node *root, int value)
    {
        if (root == NULL)
            return false;

        if (root->data == value)
            return true;

        if (value < root->data)
            return searchRec(root->left, value);

        return searchRec(root->right, value);
    }

    void inorderRec(Node *root)
    {
        if (root == NULL)
            return;

        inorderRec(root->left);
        cout << root->data << " ";
        inorderRec(root->right);
    }

    void preorderRec(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }

    void postorderRec(Node *root)
    {
        if (root == NULL)
            return;

        postorderRec(root->left);
        postorderRec(root->right);
        cout << root->data << " ";
    }
    // find minumumm value
    Node *findMin(Node *root)
    {
        while (root && root->left != NULL)
            root = root->left;

        return root;
    }
// find maximum value
    Node *findMax(Node *root)
    {
        while (root && root->right != NULL)
            root = root->right;

        return root;
    }

    int heightRec(Node *root)
    {
        if (root == NULL)
            return -1;

        int left = heightRec(root->left);
        int right = heightRec(root->right);

        return (left > right ? left : right) + 1;
    }

    int countNodesRec(Node *root)
    {
        if (root == NULL)
            return 0;

        return 1 + countNodesRec(root->left) + countNodesRec(root->right);
    }

    int countLeavesRec(Node *root)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        return countLeavesRec(root->left) + countLeavesRec(root->right);
    }

    // BST Deletion using Inorder Successor
    Node *deleteRec(Node *root, int value){
        if (root == NULL)
            return NULL;

        if (value < root->data){
            root->left = deleteRec(root->left, value);
        }
        else if (value > root->data){
            root->right = deleteRec(root->right, value);
        }
        else{
            // Case 1: No Child
            if (root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            // Case 2: One Child
            else if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL){
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two Children
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }

        return root;
    }

public:
    BST(){
        root = NULL;
    }

    void insert(int value){
        root = insertRec(root, value);
    }

    bool search(int value){
        return searchRec(root, value);
    }

    void inorder(){
        inorderRec(root);
        cout << endl;
    }
    void preorder(){
        preorderRec(root);
        cout << endl;
    }

    void postorder(){
        postorderRec(root);
        cout << endl;
    }
    void minimum(){
        Node *temp = findMin(root);

        if (temp)
            cout << "Minimum Value: " << temp->data << endl;
    }
    void maximum(){
        Node *temp = findMax(root);

        if (temp)
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

    void remove(int value)
    {
        root = deleteRec(root, value);
    }
};

int main()
{
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    BST tree;
    int choice, value;

    do
    {
        cout << "\n===== BST MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Minimum Value\n";
        cout << "7. Maximum Value\n";
        cout << "8. Height\n";
        cout << "9. Count Nodes\n";
        cout << "10. Count Leaf Nodes\n";
        cout << "11. Delete Node\n";
        cout << "12. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value))
                cout << "Value Found\n";
            else
                cout << "Value Not Found\n";
            break;

        case 3:
            cout << "Inorder: ";
            tree.inorder();
            break;

        case 4:
            cout << "Preorder: ";
            tree.preorder();
            break;

        case 5:
            cout << "Postorder: ";
            tree.postorder();
            break;

        case 6:
            tree.minimum();
            break;

        case 7:
            tree.maximum();
            break;

        case 8:
            cout << "Height = " << tree.height() << endl;
            break;

        case 9:
            cout << "Total Nodes = " << tree.countNodes() << endl;
            break;

        case 10:
            cout << "Leaf Nodes = " << tree.countLeaves() << endl;
            break;

        case 11:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.remove(value);
            cout << "Node Deleted Successfully.\n";
            break;

        case 12:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 12);

    return 0;
}