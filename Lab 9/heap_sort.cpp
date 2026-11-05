#include <iostream> 
using namespace std; 
// function to swap towo array elements
void swapValues(int &a, int &b) { 
    int temp = a; 
    a = b; 
    b = temp; 
} 
 
void displayArray(int arr[], int n) { 
    for(int i = 0; i < n; i++) 
    { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
} 
// heapify func to maintain max heap property
void heapify(int arr[], int n, int i) { 
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
 
    if(left < n && arr[left] > arr[largest]){ 
        largest = left; 
    } 
 
    if(right < n && arr[right] > arr[largest]){ 
        largest = right; 
    } 
 
    if(largest != i){ 
        swapValues(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
 // Function to convert array into Max Heap
void buildMaxHeap(int arr[], int n) { 
    for(int i = n / 2 - 1; i >= 0; i--){ 
        heapify(arr, n, i); 
    } 
} 
 
void heapSort(int arr[], int n){ 
    buildMaxHeap(arr, n); 
 
    for(int i = n - 1; i > 0; i--){ 
        swapValues(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 
 
int main(){
    cout<<"---Umer Yaseen---"<<endl; 
    cout<<"---2025(S)-AI-35---"<<endl; 
    int arr[] = {40, 10, 30, 50, 20, 60}; 
    int n = 6; 
 
    cout<<"Original array: "; 
    displayArray(arr, n); 
 
    buildMaxHeap(arr, n); 
    cout<<"Array after building Max Heap: "; 
    displayArray(arr, n); 
 
    heapSort(arr, n); 
    cout<<"Sorted array in ascending order: "; 
    displayArray(arr, n); 
 
    return 0; 
} 