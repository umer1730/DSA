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

    void deleteFromBeginning() {
        if (head == nullptr) { 
            cout << "List is empty." << endl; 
            return; 
        }

        Node* temp = head; 
        if (head == tail) { 
            head = tail = nullptr; 
        } else {
            head = head->next;    
            head->prev = nullptr; 
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
};

int main() {
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    DoublyLinkedList list;

    list.insertAtEnd(5);
    list.insertAtEnd(15);
    list.insertAtEnd(25);
    list.insertAtEnd(35);

    cout << "Initial List: " << endl;
    list.displayForward(); 

    list.deleteFromBeginning();

    cout << "\nList after deletng the first node: " << endl;
    list.displayForward(); 

    return 0;
}