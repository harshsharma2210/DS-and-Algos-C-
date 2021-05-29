#include <bits/stdc++.h>
using namespace std;

int a[8][2] = {{0, -1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

void shortestPath(vector<vector<int>> &graph, int source, int target, int m, int n, int c, int visited[])
{
    if (visited[source]==0])
    {
        visited[source] = 0;
        for (int j = 0; j < graph.size(); j++)
        {
            for (int i = 1; i < 9; i++)
            {
                if (graph[source][i] == 1 && visited[])
                {
                    c++;
                    shor
                }
            }
        }
    }
}

int main()
{
    /* Let us create the example graph discussed above */
    int m, n, s;
    cin >> m >> n >> s;
    int rows = m * n;
    vector<vector<int>> graph(m * n, vector<int>(9, 0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> graph[i][j];
        }
    }
    int count = 0;
    int visited[m * n] = {0};
    shortestPath(graph, 19, 1, m, n, count, visited);
    return 0;
}