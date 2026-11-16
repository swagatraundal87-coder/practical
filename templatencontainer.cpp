
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
