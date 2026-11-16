
#include <iostream>
using namespace std;

int main()
{
    int n, i, j, temp;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements: ";

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

**Bubble Sort** is a simple sorting technique used to arrange elements in ascending or descending order. It compares two adjacent elements and swaps them if they are in the wrong order.

In this program, elements are sorted in ascending order.

## **2. Algorithm**

1. Start.
2. Read the number of elements and array elements.
3. Start the outer loop from `i = 0` to `n-2`.
4. Start the inner loop from `j = 0` to `n-i-2`.
5. Compare adjacent elements `arr[j]` and `arr[j+1]`.
6. If `arr[j] > arr[j+1]`, swap the elements.
7. Repeat until all elements are sorted.
8. Display the sorted array.
9. Stop.

## **3. Example**

**Input:**

```
Enter number of elements: 5
Enter array elements:
5 3 4 1 2
```

**Working:**

- Pass 1: `3 4 1 2 5`
- Pass 2: `3 1 2 4 5`
- Pass 3: `1 2 3 4 5`
- Pass 4: `1 2 3 4 5`

**Output:**

```
Sorted array: 1 2 3 4 5
```

## **4. Conclusion**

Thus, we have successfully implemented the Bubble Sort technique in C++ to arrange array elements in ascending order.
*/