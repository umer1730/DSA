#include<iostream>
using namespace std;

class Rectangle{
    public:
    int length;
    int width;
    void calc_area(){
        cout<<"Area: "<<length * width<<endl;
    }
};

int main(){
    Rectangle r;
    r.length =  3;
    r.width = 4;
    r.calc_area();

    return 0;
}


