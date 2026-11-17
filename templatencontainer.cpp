
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void display(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    vector<int> v;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    cout << "Original vector: ";
    display(v);

    sort(v.begin(), v.end());

    cout << "\nSorted vector: ";
    display(v);

    v.push_back(100);

    cout << "\nAfter inserting 100: ";
    display(v);

    return 0;
}
/*
## **Theory**

A Vector is a dynamic array in C++ STL (Standard Template Library). Its size can increase or decrease automatically during program execution.

This program uses the following STL functions:

- **push_back():** Adds an element at the end of the vector.
- **sort():** Sorts the elements in ascending order.
- **begin():** Returns an iterator to the first element.
- **end():** Returns an iterator after the last element.
- **display():** A template function used to display vector elements.

A template allows the same function to work with different data types.

## **Algorithm**

1. Start.
2. Create an empty integer vector.
3. Read the number of elements.
4. Read elements and insert them using `push_back()`.
5. Display the original vector using the `display()` function.
6. Sort the vector in ascending order using `sort()`.
7. Display the sorted vector.
8. Insert 100 at the end using `push_back()`.
9. Display the updated vector.
10. Stop.

## **Example**

**Input:**

```
Enter number of elements: 5
Enter elements: 40 10 30 20 50
```

**Output:**

```
Original vector: 40 10 30 20 50
Sorted vector: 10 20 30 40 50
After inserting 100: 10 20 30 40 50 100
```

## **Conclusion**

The C++ STL Vector is successfully implemented using a template function, `push_back()`, and `sort()` to store, display, insert, and sort elements.
*/