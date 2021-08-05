// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    static int recur(int n, int r, int t[][801])
    {
        if (r == 0)
            return 1;
        if (t[n][r] != -1)
            return t[n][r];

        return t[n][r] = recur(n - 1, r - 1, t) + recur(n - 1, r, t);
    }
    int nCr(int n, int r)
    {
        // code here
        int t[n + 1][r + 1]={{0}};
        memset(t, -1, sizeof(t));
        return recur(n, r, t);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends