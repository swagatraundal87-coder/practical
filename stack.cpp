
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
