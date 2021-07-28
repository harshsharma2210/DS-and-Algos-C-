// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V;
    cin >> V;
    int indeg[V + 1] = {0};
    vector<int> adj[V + 1];
    for (int i = 0; i < V; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
            if (indeg[x] == 0)
            {
                q.push(x);
                ans[i] = 1;
            }
    }

    int c = 0;
    vector<int> ans;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        c = q.size();
        for (auto x : adj[top])
        {
        }
    }

    return 0;
}
