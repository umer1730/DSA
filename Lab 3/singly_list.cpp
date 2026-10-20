#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor
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
    cout << "NULL";
}

int main() {
    // create linked list in ONE LINE each
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    display(head);
}