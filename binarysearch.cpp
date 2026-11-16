
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
