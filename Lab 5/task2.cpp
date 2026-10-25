#include<iostream>
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

class CircularLinkedList{
private:
    Node* head;

public:
    CircularLinkedList(){
        head = NULL;
    }

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
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int countNodes()
    {
        if (head == NULL)
            return 0;

        int count = 0;
        Node* temp = head;

        do
        {
            count++;
            temp = temp->next;
        }
        while (temp != head);

        return count;
    }
};

int main()
{
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    CircularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout<<"Total Number of Nodes = "<< list.countNodes();

    return 0;
}