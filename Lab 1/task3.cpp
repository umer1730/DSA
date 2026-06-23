#include<iostream>
using namespace std;

const int capacity = 100;

int arr[capacity];
int n=0;

int search(int value){
    for(int i=0;i < n;i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}
int main(){
    int index;
    for (int val = 60;val<89;val += 2){
        arr[n] = val;
        n++;
    }
    index  = search(66);
    cout<<index;
    return 0;
}