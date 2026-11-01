#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Visit Function
void visit(Node* node){
    cout << node->data << " ";
}

// Preorder Traversal
void preorder(Node* root){
    if(root == NULL){
        return;
    }

    visit(root);
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal
void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    visit(root);
    inorder(root->right);
}

// Postorder Traversal
void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    visit(root);
}

int main(){

    // Manually Creating Tree

    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->left = new Node(60);
    root->right->right = new Node(70);

    root->left->left->left = new Node(80);

    int choice;

    do{
        cout << "\n====== DFS Traversal Menu ======\n";
        cout << "1. Recursive Preorder Traversal\n";
        cout << "2. Recursive Inorder Traversal\n";
        cout << "3. Recursive Postorder Traversal\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

    }while(choice != 4);

    return 0;
}