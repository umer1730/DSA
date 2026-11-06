#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class LinearHashTable
{
private:
    int table[TABLE_SIZE];
    int status[TABLE_SIZE];

    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:

    LinearHashTable()
    {
        for(int i = 0; i < TABLE_SIZE; i++)
        {
            status[i] = 0;
            table[i] = -1;
        }
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        int start = index;

        do
        {
            if(status[index] == 0 || status[index] == 2)
            {
                table[index] = key;
                status[index] = 1;

                cout << key
                     << " inserted at index "
                     << index << endl;

                return;
            }

            index = (index + 1) % TABLE_SIZE;

        } while(index != start);

        cout << "Hash Table Full\n";
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        int start = index;

        do
        {
            if(status[index] == 0)
                return false;

            if(status[index] == 1 && table[index] == key)
                return true;

            index = (index + 1) % TABLE_SIZE;

        } while(index != start);

        return false;
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        int start = index;

        do
        {
            if(status[index] == 0)
            {
                cout << key
                     << " not found\n";
                return;
            }

            if(status[index] == 1 && table[index] == key)
            {
                status[index] = 2;

                cout << key
                     << " deleted\n";
                return;
            }

            index = (index + 1) % TABLE_SIZE;

        } while(index != start);

        cout << key << " not found\n";
    }

    void display()
    {
        cout << "\nHash Table:\n";

        for(int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << " : ";

            if(status[i] == 0)
                cout << "EMPTY";

            else if(status[i] == 2)
                cout << "DELETED";

            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main()
{
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    LinearHashTable ht;

    int choice, value;

    do
    {
        cout << "\n===== HASH TABLE MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            ht.insert(value);
            ht.display();
            break;

        case 2:
            cout << "Enter Value: ";
            cin >> value;

            if(ht.search(value))
                cout << "Found\n";
            else
                cout << "Not Found\n";

            break;

        case 3:
            cout << "Enter Value: ";
            cin >> value;
            ht.remove(value);
            ht.display();
            break;

        case 4:
            ht.display();
            break;

        case 5:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while(choice != 5);

    return 0;
}