#include<iostream>
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

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
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

    void displayBackward() {
        Node* current = tail;
        cout << "Backward: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head == tail)
            head = tail = nullptr;
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (tail == nullptr) return;
        Node* temp = tail;
        if (head == tail)
            head = tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void deleteByValue(int value) { //delete by value
        Node* current = head;
        while (current != nullptr && current->data != value)
            current = current->next;

        if (current == nullptr) return;
        if (current == head) deleteFromBeginning();
        else if (current == tail) deleteFromEnd();
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            deleteFromBeginning();
        }
    }
};

int main() {
    DoublyLinkedList list;
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    list.insertAtBeginning(15);
    list.insertAtBeginning(5);
    list.insertAtEnd(25);
    list.insertAtEnd(35);

    list.displayForward();
    list.displayBackward();
}