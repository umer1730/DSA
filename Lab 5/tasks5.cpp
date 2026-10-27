#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // ENQUEUE
    void enqueue(int x) {
        if (rear == 4) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;

        rear++;
        arr[rear] = x;
        cout << x << " inserted\n";
    }

    // DEQUEUE
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " deleted\n";
        front++;
    }

    // DISPLAY
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // PEEK
    void peek() {
        if (front == -1 || front > rear)
            cout << "Queue Empty\n";
        else
            cout << "Front element: " << arr[front] << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.peek();
}