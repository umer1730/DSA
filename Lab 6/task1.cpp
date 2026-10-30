#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};   
class StackLinked{
    private:
    Node* head;

    public:
    StackLinked(){
        head = NULL;
    }
    
    ~StackLinked(){
        while(!isEmpty()){
            pop();   // delte all nodes one by one
        }
    }
    // check if stack is empty
    bool isEmpty(){
        return head == NULL;
    }
// insert element at top
    void push(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
// remove top element
    int pop(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        return value;
    }
    // return top element without removing
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;    
        }
        else{
            return head->data;
        }
    }
    void display(){   // print all stack elements
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
    }

    Node* temp = head;  // start from top
    cout<<"Stack elements: ";
    // traversal one by one
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        }
    cout<<endl;
    }
};


int main(){
    StackLinked s;
 //push values into stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(12);

    s.display();    //display stack

    cout<<"Top element: "<<s.peek()<<endl;
    cout<<"Popped: "<<s.pop()<<endl;    //pop top element
    s.display();    // display after pop
    cout<<"Top element afer pop now: "<<s.peek()<<endl;
    cout<<"Name: ---Umer Yaseen---"<<endl;
    cout<<"Reg: ---2025(S)-Ai-35---"<<endl;
    return 0;
}