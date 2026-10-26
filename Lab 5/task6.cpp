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

    public:
    Queue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x){
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
        cout<<x<<" enqueued to queue\n";

    }
    int dequeue(){
        if(front == NULL){
            cout<<"Queue is empty,cannot dequeue\n";
            return -1;
        }
        Node* temp = front;
        int val = front->data;
        front = front->next;
        delete temp;

        if(front == NULL){
            rear = NULL;
        }
        cout<<val<<" dequeued from queue\n";
        return val;
    }

    int getFront(){
        if(front == NULL){
            cout<<"Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    
    bool isEmpty(){
        return (front == NULL);
    }
    void display(){
        if(front == NULL){
            cout<<"Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout<<"Queue element: ";
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout<<"Front element: "<<q.getFront()<<endl;

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}