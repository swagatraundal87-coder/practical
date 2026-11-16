
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
