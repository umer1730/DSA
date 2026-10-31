#include <iostream>
#include <queue>
using namespace std;

// Node Structure
struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(char value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Count Total Nodes
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// BFS Traversal
void BFS(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    cout << "BFS Traversal (Level Order): ";

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
    cout << endl;
}
int main(){
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    //Create Binary Tree Dynamically

    Node *A = new Node('A');
    Node *B = new Node('B');
    Node *C = new Node('C');
    Node *D = new Node('D');
    Node *E = new Node('E');
    Node *F = new Node('F');

    A->left = B;
    A->right = E;

    B->left = C;
    B->right = D;

    E->right = F;
    // BFS Traversal
    BFS(A);
    // Count Nodes
    cout<<"Total Number of Nodes = "<<countNodes(A) << endl;
    return 0;
}