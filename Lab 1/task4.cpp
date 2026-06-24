#include<iostream>
using namespace std;

const int capacity = 100;
int arr[capacity];
int n = 0;

void insertEnd(int value) {
    if (n == capacity) {
        cout << "Overflow!";
        return;
    }
    arr[n] = value;
    n++;
}


int main() {

    for (int val = 60; val < 89; val += 2) {
        insertEnd(val);
    }

    insertEnd(77);

    cout << "n = " << n << endl;

   
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}