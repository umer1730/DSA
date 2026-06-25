#include<iostream>
using namespace std;

const int CAPACITY = 100;
int arr[CAPACITY];
int n = 0;

// Insert at specific index
void insertAt(int index, int value) {
    if (index < 0 || index > n || n == CAPACITY) {
        cout << "Invalid operation\n";
        return;
    }

    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    n++;
}

// Display array
void display() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    for (int val = 60; val < 89; val += 2) {
        arr[n] = val;
        n++;
    }

    cout << "n = " << n << endl;

    insertAt(3, 101);

    cout << "After Insertion:\n";
    display();

    return 0;
}