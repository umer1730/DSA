// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;
// };
// int count(Node* head){
//     int count = 0;
//     Node* current = head;
//     while(current != NULL){
//         count++;
//         current = current->next;;
//     }
//     return count;
// }

// int main(){
//     Node* n1 = new Node();
//     Node* n2 = new Node();
//     Node* n3 = new Node();
//     Node* n4 = new Node();
//     Node* n5 = new Node();

//     n1->data = 10;
//     n2->data = 20;
//     n3->data = 30;
//     n4->data = 40;
//     n5->data = 50;

//     n1->next = n2;
//     n2->next = n3;
//     n3->next = n4;
//     n4->next = n5;
//     n5->next = NULL;

//     int total = count(n1);
//     cout<<"Total nodes = "<<total;
//     return 0;
// }
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// function to count nodes
int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    // create linked list in compact way
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    cout << "Total nodes = " << countNodes(head);
}