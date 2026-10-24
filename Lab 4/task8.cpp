#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
class StackLinkedList{
    private:
    Node* head;

    public:
    StackLinkedList(){
        head = NULL;
    }
    ~StackLinkedList(){
        while(!isEmpty()){
            pop();
        }
    }
    bool isEmpty(){
        return head == NULL;
    }
    void push(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack underflow: cannot pop from empty stack"<<endl;
            return -1;
        }
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        return value;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty: no top element"<<endl;
            return -1;    
        }
        return head->data;
    }
};
int main(){
    StackLinkedList s;

    s.push(2);
    s.push(5);
    s.push(7);

    cout<<"Top element: "<<s.peek()<<endl;
    cout<<"Popped: "<<s.pop()<<endl;
    cout<<"Top element now: "<<s.peek()<<endl;

    return 0;
}