#include <iostream>
using namespace std;

// PACKAGE CLASS 
class Package {
public:
    int id;
    int urgency;
    int weight;
    int zone;

    Package() {
        id = urgency = weight = zone = 0;
    }

    
    Package(int i, int u, int w, int z) {
        id = i;
        urgency = u;
        weight = w;
        zone = z;
    }
};

// QUEUE 
class Queue {
private:
    Package arr[10];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(Package p) {
        if (rear == 9) return;

        if (front == -1) front = 0;
        arr[++rear] = p;
    }

    Package dequeue() {
        return arr[front++];
    }

    bool isEmpty() {
        return front > rear;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i].id << " ";
        }
        cout << endl;
    }
};

// stack
class Stack {
private:
    int arr[10];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        arr[++top] = x;
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// binary search tree 
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void inorder(Node* node) {
        if (node == NULL) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL) return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    bool search(Node* node, int key) {
        if (node == NULL) return false;

        if (node->data == key) return true;

        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
};

    //  sorting 
    bool higherPriority(Package a, Package b) {
        if (a.urgency != b.urgency)
            return a.urgency > b.urgency;

        if (a.weight != b.weight)
            return a.weight < b.weight;

        if (a.zone != b.zone)
            return a.zone < b.zone;

        return a.id < b.id;
    }

    void selectionSort(Package arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int maxIdx = i;

            for (int j = i + 1; j < n; j++) {
                if (higherPriority(arr[j], arr[maxIdx])) {
                    maxIdx = j;
                }
            }

            Package temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }


int main() {
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    // Given values
    int a = 0, b = 3, c = 5, K = 1;

    // Step 1: Queue creation
    Queue q;

    int ids[7] = {101, 105, 108, 104, 110, 118, 109};

    Package p[7];

    p[0] = Package(101, 1, 5, 2);
    p[1] = Package(105, 2, 4, 1);
    p[2] = Package(108, 2, 7, 4);
    p[3] = Package(104, 1, 3, 0);
    p[4] = Package(110, 1, 2, 1);
    p[5] = Package(118, 3, 3, 4);
    p[6] = Package(109, 3, 8, 0);

    for (int i = 0; i < 7; i++) {
        q.enqueue(p[i]);
    }

    cout << "Original Queue:\n";
    q.display();

    // Step 2: Stack + Valid List
    Stack st;
    Package valid[10];
    int vCount = 0;

    while (!q.isEmpty()) {
        Package cur = q.dequeue();

        if (cur.weight > 6) {
            st.push(cur.id);
        } else {
            valid[vCount++] = cur;
        }
    }

    cout << "\nDamaged Packages (Stack Order):\n";
    st.display();

    cout << "\nValid Packages Before Sorting:\n";
    for (int i = 0; i < vCount; i++)
        cout << valid[i].id << " ";
    cout << endl;

    // Step 3: Sorting
    selectionSort(valid, vCount);

    cout << "\nValid Packages After Sorting:\n";
    for (int i = 0; i < vCount; i++)
        cout << valid[i].id << " ";
    cout << endl;

    // Step 4: BST
    BST tree;

    for (int i = 0; i < vCount; i++) {
        tree.insert(valid[i].id);
    }

    cout << "\nBST Inorder Traversal:\n";
    tree.inorder(tree.root);

    cout << "\n\nBST Preorder Traversal:\n";
    tree.preorder(tree.root);

    // Step 5: Search
    int searchID = 100 + ((a * b) + c + K) % 30;

    cout << "\n\nSearch ID = " << searchID << endl;

    if (tree.search(tree.root, searchID))
        cout << "Result: Package Found\n";
    else
        cout << "Result: Package Not Found\n";

    return 0;
}