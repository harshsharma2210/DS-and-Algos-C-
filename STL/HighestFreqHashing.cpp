// Problem Name: Highest frequency( Hashing )
// Problem Difficulty: None
// Problem Constraints: 1 <= N <= 10^7
// Problem Description:
// Given an array find the number which comes with maximum frequency. It must work in
// O(n) time complexity.
// Input Format: Enter the size of the array N and add N more numbers and store in an array
// Sample Input: 5
// 1 2 2 2 3
// Output Format: Display the number with the maximum frequency.
// Sample Output: 2
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    int maxFreq = 0;
    int ans = 0;
    for (auto it : m)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            ans = it.first;
        }
    }
    cout << ans;
}