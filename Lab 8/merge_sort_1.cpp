#include <iostream>
using namespace std;
// class node
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
// class for linked list
class LinkedList
{
private:
    Node* head;

    void splitList(Node* source, Node*& left, Node*& right)
    {
        Node* slow = source;
        Node* fast = source->next;

        while (fast != NULL)
        {
            fast = fast->next;

            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        left = source;
        right = slow->next;
        slow->next = NULL;
    }
    // merge sorted list 
    Node* mergeSortedLists(Node* left, Node* right)
    {
        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        Node* result = NULL;

        if (left->data <= right->data)
        {
            result = left;
            result->next = mergeSortedLists(left->next, right);
        }
        else
        {
            result = right;
            result->next = mergeSortedLists(left, right->next);
        }

        return result;
    }

    Node* mergeSortRec(Node* start)
    {
        if (start == NULL || start->next == NULL)
            return start;

        Node* left = NULL;
        Node* right = NULL;

        splitList(start, left, right);

        left = mergeSortRec(left);
        right = mergeSortRec(right);

        return mergeSortedLists(left, right);
    }

public:
    LinkedList()
    {
        head = NULL;
    }
// inserted value at the end
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
// function for merge sort
    void mergeSort()
    {
        head = mergeSortRec(head);
    }
};

int main()
{
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    LinkedList list;

    list.insertAtEnd(65);
    list.insertAtEnd(25);
    list.insertAtEnd(80);
    list.insertAtEnd(10);
    list.insertAtEnd(45);
    list.insertAtEnd(30);

    cout << "Original List: ";
    list.display();

    list.mergeSort();

    cout << "Sorted List: ";
    list.display();

    return 0;
}