// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static struct compare
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > a.first;
        }
    } vector<int> sortByFreq(int arr[], int n)
    {
        // Your code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (auto i : mp)
        {
            pq.push({i.second, i.first});
        }
        vector<int> ans;
        for (auto i : pq)
        {
            for (int i = 0; i < pq.first; i++)
                ans.push_back(pq.second);
        }
        return ans;
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

        int a[n + 1];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(a, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends