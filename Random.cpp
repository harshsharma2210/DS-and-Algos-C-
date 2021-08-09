class Solution
{
public:
    int dp[51][51];
    int printMaxSubSquare(vector<vector<int>> &M, int m, int n, int *maxv)
    {
        int res;
        if (m < 0 || n < 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        if (M[m][n] == 1)
        {
            res = 1 + min(printMaxSubSquare(M, m, n - 1, maxv), min(printMaxSubSquare(M, m - 1, n, maxv), printMaxSubSquare(M, m - 1, n - 1, maxv)));
        }
        else
        {

            res = 0;
        }
        *maxv = max(*maxv, res);
        return dp[m][n] = res;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here
        int maxv = 0;
        memset(dp, -1, sizeof(dp));
        printMaxSubSquare(mat, n - 1, m - 1, &maxv);
        return maxv;
    }
};