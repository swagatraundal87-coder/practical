
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

/*
## **1. Theory**

**Kruskal's Algorithm** is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, weighted and undirected graph.

It selects edges in increasing order of weight. It does not select an edge if it forms a cycle.

**Minimum Spanning Tree (MST):** A tree that connects all vertices with minimum total edge weight without forming a cycle.

## **2. Algorithm**

1. Start.
2. Read the number of vertices and cost adjacency matrix.
3. Initialize each vertex as a separate set.
4. Find the minimum-weight edge in the graph.
5. Check whether the edge forms a cycle using the `find()` function.
6. If it does not form a cycle:
   - Add the edge to the Minimum Spanning Tree.
   - Add its weight to the minimum cost.
   - Join the two sets using `unionSet()`.
7. Repeat until `n-1` edges are selected.
8. Display the selected edges and minimum cost.
9. Stop.

## **3. Example**

**Input:**

```
Enter number of vertices: 4

Enter cost adjacency matrix:
0 10 6 5
10 0 0 15
6 0 0 4
5 15 4 0
```

**Working:**

The algorithm selects edges in increasing order of weight:

- Edge 2 - 3 = 4
- Edge 0 - 3 = 5
- Edge 0 - 1 = 10

All four vertices are connected without forming a cycle.

**Output:**

```
Edges in Minimum Spanning Tree:
2 - 3 : 4
0 - 3 : 5
0 - 1 : 10

Minimum cost: 19
```

## **4. Conclusion**

Thus, we have successfully implemented Kruskal's Algorithm in C++ to find the Minimum Spanning Tree and calculate its minimum cost.
*/