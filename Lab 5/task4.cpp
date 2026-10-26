#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
class Queue{
    Node* front;
    Node* rear;

    public:
    Queue(){
        front = rear = NULL;
    }

    void enqueue(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;

        if(rear == NULL){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
        cout<<x<<"Inserted\n";
    }
    void dequeue(){
        if(front == NULL){
            cout<<"Queue Underflow\n";
            return;
        }
        Node* temp = front;
        cout<<temp->data << "Deleted\n";
        front = front->next;

        if(front == NULL){
            rear = NULL;
        }
        delete temp;
    }
    void peek(){
        if(front != NULL){
            cout<<"Front element: "<<front->data<<endl;
        }
        else{
            cout<<"Queue Empty\n";
        }
    }
    void display(){
        Node* temp = front;
        cout<<"Queue: ";
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
    q.enqueue(20);
    q.display();

    q.dequeue();
    q.display();

    q.peek();
}