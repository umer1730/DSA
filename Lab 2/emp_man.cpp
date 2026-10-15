#include<iostream>
using namespace std;

class Employee{
private:
    double salary;
protected:
    string department;
public:
    string name;
    Employee(string n,double s,string dept){
        name = n;
        salary = s;
        department = dept;

    }
    void showSalary(){
        cout<< "Salary: "<<salary<<endl;
    }
    void showDepartment(){
        cout<<"Deprtment: "<<department<<endl;
    }
};
class Manager : public Employee{
public: 
    Manager(string n, double s,string dept): Employee(n,s,dept){}

    void accessMembers(){
        cout<<"Name (public) = "<<name<<endl;

        cout<< "Depart (protected) = "<<department<<endl;
    }
};
int main(){
    Manager m1("Alice",75000,"HR");
    m1.accessMembers();
    cout<<"Name(public) = "<<m1.name <<endl;

    return 0;
}