// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find out minimum steps Knight needs to reach target position.
    int vis[1001][1001] = {0};
    void dfs(vector<int> &KnightPos, vector<int> &TargetPos, int N, int vis[][1001], vector<int> count, int c)
    {
        if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1])
        {
            count.push_back(c);
            return;
        }
        if (KnightPos[0] < N || KnightPos[1] < N || KnightPos[0] < 0 || KnightPos[1] < 0 || (vis[KnightPos[0]] && vis[KnightPos[1]]))
        {
            return;
        }
        vis[KnightPos[0]][KnightPos[1]] = 1;

        KnightPos[0] = KnightPos[0] + 2;
        KnightPos[1] = KnightPos[1] + 1;
        ;
        dfs(KnightPos, TargetPos, N, vis, count, c + 1);

        KnightPos[0] = KnightPos[0] - 2;
        KnightPos[1] = KnightPos[1] + 1;
        dfs(KnightPos, TargetPos, N, vis, count, c + 1);

        KnightPos[0] = KnightPos[0] + 2;
        KnightPos[1] = KnightPos[1] - 1;
        dfs(KnightPos, TargetPos, N, vis, count, c + 1);

        KnightPos[0] = KnightPos[0] - 2;
        KnightPos[1] = KnightPos[1] - 1;
        dfs(KnightPos, TargetPos, N, vis, count, c + 1);
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        vector<int> count;
        dfs(KnightPos, TargetPos, N, vis, count, 0);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends