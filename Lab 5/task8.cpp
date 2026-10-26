#include<iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
    int count;
    int maxSize;

public:

    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
        maxSize = 10;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Check if queue is full
    bool isFull() {
        return count == maxSize;
    }

    // Enqueue operation
    void enqueue(int value) {

        if (isFull()) {
            cout << "Queue Overflow! Queue is full.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        // If queue is empty
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
        cout << value << " inserted into queue.\n";
    }

    // Dequeue operation
    void dequeue() {

        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty.\n";
            return;
        }

        Node* temp = front;

        cout << front->data << " deleted from queue.\n";

        front = front->next;

        delete temp;

        count--;

        // If queue becomes empty
        if (front == NULL) {
            rear = NULL;
        }
    }

    // Peek operation
    void peek() {

        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Front element is: " << front->data << endl;
    }

    // Display queue
    void display() {

        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;

        cout << "Queue elements: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

// Main function
int main() {

    Queue q;
    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            if(q.isEmpty())
                cout << "Queue is empty.\n";
            else
                cout << "Queue is not empty.\n";
            break;

        case 6:
            if(q.isFull())
                cout << "Queue is full.\n";
            else
                cout << "Queue is not full.\n";
            break;

        case 7:
            cout << "Program exited.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while(choice != 7);

    return 0;
}