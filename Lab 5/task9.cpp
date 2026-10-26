#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Queue{
private:
    Node* front;
    Node* rear;
    int count;
    int MAX;

public:

    Queue(){
        front = NULL;
        rear = NULL;
        count = 0;
        MAX = 10;
    }

    // Check if queue is empty
    bool isEmpty(){
        return (front == NULL);
    }

    // Check if queue is full
    bool isFull(){
        return (count == MAX);
    }

    // Enqueue function
    void enqueue(int x){

        if(isFull()){
            cout << "Queue Overflow! Queue is full.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if(rear == NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }

        count++;

        cout << x << " enqueued to queue\n";
    }

    // Dequeue function
    int dequeue(){

        if(isEmpty()){
            cout << "Queue Underflow! Queue is empty.\n";
            return -1;
        }

        Node* temp = front;
        int val = front->data;

        front = front->next;

        delete temp;

        count--;

        if(front == NULL){
            rear = NULL;
        }

        cout << val << " dequeued from queue\n";

        return val;
    }

    // Get front element
    int getFront(){

        if(isEmpty()){
            cout << "Queue is empty\n";
            return -1;
        }

        return front->data;
    }

    // Display queue
    void display(){

        if(isEmpty()){
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;

        cout << "Queue elements: ";

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main(){

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);

    // Overflow
    q.enqueue(110);

    q.display();

    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}