#include<iostream>
using namespace std;

class Car{
public:
    string brand;
    int model;
    
    Car(string b,int m){
        brand = b;
        model =  m;
    }
    void display(){
        cout<<brand<<"-"<<model<<endl;
    }
};
int main(){
    Car c1("Corolla",2112);
    c1.display();
    return 0;
}