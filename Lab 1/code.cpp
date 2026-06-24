#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    int year;

public:
    void setDetails(string b, int y) {
        brand = b;
        year = y;
    }

    void display() {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Year: " << year << endl;
        cout << endl;
    }
};

int main() {

    
    Car *car1 = new Car();
    Car *car2 = new Car();

   
    car1->setDetails("Toyota", 2022);
    car2->setDetails("Honda", 2020);

    
    cout << "Car 1 Details:" << endl;
    car1->display();

    cout << "Car 2 Details:" << endl;
    car2->display();

    delete car1;
    delete car2;

    return 0;
}