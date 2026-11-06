#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

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

class HashTable
{
private:
    Node* table[TABLE_SIZE];
    int count;

    int hashFunction(int key)
    {
        int index = key % TABLE_SIZE;
        if(index < 0)
            index += TABLE_SIZE;
        return index;
    }
 // function to destry chain
    void destroyChain(Node* head)
    {
        Node* temp;

        while(head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    HashTable()
    {
        count = 0;

        for(int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    ~HashTable()
    {
        for(int i = 0; i < TABLE_SIZE; i++)
            destroyChain(table[i]);
    }

    void insert(int key)
    {
        if(search(key))
        {
            cout << "Duplicate value ignored: " << key << endl;
            return;
        }

        int index = hashFunction(key);

        Node* newNode = new Node(key);

        newNode->next = table[index];
        table[index] = newNode;

        count++;

        cout << key << " inserted at index "
             << index << endl;
    }

    bool search(int key)
    {
        int index = hashFunction(key);

        Node* current = table[index];

        while(current != NULL)
        {
            if(current->data == key)
                return true;

            current = current->next;
        }

        return false;
    }

    void remove(int key)
    {
        int index = hashFunction(key);

        Node* current = table[index];
        Node* previous = NULL;

        while(current != NULL && current->data != key)
        {
            previous = current;
            current = current->next;
        }

        if(current == NULL)
        {
            cout << key << " not found" << endl;
            return;
        }

        if(previous == NULL)
            table[index] = current->next;
        else
            previous->next = current->next;

        delete current;
        count--;

        cout << key << " deleted from index "
             << index << endl;
    }

    void display()
    {
        cout << "\nHash Table:\n";

        for(int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";

            Node* current = table[i];

            while(current != NULL)
            {
                cout << current->data << " -> ";
                current = current->next;
            }

            cout << "NULL" << endl;
        }
    }

    double loadFactor()
    {
        return (double)count / TABLE_SIZE;
    }
};

int main()
{
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    HashTable ht;

    ht.insert(101);
    ht.insert(205);
    ht.insert(312);
    ht.insert(111);
    ht.insert(425);
    ht.insert(121);
    ht.insert(501);

    ht.display();

    cout << "\nLoad Factor = "
         << ht.loadFactor() << endl;

    int key;

    cout << "\nEnter value to search: ";
    cin >> key;

    if(ht.search(key))
        cout << key << " Found\n";
    else
        cout << key << " Not Found\n";

    cout << "\nDeleting 111...\n";
    ht.remove(111);

    ht.display();
    cout << "\nLoad Factor = "<< ht.loadFactor() << endl;
    return 0;
}