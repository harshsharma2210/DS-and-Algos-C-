// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int dp[10005];

    int solve(int n, int x, int y, int z)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans1, ans2, ans3;
        ans1 = ans2 = ans3 = INT_MIN;
        if (n >= x)
            ans1 = 1 + solve(n - x, x, y, z);
        if (n >= y)
            ans2 = 1 + solve(n - y, x, y, z);
        if (n >= z)
            ans3 = 1 + solve(n - z, x, y, z);

        return dp[n] = max(ans1, max(ans2, ans3));
    }

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp, -1, sizeof(dp));
        int ans = solve(n, x, y, z);
        if (ans < 0)
            return 0;
        else
            return ans;
    }
};
// SOLN 2 ADITYA VERMA RECURSION+DP
int solve(vector<int> nums, int n, int length, vector<vector<int>> &dp)
{
    if (length == 0)
        return 0;

    if (n == 0)
        return INT_MIN / 2;

    if (dp[n - 1][length] != -1)
        return dp[n - 1][length];

    if (nums[n - 1] <= length)
        return dp[n - 1][length] = max(1 + solve(nums, n, length - nums[n - 1], dp), solve(nums, n - 1, length, dp));

    return dp[n - 1][length] = solve(nums, n - 1, length, dp);
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> nums{x, y, z};
    vector<vector<int>> dp(3, vector<int>(n + 1, -1));

    int ans = solve(nums, 3, n, dp);

    if (ans < 0)
        return 0;

    return ans;
}
class Solution
{
public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int length = n; // length of line segment
        int a[] = {x, y, z};
        int arrSize = 3;
        int dp[arrSize + 1][length + 1]; // t[n+1][sum+1]
        for (int i = 0; i < arrSize + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = INT_MIN + 1;
                if (j == 0)
                    dp[i][j] = 0;
                if (i == 1)
                {
                    if (j % a[0] == 0)
                    {
                        dp[i][j] = j / a[0];
                    }
                    else
                        dp[i][j] = INT_MIN + 1;
                }
            }
        }
        for (int i = 1; i < arrSize + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (j - a[i - 1] >= 0)
                    dp[i][j] = max(dp[i - 1][j], 1 + dp[i][j - a[i - 1]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[arrSize][length] < 0 ? 0 : dp[arrSize][length];
    }
};
// { Driver Code Starts.
int main()
{

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
} // } Driver Code Ends