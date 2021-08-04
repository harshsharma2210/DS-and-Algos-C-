// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int dp[1001][1001] = {{0}};

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack1(int W, int wt[], int val[], int n)
    {
        if (W == 0 || n == 0)
            return 0; //bsse condition

        if (dp[n][W] != -1)
            return dp[n][W]; //if value is not -1 then it already has a value

        if (wt[n - 1] > W)
            return dp[n][W] = knapSack1(W, wt, val, n - 1); //if wt is greater than capacity

        return dp[n][W] = max(val[n - 1] + knapSack1(W - wt[n - 1], wt, val, n - 1), knapSack1(W, wt, val, n - 1));
        //taking max of items with high value
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        memset(dp, -1, sizeof(dp)); ///initializing matrix with -1
        return knapSack1(W, wt, val, n);
    }
};

class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        int t[n + 1][W + 1];
        for (int i = 0; i < (n + 1); i++)
        {
            for (int j = 0; j < (W + 1); j++)
            {
                if (i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < (n + 1); i++)
        {
            for (int j = 1; j < (W + 1); j++)
            {
                if (wt[i - 1] <= j)
                {
                    t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][W];
    }
};
// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];
        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends