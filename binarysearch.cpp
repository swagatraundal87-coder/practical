
#include <iostream>
using namespace std;

int main()
{
    int n, i, key;
    int low, high, mid;
    int found = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements in sorted order: ";

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            found = 1;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found == 1)
    {
        cout << "Element found at position: " << mid + 1;
    }
    else
    {
        cout << "Element not found!";
    }

    return 0;
}
/*
## **1. Theory**

**Binary Search** is a searching technique used to find an element in a sorted array. It repeatedly divides the array into two halves until the required element is found or the search space becomes empty.

**Note:** The array must be sorted before applying Binary Search.

## **2. Algorithm**

1. Start.
2. Read the number of elements and array elements in sorted order.
3. Read the element to be searched.
4. Set `low = 0` and `high = n-1`.
5. Calculate the middle position using `mid = (low + high) / 2`.
6. If `arr[mid] == key`, the element is found.
7. If `arr[mid] < key`, search the right half by setting `low = mid + 1`.
8. Otherwise, search the left half by setting `high = mid - 1`.
9. Repeat until the element is found or `low > high`.
10. Display the result and stop.

## **3. Example**

**Input:**

```
Enter number of elements: 5
Enter array elements in sorted order:
10 20 30 40 50

Enter element to search: 40
```

**Working:**

| Step | Low | High | Mid | Value |
| ---- | --- | ---- | --- | ----- |
| 1    | 0   | 4    | 2   | 30    |
| 2    | 3   | 4    | 3   | 40    |

Element found at index 3, so its position is 4.

**Output:**

```
Element found at position: 4
```

## **4. Conclusion**

Thus, we have successfully implemented the Binary Search technique in C++ to search an element in a sorted array.
*/
