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
 // Enqueue function where value enter in rear
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
        cout<<x<<" Enqueued to queue: "<<endl;
    }
    // Dequeue function where value remove from front
    int dequeue(){
        if(front == NULL){
            cout<<"Queue is empty cannot to dequeue";
            return -1;
        }

        Node* temp = front;
        int value = front->data;
        front = front->next;
        delete temp;

        if(front == NULL){
            rear =  NULL;
        }
        cout<<value<<" Dequeued from queue"<<endl;
        return value;
    }
 // Get front element
    int getFront(){
        if(front == NULL){
            cout<<"Queue is empty";
            return -1;
        }
        return front->data;
    }

    bool isEmpty(){
        return (front == NULL);
    }
// Display queue
    void display(){
        if(front==NULL){
            cout<<"Queue is empty";
            return;
        }
        Node* temp = front;
        cout<<"Queue elements: ";
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    cout<<"---Umer Yaseen"<<endl;
    cout<<"---2025(S)-AI-35"<<endl;

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

    q.enqueue(110);
    q.display();

    cout<<"Front Element: "<<q.getFront()<<endl;
    
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}