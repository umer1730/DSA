#include <iostream>
using namespace std;

const int capacity = 100; 
int arr[capacity]; 
int n = 0; 

void deleteAt(int index) { 
    if (index < 0 || index >= n) { 
        cout << "Invalid index\n"; 
        return; 
    } 
    for (int i = index; i < n - 1; i++) { 
        arr[i] = arr[i + 1]; 
    } 
    n--; 
}

int main() {
    
    for (int val = 60; val < 89; val += 2) {   
        arr[n] = val; 
        n++; 
    } 

    deleteAt(4);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}