#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void insertBeginning(Node* &head, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd(Node* &head, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode; // list is empty
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next; // move forward untill you reach the last one
    }
    temp->next = newNode; //new node at the end
}

void display(Node* head){
    if(head == NULL){
        cout<<"List is empty\n";
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

void search(Node* head, int key){
    Node* temp = head;
    int pos = 1;

    while(temp != NULL){
        if(temp->data == key){
            cout<<"Element found at position "<<pos<<endl;
            return;
        }
        temp = temp->next;
        pos++; // iteration untill the value not equal
    }
    cout<<"Element not found\n";
}

void deleteFirst(Node* &head){
    if(head == NULL){
        cout<<"List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next; 
    delete temp; // del old temp
    cout<<"First node deleted\n";
}

int main(){
    Node* head = NULL;
    int choice, value;

    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    do{
        cout<<"\n===== LINKED LIST MENU =====\n";
        cout<<"1. Insert at Beginning\n";
        cout<<"2. Insert at End\n";
        cout<<"3. Display List\n";
        cout<<"4. Search Element\n";
        cout<<"5. Delete First Node\n";
        cout<<"6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                insertBeginning(head, value);
                break;

            case 2:
                cout<<"Enter value: ";
                cin>>value;
                insertEnd(head, value);
                break;

            case 3:
                display(head);
                break;

            case 4:
                cout<<"Enter value to search: ";
                cin>>value;
                search(head, value);
                break;

            case 5:
                deleteFirst(head);
                break;

            case 6:
                cout<<"Exiting program...\n";
                break;

            default:
                cout<<"Invalid choice!\n";
        }

    }while(choice != 6);

    return 0;
}