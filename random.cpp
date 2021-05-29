#include <bits/stdc++.h>
using namespace std;
class Graph
{
	int **edges;
	int *path;
	int *visited;

public:
	Graph(int n, int m)
	{
		edges = new int *[m * n + 1];

		path = new int[n * m + 1];
		visited = new int[n * m + 1];
		for (int i = 0; i < n * m + 1; i++)
		{
			edges[i] = new int[10];
			path[i] = -1;
			visited[i] = INT_MAX;
		}
	}
	void addEdge(int x, int y, int count)
	{
		edges[x][count] = y;
		;
	}
	void bfs(int src, int z, int count[])
	{
		visited[src] = z;
		z = z + 1;
		for (int i = 0; i < count[src]; i++)
		{
			if (visited[edges[src][i]] > z)
			{
				path[edges[src][i]] = src;
				bfs(edges[src][i], z, count);
			}
		}
	}
	void path_finding(int j)
	{
		if (path[j] == -1)
		{
			cout << j << " ";
			return;
		}
		else
		{
			path_finding(path[j]);
			cout << j << " ";
		}
	}
	void path_print()
	{
		for (int i = 1; i < 41; i++)
		{
			cout << path[i] << " ";
		}
	}
};
int main()
{
	int n, m;
	cin >> m;
	cin >> n;
	Graph G(m, n);
	int src;
	cin >> src;
	int countarr[m * n + 1];
	int matrix[m * n + 1][8];
	for (int i = 1; i < m * n + 1; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < 8; j++)
		{
			cin >> matrix[i][j];
		}
	}
	for (int i = 1; i < m * n + 1; i++)
	{
		int c = 0;
		if (matrix[i][0] == 1)
		{
			G.addEdge(i, i - n, c);
			c++;
		}
		if (matrix[i][1] == 1)
		{
			G.addEdge(i, i - n + 1, c);
			c++;
		}
		if (matrix[i][2] == 1)
		{
			G.addEdge(i, i + 1, c);
			c++;
		}
		if (matrix[i][3] == 1)
		{
			G.addEdge(i, i + n + 1, c);
			c++;
		}
		if (matrix[i][4] == 1)
		{
			G.addEdge(i, i + n, c);
			c++;
		}
		if (matrix[i][5] == 1)
		{
			G.addEdge(i, i + n - 1, c);
			c++;
		}
		if (matrix[i][6] == 1)
		{
			G.addEdge(i, i - 1, c);
			c++;
		}
		if (matrix[i][7] == 1)
		{
			G.addEdge(i, i - n - 1, c);
			c++;
		}
		countarr[i] = c;
	}
	G.bfs(src, 0, countarr);
	G.path_finding(1);
	cout << endl;
	G.path_finding(n);
	cout << endl;
	G.path_finding((m - 1) * (n) + 1);
	cout << endl;
	G.path_finding(m * n);
}