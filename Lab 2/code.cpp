#include<iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;
    Car(string b, int y){
        brand = b;
        year = y;
    }
    void display(){
        cout << "Car Brand: " << brand << endl;
        cout << "Car Year: " << year << endl;
        cout << endl;
    }
};
int main(){
    Car *car1 = new Car("Ferrari", 2022);
    Car *car2 = new Car("Honda", 2020);

    cout << "Car 1 Details:" << endl;
    car1->display();

    cout << "Car 2 Details:" << endl;
    car2->display();
    delete car1;
    delete car2;

    return 0;
}