#include<iostream>
using namespace std;

class Student{
public:
    string name;
    int rollno;
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"ROll No: "<<rollno<<endl;
    }
};
int main(){
    Student s1;
    s1.name = "Ali";
    s1.rollno = 101;

    s1.display();
    return 0;
}

