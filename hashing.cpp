
#include <iostream>
using namespace std;

int main()
{
    int hashTable[100];
    int size, n, key, index;

    cout << "Enter hash table size: ";
    cin >> size;

    if (size <= 0 || size > 100)
    {
        cout << "Invalid size";
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        hashTable[i] = -1;
    }

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0 || n > size)
    {
        cout << "Invalid number of elements";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> key;

        index = key % size;

        while (hashTable[index] != -1)
        {
            index = (index + 1) % size;
        }

        hashTable[index] = key;
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < size; i++)
    {
        cout << i << " --> " << hashTable[i] << endl;
    }

    return 0;
}
