#include<iostream>
using namespace std;

void removeAll(int arr[],int &n,int value){
    int newsize = 0;

    for(int i =0;i < n;i++){
        if(arr[i] != value){
            arr[newsize] = arr[i];
            newsize++;
        }
    }
    n = newsize;
}

int main() {
    int arr[] = {10, 20, 30, 20, 40, 20};
    int n = 6;

    int value = 20;

    removeAll(arr, n, value);
 cout << "Array after removing " << value << ": ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}  