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

    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Value " << value << " not found." << endl;
            return;
        }

        if (current == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            else tail = nullptr; 
        } 
        else if (current == tail) {
            tail = tail->prev;
            if (tail != nullptr) tail->next = nullptr;
            else head = nullptr; 
        } 
        else {
            current->prev->next = current->next; 
            current->next->prev = current->prev; 
        }

        delete current;  
        cout << "Value " << value << " deleted." << endl;
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
};

int main() {
    DoublyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(15);
    list.insertAtEnd(25);

    cout << "Initial List: " << endl;
    list.displayForward(); 

    cout << "\n--- Performing Task 6 (deleteByValue: 15) ---" << endl;
    list.deleteByValue(15);

    cout << "Final List Memory Connection:" << endl;
    list.displayForward(); 

    return 0;
}