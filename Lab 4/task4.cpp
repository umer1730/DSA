#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void displayForward() {
        Node* current = head;
        cout << "Forward: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    Node* getTail() { 
        return tail;
    }
};

int main() {
    DoublyLinkedList list;

    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    list.insertAtEnd(15);
    list.insertAtEnd(25);
    list.insertAtEnd(35);

    cout << "List before Task 4: " << endl;
    list.displayForward(); 

    
    list.deleteFromEnd();

    cout << "\nList after deleting from end:" << endl;
    list.displayForward(); 
    
    if (list.getTail() != nullptr) {
        cout << "New tail value: " << list.getTail()->data << endl;
    }

    return 0;
}