#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    int rollno;

    Student(string n,int r){   // No need to initialize object
        name = n;
        rollno = r;

    }
    void display(){
        cout<<name <<"-"<< rollno<<endl;
    }
};
int main(){
    Student s1("Sara",102);

    s1.display();
    return 0;
}