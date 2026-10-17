#include<iostream>
using namespace std;

int main(){
    int x = 10;
    int *ptr = &x;

    cout<<"Value of x: "<<x<<endl;
    cout<<"Adress of x: "<<&x<<endl;
    cout<<"Pointer Value : "<<ptr<<endl;
    cout<<"Value via pinter : "<<*ptr<<endl;
}
