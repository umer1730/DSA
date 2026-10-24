#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
// circular linked list
class CircularLinkedList
{
private:
    Node* head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }
// insert value
    void insert(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is Empty.";
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        while (temp != head);

        cout << "Head";
    }
};

int main()
{
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    CircularLinkedList list;
    cout<<"Enter 5 values:\n";
    //take value by user
    for (int i = 0; i < 5; i++)
    {
        int value;
        cin>>value;
        list.insert(value);
    }
    cout << "\nCircular Linked List:\n";
    list.display();
    return 0;
}