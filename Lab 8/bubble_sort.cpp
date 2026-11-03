#include<iostream>
using namespace std;

void display(int arr[],int size){
    for(int i=0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubbleSort(int arr[],int size) {
    // Outer loop controls the number of passes
    for(int i=0;i < size-1;i++) {
        // Inner loop compares adjacent elements
        for(int j=0;j < size-1-i;j++) {
            if(arr[j] > arr[j + 1]) {
                // swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    
    int arr[10] = {40,10,70,20,90,50,30,80,60,15};
    cout<<"Array before sorting: ";
    display(arr,10);

    bubbleSort(arr,10);

    cout<<"Array after sorting: ";
    display(arr,10);
    return 0;
}