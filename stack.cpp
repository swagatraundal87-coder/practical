
#include <iostream>
using namespace std;

int stack[100];
int top = -1;

void push(int value)
{
    if (top == 99)
    {
        cout << "Stack Overflow";
    }
    else
    {
        top++;
        stack[top] = value;
        cout << "Element inserted";
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow";
    }
    else
    {
        cout << "Deleted element: " << stack[top];
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty";
    }
    else
    {
        cout << "Stack elements: ";

        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
    }
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
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
## **Theory**

A Stack is a linear data structure that follows the **LIFO (Last In, First Out)** principle. This means the element inserted last is deleted first.

A stack has three main operations:

- **Push:** Inserts an element into the stack.
- **Pop:** Deletes the top element from the stack.
- **Display:** Displays all elements of the stack.

The `top` variable points to the topmost element. Stack Overflow occurs when the stack is full, and Stack Underflow occurs when the stack is empty.

## **Algorithm**

1. Start.
2. Initialize `top = -1`.
3. Display the menu: Push, Pop, Display, Exit.
4. Read the user's choice.
5. If the choice is Push:
   - Check whether the stack is full.
   - If not, increment `top` and insert the element.
6. If the choice is Pop:
   - Check whether the stack is empty.
   - If not, delete the top element and decrement `top`.
7. If the choice is Display:
   - Check whether the stack is empty.
   - If not, display elements from top to bottom.
8. Repeat until the user selects Exit.
9. Stop.

## **Example**

**Operations:**

```
1. Push
Enter value: 10

1. Push
Enter value: 20

1. Push
Enter value: 30

3. Display
Stack elements: 30 20 10

2. Pop
Deleted element: 30

3. Display
Stack elements: 20 10
```

## **Conclusion**

The Stack data structure is successfully implemented using an array in C++ with Push, Pop, and Display operations.
*/