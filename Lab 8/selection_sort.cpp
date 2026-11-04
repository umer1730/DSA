#include<iostream>
using namespace std;

void display(int arr[],int size){
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selectionSort(int arr[],int size){
    for(int i = 0;i<size-1;i++){
        // Find the smallest element in remaining array
        int minIndex = i;
        // Find the smallest element in remaining array
        for(int j = i+1;j < size;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        // Swap smallest element with current position
        int temp = arr[i];
        arr[i]  = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main(){
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;

    int arr[10] = {40,10,70,20,90,50,30,80,60,15};
    cout<<"Array before sorting: ";
    display(arr,10);

    selectionSort(arr,10);

    cout<<"Array after sorting: ";
    display(arr,10);
    return 0;
}