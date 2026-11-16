
#include <iostream>
using namespace std;

int main()
{
    int n, cost[10][10];
    int visited[10] = {0};
    int edges = 0, minCost = 0;
    int min, a, b;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[0] = 1;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        min = 999;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (min == 999)
        {
            cout << "Graph is not connected";
            return 0;
        }

        cout << a << " - " << b << " : " << min << endl;

        minCost = minCost + min;
        visited[b] = 1;
        edges++;
    }

    cout << "\nMinimum cost: " << minCost;

    return 0;
}

