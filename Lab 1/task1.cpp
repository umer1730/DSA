#include<iostream>
using namespace std;

const int capacity = 100;
int arr[capacity];
int n = 0;

int main(){
    for(int val = 60;val < 89;val +=2){
        arr[n] = val;
        n++;
    }
    cout<<"n = "<<n<<"\n";
    return 0;
}       