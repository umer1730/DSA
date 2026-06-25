#include<iostream>
using namespace std;

const int capacity = 100; 
int arr[capacity]; 
int n = 0;

void update(int index, int newValue) { 
if (index < 0 || index >= n) { 
cout << "Invalid index"; 
return; 
} 
arr[index] = newValue; 
} 
int main(){
    for (int val = 60; val < 89; val+=2)  {   
        arr[n] = val; 
        n++; 
} 
    update(3,77);

    cout<<update(arr,newValue);
}