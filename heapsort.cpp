
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int n, arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid size";
        return 0;
    }

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
## **1. Theory**

**Heap Sort** is a sorting technique based on the Binary Heap data structure. It first converts the array into a Max Heap and then repeatedly moves the largest element to the end of the array.

In this program, elements are sorted in ascending order.

## **2. Algorithm**

1. Start.
2. Read the number of elements and array elements.
3. Convert the array into a Max Heap using the `heapify()` function.
4. Swap the root element (largest element) with the last element.
5. Reduce the heap size by one.
6. Apply Heapify again to maintain the Max Heap.
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

- Original array: `5 3 4 1 2`
- Max Heap: `5 3 4 1 2`
- Pass 1: `4 3 2 1 5`
- Pass 2: `3 1 2 4 5`
- Pass 3: `2 1 3 4 5`
- Pass 4: `1 2 3 4 5`

**Output:**

```
Sorted array: 1 2 3 4 5
```

## **4. Conclusion**

Thus, we have successfully implemented the Heap Sort technique in C++ using a Max Heap to arrange array elements in ascending order.
*/