#include<iostream>
using namespace std;
class StackArray{
    private:
    int* arr;
    int top;
    int capacity;

public:
    StackArray(int size){
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    ~StackArray(){
        delete[]arr;
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top = capacity -1;
    }
    void push(int value){
        if(isFull()){
            cout<<"Stack overflow, cannot push"<<value;
            return; 
        }
        top++;
        arr[top] = value;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack underflow cannot pop from empty stack"<<endl;
            return -1;
        }
        int value = arr[top];
        top--;
        return value;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty: no top element"<<endl;
            return -1;
        }
        return arr[top];
    }
};
int main(){
    StackArray s(5);
    s.push(2);
    s.push(5);
    s.push(7);

    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    cout<<"Top element: "<<s.peek()<<endl;
    cout<<"Popped: "<<s.pop()<<endl;
    cout<<"Top element now: "<<s.peek()<<endl;

    return 0;
}