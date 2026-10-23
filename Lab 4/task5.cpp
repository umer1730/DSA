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

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void verifyTask5() {
        if (head != nullptr && head->next != nullptr) {
            cout << "Current Head: " << head->data << endl;
            cout << "Next Node: " << head->next->data << endl;
            if (head->next->prev == head) {
                cout << "Verification: The previous first node (" << head->next->data 
                     << ") now has a non-null prev pointer pointing to " << head->data << "." << endl;
            }
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
};

int main() {
    DoublyLinkedList list;
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    list.insertAtBeginning(25);
    list.insertAtBeginning(15);

    cout << "List before inseting:" << endl;
    list.displayForward(); 

    cout << "\n--- Insert 1 at beginning---" << endl;
    list.insertAtBeginning(1);
    
    list.displayForward(); 
    
    list.verifyTask5();

    return 0;
}