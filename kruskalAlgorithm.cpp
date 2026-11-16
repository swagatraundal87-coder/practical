
#include <iostream>
using namespace std;

int parent[10];

int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }

    return i;
}

void unionSet(int a, int b)
{
    int x = find(a);
    int y = find(b);

    parent[x] = y;
}

int main()
{
    int n, cost[10][10];
    int minCost = 0;
    int edges = 0;
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

        parent[i] = i;
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        min = 999;
        a = -1;
        b = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a == -1)
        {
            cout << "Graph is not connected";
            return 0;
        }

        int x = find(a);
        int y = find(b);

        if (x != y)
        {
            cout << a << " - " << b << " : " << min;

            minCost = minCost + min;
            unionSet(a, b);
            edges++;
            cout << endl;
        }

        cost[a][b] = 999;
        cost[b][a] = 999;
    }

    cout << "\nMinimum cost: " << minCost;

    return 0;
}
