
#include <iostream>
using namespace std;

int main()
{
    int n, i, key;
    int found = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements: ";

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        cout << "Element found at position: " << i + 1;
    }
    else
    {
        cout << "Element not found!";
    }

    return 0;
}
/*
## **1. Theory**

**Linear Search** is a simple searching technique used to find an element in an array. It checks each element one by one until the required element is found or the array ends.

It can be used on both sorted and unsorted arrays.

## **2. Algorithm**

1. Start.
2. Read the number of elements and array elements.
3. Read the element to be searched (`key`).
4. Start a loop from `i = 0` to `n-1`.
5. Compare each array element with `key`.
6. If both are equal, set `found = 1` and stop the loop.
7. If the element is found, display its position.
8. Otherwise, display "Element not found".
9. Stop.

## **3. Example**

**Input:**

```
Enter number of elements: 5
Enter array elements:
10 20 30 40 50

Enter element to search: 30
```

**Working:**

- Compare 30 with 10 → Not matched.
- Compare 30 with 20 → Not matched.
- Compare 30 with 30 → Matched.

**Output:**

```
Element found at position: 3
```

## **4. Conclusion**

Thus, we have successfully implemented the Linear Search technique in C++ to find an element in an array.
*/
