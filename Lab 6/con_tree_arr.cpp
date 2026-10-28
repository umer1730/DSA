#include<iostream>
using namespace std;

int main(){
    char tree[7];

    tree[1] = 'A';
    tree[2] = 'B';
    tree[3] = 'C';
    tree[4] = 'D';
    tree[5] = 'E';
    tree[6] = 'F';

    for(int i = 1;i <=6; i++){
        cout<<"Index "<<i<<": "<<tree[i]<<endl;
    }
    return 0;
}