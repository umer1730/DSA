#include<iostream>
using namespace std;

class Student{
public:
    string name;
    int rollno;

    Student(string n, int r){
        name = n;
        rollno = r;
    }
    void display(){
        cout<<name<<"-"<<rollno<<endl;
    }
};
int main(){
    Student s1("Ali",101);
    s1.display();

    Student *s2 = new Student("Arslan",104);
    s2->display();
    delete s2;

    return 0;
}