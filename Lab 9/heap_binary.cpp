#include <iostream>
using namespace std;

class PriorityQueueHeap
{
private:
    static const int MAX_SIZE = 100;
    int heap[MAX_SIZE];
    int size;
    // root
    int parent(int index)
    {
        return (index - 1) / 2;
    }
    // root->left
    int leftChild(int index)
    {
        return 2 * index + 1;
    }
 // root->right
    int rightChild(int index)
    {
        return 2 * index + 2;
    }

    void swapValues(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index)
    {
        while (index > 0 && heap[index] > heap[parent(index)])
        {
            swapValues(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index)
    {
        while (true)
        {
            int left = leftChild(index);
            int right = rightChild(index);
            int largest = index;

            if (left < size && heap[left] > heap[largest])
            {
                largest = left;
            }

            if (right < size && heap[right] > heap[largest])
            {
                largest = right;
            }

            if (largest != index)
            {
                swapValues(heap[index], heap[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }

public:
    PriorityQueueHeap()
    {
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == MAX_SIZE;
    }

    void insert(int value)
    {
        if (isFull())
        {
            cout << "Priority Queue is full. Cannot insert "
                 << value << endl;
            return;
        }

        heap[size] = value;
        heapifyUp(size);
        size++;
    }
    // peek function
    int peek()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty" << endl;
            return -1;
        }

        return heap[0];
    }

    int extractMax()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty"<<endl;
            return -1;
        }

        int maxValue = heap[0];
        heap[0] = heap[size - 1];
        size--;

        if (size > 0)
        {
            heapifyDown(0);
        }
        return maxValue;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty"<<endl;
            return;
        }
        cout << "Heap array: ";

        for (int i = 0; i < size; i++)
        {
            cout<<heap[i]<<" ";
        }

        cout<<endl;
    }

    // LAB TASK
    void deleteAtIndex(int index)
    {
        if (isEmpty())
        {
            cout<<"Priority Queue is empty"<<endl;
            return;
        }

        if (index < 0 || index >= size)
        {
            cout<<"Invalid index"<<endl;
            return;
        }

        heap[index] = heap[size - 1];
        size--;

        if (index < size)
        {
            if (index > 0 &&
                heap[index] > heap[parent(index)])
            {
                heapifyUp(index);
            }
            else
            {
                heapifyDown(index);
            }
        }

        cout<<"Element deleted from index "<<index<<endl;
    }
};

int main()
{
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    PriorityQueueHeap pq;

    pq.insert(50);
    pq.insert(30);
    pq.insert(70);
    pq.insert(20);
    pq.insert(40);
    pq.insert(60);
    pq.insert(80);
    pq.insert(90);
    pq.insert(85);

    cout<<"Priority Queue after insertions:"<<endl;
    pq.display();

    cout<<"\nHighest priority value: "<< pq.peek()<<endl;

    cout<<"\nExtracted value: "<< pq.extractMax()<<endl;

    cout<<"\nPriority Queue after one extraction:"<<endl;
    pq.display();

    cout<<"\nExtracted value: "<< pq.extractMax() << endl;

    cout << "\nPriority Queue after second extraction:"<<endl;
    pq.display();

    cout<<"\nDeleting element at index 3..."<<endl;
    pq.deleteAtIndex(3);

    cout<<"\nPriority Queue after deletion:"<< endl;
    pq.display();

    return 0;
}