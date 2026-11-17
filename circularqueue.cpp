
#include <iostream>
using namespace std;

int queue[100];
int front = -1, rear = -1;
int size;

void insert(int value)
{
    if ((rear + 1) % size == front)
    {
        cout << "Queue is full";
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % size;
        queue[rear] = value;

        cout << "Element inserted";
    }
}

void deleteElement()
{
    if (front == -1)
    {
        cout << "Queue is empty";
    }
    else
    {
        cout << "Deleted element: " << queue[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty";
    }
    else
    {
        cout << "Queue elements: ";

        int i = front;

        while (true)
        {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }
    }
}

int main()
{
    int choice, value;

    cout << "Enter queue size: ";
    cin >> size;

    if (size <= 0 || size > 100)
    {
        cout << "Invalid size";
        return 0;
    }

    do
    {
        cout << "\n\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                deleteElement();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}

/*
## **1. Theory**

A **Circular Queue** is a linear data structure in which the last position is connected to the first position, forming a circle. It follows the FIFO (First In First Out) principle.

Main operations:

- **Insert:** Adds an element to the queue.
- **Delete:** Removes an element from the front.
- **Display:** Displays all queue elements.

## **2. Algorithm**

1. Start.
2. Initialize `front = -1` and `rear = -1`.
3. Read the queue size.
4. Display the menu.
5. If Insert is selected:
   - Check whether the queue is full.
   - If space is available, insert the element at the rear.
6. If Delete is selected:
   - Check whether the queue is empty.
   - If not empty, delete the front element.
7. If Display is selected, print all queue elements.
8. Repeat until Exit is selected.
9. Stop.

## **3. Example**

**Operations:**

```
Enter queue size: 5

Insert 10
Insert 20
Insert 30
Display
Delete
Display
```

**Output:**

```
Queue elements: 10 20 30

Deleted element: 10

Queue elements: 20 30
```

**Working:**

- Initially, the queue is empty.
- Insert 10, 20 and 30 into the queue.
- Delete removes 10 from the front.
- Remaining elements are 20 and 30.

## **4. Conclusion**

Thus, we have successfully implemented a Circular Queue in C++ and performed Insert, Delete and Display operations using an array.
*/