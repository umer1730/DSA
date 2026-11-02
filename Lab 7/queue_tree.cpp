#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

void BFS(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;

    q.push(root);
    cout<<"\nBFS Traversal: ";

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        cout<<current->data<<" ";

        if(current->left != NULL){
            q.push(current->left);
        }
        if(current->right != NULL){
            q.push(current->right);
        }
    }
    cout<<endl;
}

int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1 + countNodes(root->left)+countNodes(root->right);
}
int main(){
     Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->left = new Node(60);
    root->right->right = new Node(70);

    root->left->left->left = new Node(80);

    BFS(root);

    int total = countNodes(root);

    cout << "Total Number of Nodes: " << total << endl;

    return 0;
}