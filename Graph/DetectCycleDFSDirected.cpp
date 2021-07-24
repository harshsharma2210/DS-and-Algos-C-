// Detect cycle in a directed graph
// Medium Accuracy: 30.19% Submissions: 100k+ Points: 4
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// Example 1:

// Input:

// Output: 1
// Explanation: 3 -> 3 is a cycle

// Example 2:

// Input:

// Output: 0
// Explanation: no cycle in the graph

// Your task:
// You don’t need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in a directed graph.
    bool dfs(int i, vector<int> adj[], int vis[], int order[])
    {
        vis[i] = 1;
        order[i] = 1;
        for (auto x : adj[i])
        {
            if (!vis[x])
            {
                bool flag = dfs(x, adj, vis, order);
                if (flag)
                    return true;
            }
            else if (order[x] == 1)
            {
                return true;
            }
        }
        order[i] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int vis[V + 1] = {0}, order[V + 1] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bool flag = dfs(i, adj, vis, order);
                if (flag)
                {
                    return flag;
                }
            }
        }
        return false;
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends