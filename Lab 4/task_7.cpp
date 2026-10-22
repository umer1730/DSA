#include<iostream>
using namespace std;

class StackArray {
private:
    int *arr;
    int top;
    int capacity;

public:
    StackArray(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if(isFull()) {
            cout<<"Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = value;
    }

    int pop() {
        if(isEmpty()) {
            cout<<"Stack Underflow\n";
            return -1;
        }
        int value = arr[top];
        top--;
        return value;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"Stack Empty\n";
            return -1;
        }
        return arr[top];
    }

    int size(){
        return top + 1;
    }

    ~StackArray() {
        delete[] arr;
    }
};

int main() {
    StackArray s(5);
    int x;

    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"Popped: "<<s.pop()<<endl;
    cout<<"Top element: "<<s.peek()<<endl;

    cout<<endl;
    cout<<"Size: "<<s.size();

    cout<<endl;
    cout<<"Enter 5 numbers: \n";
    for(int i = 0;i<5;i++) {
        cin>>x;
        s.push(x);
    }
}