#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Returns total number of swaps performed
int bubbleSort(int arr[], int size, bool ascending)
{
    int swaps = 0;

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            bool condition;
            // check sortinfg together
            if(ascending){
                condition = arr[j] > arr[j + 1];
            }
            else{
                condition = arr[j] < arr[j + 1];
            }
            //swap if condition is true
            if(condition){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
            }
        }
    }
    return swaps;
}

int selectionSort(int arr[], int size, bool ascending)
{
    int swaps = 0;
    for(int i = 0; i < size - 1; i++)
    {
        int index = i;
         // Find minimum or maximum element
        for(int j = i + 1; j < size; j++)
        {
            if(ascending){
                if(arr[j] < arr[index])
                    index = j;
            }
            else{
                if(arr[j] > arr[index])
                    index = j;
            }
        }
        if(index != i){
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;

            swaps++;
        }
    }

    return swaps;
}

int main()
{
    cout<<"---Umer Yaseen---"<<endl;
    cout<<"---2025(S)-AI-35---"<<endl;
    
    int size;

    cout <<"Enter Array Size: ";
    cin >> size;

    int bubbleArr[100];
    int selectionArr[100];

    cout <<"Enter Elements:\n";

    for(int i = 0; i < size; i++){
        cin >> bubbleArr[i];
        selectionArr[i] = bubbleArr[i];
    }

    int choice;

    cout << "\n1. Ascending";
    cout << "\n2. Descending";
    cout << "\nEnter Choice: ";
    cin >> choice;

    bool ascending = (choice == 1);
    // Sort arrays and count swaps
    int bubbleSwaps = bubbleSort(bubbleArr, size, ascending);
    int selectionSwaps = selectionSort(selectionArr, size, ascending);

    cout << "\nBubble Sort Result: ";
    display(bubbleArr, size);

    cout << "Bubble Sort Swaps: "<< bubbleSwaps << endl;

    cout << "\nSelection Sort Result: ";
    display(selectionArr, size);

    cout << "Selection Sort Swaps: "<< selectionSwaps << endl;

    cout << "\nComparison:\n";

    if(bubbleSwaps < selectionSwaps)
    {
        cout << "Bubble Sort performed fewer swaps.";
    }
    else if(selectionSwaps < bubbleSwaps)
    {
        cout << "Selection Sort performed fewer swaps.";
    }
    else
    {
        cout << "Both algorithms performed equal swaps.";
    }

    return 0;
}