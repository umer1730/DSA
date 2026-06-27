#include<iostream>
using namespace std;

void reverseArray(int arr[],int n){
    for(int i = n-1;i >= 0;i--){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    reverseArray(arr,n);
}