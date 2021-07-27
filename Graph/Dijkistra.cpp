// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int minDist(bool proc[], vector<int> dist, int V)
    {
        int mini = INT_MAX;
        int minIndex;
        for (int i = 0; i < V; i++)
        {
            if (proc[i] == false && mini > dist[i])
            {
                mini = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        bool proc[V];
        vector<int> dist(V);
        for (int i = 0; i < V; i++)
        {
            proc[i] = false;
            dist[i] = INT_MAX;
        }
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            int min = minDist(proc, dist, V);
            proc[min] = true;
            for (auto v : adj[min])
            {

                if (!proc[v[0]] && (dist[min] + v[1]) < dist[v[0]])
                {
                    dist[v[0]] = dist[min] + v[1];
                }
            }
        }
        return dist;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends