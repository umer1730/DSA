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

class LinkedList
{
private:
    Node* head;

    void appendNode(Node*& listHead, Node*& listTail, Node* node)
    {
        node->next = NULL;

        if (listHead == NULL)
        {
            listHead = node;
            listTail = node;
        }
        else
        {
            listTail->next = node;
            listTail = node;
        }
    }

    Node* getTail(Node* start)
    {
        if (start == NULL)
            return NULL;

        while (start->next != NULL)
        {
            start = start->next;
        }

        return start;
    }

    Node* concatenate(Node* less, Node* equal, Node* greater)
    {
        Node* newHead = NULL;
        Node* newTail = NULL;

        if (less != NULL)
        {
            newHead = less;
            newTail = getTail(less);
        }

        if (equal != NULL)
        {
            if (newHead == NULL)
            {
                newHead = equal;
                newTail = getTail(equal);
            }
            else
            {
                newTail->next = equal;
                newTail = getTail(equal);
            }
        }

        if (greater != NULL)
        {
            if (newHead == NULL)
            {
                newHead = greater;
            }
            else
            {
                newTail->next = greater;
            }
        }

        return newHead;
    }

    Node* quickSortRec(Node* start)
    {
        if (start == NULL || start->next == NULL)
            return start;

        int pivot = start->data;

        Node* lessHead = NULL;
        Node* lessTail = NULL;

        Node* equalHead = NULL;
        Node* equalTail = NULL;

        Node* greaterHead = NULL;
        Node* greaterTail = NULL;

        Node* current = start;

        while (current != NULL)
        {
            Node* nextNode = current->next;
            current->next = NULL;

            if (current->data < pivot)
            {
                appendNode(lessHead, lessTail, current);
            }
            else if (current->data == pivot)
            {
                appendNode(equalHead, equalTail, current);
            }
            else
            {
                appendNode(greaterHead, greaterTail, current);
            }

            current = nextNode;
        }

        lessHead = quickSortRec(lessHead);
        greaterHead = quickSortRec(greaterHead);

        return concatenate(lessHead, equalHead, greaterHead);
    }

public:
    LinkedList()
    {
        head = NULL;
    }

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

    void quickSort()
    {
        head = quickSortRec(head);
    }
};

int main()
{
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    LinkedList list;

    list.insertAtEnd(55);
    list.insertAtEnd(20);
    list.insertAtEnd(70);
    list.insertAtEnd(20);
    list.insertAtEnd(40);
    list.insertAtEnd(90);
    list.insertAtEnd(10);

    cout << "Original List: ";
    list.display();

    list.quickSort();

    cout << "Sorted List: ";
    list.display();

    return 0;
}