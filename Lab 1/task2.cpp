#include<iostream>
using namespace std;
const int CAPACITY = 100; 
int arr[CAPACITY];
int n=0;
void traverse(){
    if (n == 0){
        cout<<"Array is empty\n";
        return; 
    }
    cout<<"Array elements: ";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    
    for (int val = 60; val < 89; val+=2){   
        arr[n] = val; 
        n++; 
} 
    cout<<"n= "<<n<<"\n"; 
    traverse();

    return 0;
}
