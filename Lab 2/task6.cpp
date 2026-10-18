#include<iostream>
using namespace std;

 class Student{
    public:
    string name;
    int rollno;

    Student(){
        name = "";
        rollno = 0;
    }

    void dataset(string n,int r){
        name = n;
        rollno = r;
    }    
    void display(){
        cout<<name<<"-"<<rollno<<endl;
    }
};

int main(){
    int n;
    cout<<"Enter number of students: ";
    cin>>n;

    Student *students = new Student[n];

    for(int i = 0;i< n;i++){
        string name;
        int roll;

        cout<<"Enter name and roll no: ";
        students[i].dataset(name,roll);
    }
    cout<<"\n Student List: \n";
    for(int i = 0;i < n;i++){
        students[i].display();
    }
    delete[]students;

    return 0;

}
