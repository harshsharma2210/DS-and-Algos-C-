// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        int len = str.length();
        string strr = str;
        int t[len + 1][len + 1];
        memset(t, -1, sizeof(t));
        for (int i = 0; i < len + 1; i++)
        {
            for (int j = 0; j < len + 1; j++)
            {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }
        reverse(strr, strr + len);
        for (int i = 1; i < len + 1; i++)
        {
            for (int j = 1; j < len + 1; j++)
            {
                if (str[i - 1] == str[j - 1] && i != j)
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
        return t[len][len];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends