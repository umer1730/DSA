#include<iostream>
using namespace std;

int maximum(int arr[],int n){
    if (n == 0){
        cout <<"Invalid";
    }
    int maxVal = arr[n];
    for (int i = 0;i<=n;i++){
        if (arr[i] > maxVal){
            maxVal = arr[i];
        }
    }
    return maxVal;

}
int main(){
    int arr[] = {1,2,3,4,9,6,5};
    int n= 7;
    
    cout<<maximum(arr,n);
}