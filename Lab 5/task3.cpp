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
// constructor
public:
    CircularLinkedList()
    {
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
// search function
    void search(int key)
    {
        if (head == NULL)
        {
            cout << "List is Empty.";
            return;
        }

        Node* temp = head;
        int position = 1;

        do
        {
            if (temp->data == key)
            {
                cout << key << " found at position "
                     << position;
                return;
            }

            temp = temp->next;
            position++;

        } while (temp != head);

        cout << key << " not found.";
    }
};

int main()
{
    CircularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    int key;
// take value from user
    cout << "Enter element to search: ";
    cin >> key;

    list.search(key);

    return 0;
}