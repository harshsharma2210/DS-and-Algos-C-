// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isSafe(int x, int y, int row, int col)
    {
        return x >= 0 && y >= 0 && x < row && y < col;
    }
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &kpos, vector<int> &tpos, int N)
    {
        queue<vector<int>> q;
        q.push({kpos[0] - 1, kpos[1] - 1, 0});
        vector<vector<bool>> board(N, vector<bool>(N, false));
        int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
        int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
        board[kpos[0] - 1][kpos[1] - 1] = true;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int x = node[0], y = node[1], s = node[2];
            if (x == tpos[0] - 1 && y == tpos[1] - 1)
            {
                return s;
            }
            for (int i = 0; i < 8; i++)
            {
                int nextX = x + dx[i], nextY = y + dy[i];
                if (isSafe(nextX, nextY, N, N) && !board[nextX][nextY])
                {
                    board[nextX][nextY] = true;
                    q.push({nextX, nextY, s + 1});
                }
            }
        }
        return 0;
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