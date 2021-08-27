// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    string solve(int arr[], int n)
    {
        // code here
        string ans1, ans2;
        ans1 = ans2 = "";
        sort(arr, arr + n);
        for (int i = 0; i < n; i += 2)
        {
            if (i & 2 == 0)
                ans1 = ans1 + to_string(arr[i]);
            else
                ans2 = ans2 + to_string(arr[i + 1]);
        }
        ans1 = to_string(stoi(ans1) + stoi(ans2));

        return (ans1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends