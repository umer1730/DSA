#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// insert new value after given key
void insertAfter(Node* head, int key, int value) {
    while (head != NULL && head->data != key)
        head = head->next;

    if (head == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = head->next;
    head->next = newNode;
}

int main() {
    // create list quickly
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    cout << "Original List:\n";
    display(head);

    insertAfter(head, 20, 25);

    cout << "After insertion:\n";
    display(head);
}