// Detect cycle in an undirected graph
// Medium Accuracy: 35.66% Submissions: 100k+ Points: 4
// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.

// Example 1:

// Input:

// Output: 1
// Explanation: 1->2->3->4->1 is a cycle.
// Example 2:

// Input:

// Output: 0
// Explanation: No cycle in the graph.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not.

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105
// { Driver Code Starts
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in an undirected graph.
    bool dfs(int i, int par, vector<int> adj[], int vis[])
    {
        vis[i] = 1;
        for (auto x : adj[i])
        {
            if (!vis[x])
            {
                bool flag = dfs(x, i, adj, vis);
                if (flag)
                    return true;
            }
            else if (par != x || x == i)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        // Code here
        for (int i = 0; i < V; i++)
        {
            if (vis[i] != 0)
            {
                bool flag = dfs(i, -1, adj, vis);
                if (flag)
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends