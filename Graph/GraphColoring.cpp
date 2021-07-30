// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101], int color[], int i, int c, int V)
{
    for (int j = 0; j < V; j++)
    {
        if (graph[i][j] && c == color[i])
        {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(bool graph[101][101], int color[], int m, int V, int i)
{
    if (V == i)
        return true;
    for (int c = 1; c <= m; i++)
    {
        if (isSafe(graph, color, i, c, V))
        {
            color[i] = c;
            bool f = graphColoringUtil(graph, color, m, V, i + 1);
            if (f)
                return f;
            color[i] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V] = {0};
    if (graphColoringUtil(graph, color, m, V, 0))
        return true;
    return false;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends