
#include <iostream>
using namespace std;

int main()
{
    int n, i, j, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements: ";

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Sorted array: ";

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
/*
## **1. Theory**

**Insertion Sort** is a simple sorting technique that arranges elements in ascending or descending order. It takes one element at a time and inserts it into its correct position in the already sorted part of the array.

In this program, elements are sorted in ascending order.

## **2. Algorithm**

1. Start.
2. Read the number of elements and array elements.
3. Start the loop from `i = 1` to `n-1`.
4. Store the current element in `key`.
5. Compare `key` with the previous elements.
6. If the previous element is greater than `key`, shift it one position to the right.
7. Insert `key` at its correct position.
8. Repeat until all elements are sorted.
9. Display the sorted array.
10. Stop.

## **3. Example**

**Input:**

```
Enter number of elements: 5
Enter array elements:
5 3 4 1 2
```

**Working:**

- Pass 1: `3 5 4 1 2`
- Pass 2: `3 4 5 1 2`
- Pass 3: `1 3 4 5 2`
- Pass 4: `1 2 3 4 5`

**Output:**

```
Sorted array: 1 2 3 4 5
```

## **4. Conclusion**

Thus, we have successfully implemented the Insertion Sort technique in C++ to arrange array elements in ascending order.
*/