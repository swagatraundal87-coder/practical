
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
/*
## **1. Theory**

**Hashing** is a technique used to store data in a hash table using a hash function. Linear Probing is a collision-handling technique used when two or more elements get the same index.

If a position is already occupied, it checks the next position until an empty position is found.

**Hash Function:**

\\[ h(key) = key \\% size \\]

## **2. Algorithm**

1. Start.
2. Read the hash table size.
3. Initialize all positions of the hash table with `-1`.
4. Read the number of elements.
5. Read each element.
6. Calculate the index using `key % size`.
7. If the position is occupied, check the next position.
8. Repeat until an empty position is found.
9. Insert the element at that position.
10. Display the hash table.
11. Stop.

## **3. Example**

**Input:**

```
Enter hash table size: 7
Enter number of elements: 5

Enter value: 10
Enter value: 20
Enter value: 15
Enter value: 7
Enter value: 17
```

**Working:**

Hash function: `key % 7`

- 10 % 7 = 3 → Insert at index 3.
- 20 % 7 = 6 → Insert at index 6.
- 15 % 7 = 1 → Insert at index 1.
- 7 % 7 = 0 → Insert at index 0.
- 17 % 7 = 3 → Index 3 is occupied, so insert at index 4.

**Output:**

```
Hash Table:
0 --> 7
1 --> 15
2 --> -1
3 --> 10
4 --> 17
5 --> -1
6 --> 20
```

## **4. Conclusion**

Thus, we have successfully implemented Hashing using Linear Probing in C++ to handle collisions and store elements in a hash table.
*/