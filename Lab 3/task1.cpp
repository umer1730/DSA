#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
void insertAtEnd(Node*& head,int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode; // agr null ke equal agya to head wo null ho ga
        return;
    }
    Node* current = head;
    while(current->next != NULL){ //loop continue till equal to NULL
        current = current->next;
    }
    current->next = newNode;
}

void insertAtBeginning(Node* & head,int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void display(Node* head){
    Node* current = head;
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}

bool search(Node* head,int key)
{
    Node* current = head;
    while(current != NULL){
        if(current->data == key)
        return true;
        current = current->next;
    }
    return false;
}

void deleteFirst(Node* &head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return; 
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
int main(){
    Node* head = NULL;
    insertAtEnd(head,10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    cout<<"Linked list: "<<endl;
    display(head);
    cout<<endl;

    insertAtBeginning(head,5);
    cout<<"After inserting at beginning: "<<endl;
    display(head);
    if(search(head,20))
    cout<<"20 found"<<endl;
    cout<<endl;
    
    deleteFirst(head);
    cout<<"After deleting first node: "<<endl;
    display(head);

    return 0;
}