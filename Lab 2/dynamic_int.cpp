#include<iostream>
using namespace std;

class DynamicArray{
public:
    int array[5];
    int size;
    DynamicArray(int s){
        size = s;
    }
    void dataset(){
        cout << "Enter " << size << " integers:" << endl;
        for(int i = 0; i < size; i++){
            cin >> array[i];
        }
    }
    void display() {
        cout << "Array elements are:" << endl;
        for(int i = 0; i < size; i++){
            cout << array[i]<<" " ;
        }
        cout << endl;
    }
};
int main(){
    DynamicArray *obj = new DynamicArray(5);

    obj->dataset();

    delete obj;
    
    return 0;
}