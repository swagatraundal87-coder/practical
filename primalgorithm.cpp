
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

/*
## **Theory**

Prim's Algorithm is a greedy algorithm used to find the **Minimum Spanning Tree (MST)** of a connected, weighted, undirected graph.

It starts from one vertex and repeatedly selects the minimum-weight edge that connects a visited vertex to an unvisited vertex. It continues until all vertices are connected.

## **Algorithm**

1. Start.
2. Read the number of vertices and the cost adjacency matrix.
3. Replace all zero values with 999 to represent no edge.
4. Mark the first vertex as visited.
5. Find the minimum-weight edge connecting a visited vertex to an unvisited vertex.
6. Display the selected edge and add its weight to the minimum cost.
7. Mark the new vertex as visited.
8. Repeat until `n - 1` edges are selected.
9. Display the minimum cost.
10. Stop.

## **Example**

**Input:**

```
Enter number of vertices: 4

Enter cost adjacency matrix:
0 10 6 5
10 0 0 15
6 0 0 4
5 15 4 0
```

**Output:**

```
Edges in Minimum Spanning Tree:
0 - 3 : 5
3 - 2 : 4
0 - 1 : 10

Minimum cost: 19
```

**Conclusion:** Prim's Algorithm is successfully implemented in C++ to find the Minimum Spanning Tree and calculate its minimum cost.
*/