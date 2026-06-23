#include<iostream>
using namespace std;
class Circle{
private:
    int radius;
public:    
    void setRadius(int r){
        radius  = r;
    }
    int area(){
        return 3.14 * radius * radius;
    }
};

int main(){
    Circle c;
    c.setRadius(5);

    cout<<"Area of circle: "<<c.area()<<endl;
   
    return 0;
}
