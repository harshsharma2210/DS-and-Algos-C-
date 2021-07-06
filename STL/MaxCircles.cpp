// Problem Name: Maximum Circles
// Problem Difficulty: None
// Problem Constraints: 1<=n<=10^5
// |c|<=10^9
// 1<=r<=10^9

// Problem Description:
// There are *n* circles arranged on x-y plane. All of them have their centers on x-axis. You have to remove some of them, such that no two circles are overlapping after that. Find the  minimum number of circles that need to be removed.
// Input Format: First line contains a single integer, *n*, denoting the number of circles. Next line contains two integers, *c* and *r* each, denoting the circle with radius *r* and center, (*c*,0).
// Sample Input: 4
// 1 1
// 2 1
// 3 1
// 4 1
// Output Format: Print a single integer denoting the answer.
// Sample Output: 2

#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int> a, const pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a - b, a + b));
    }
    sort(v.begin(), v.end(), compare);
    int count = 0;
    int end = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first < end)
        {
            end = v[i - 1].second;
            continue;
        }
        count++;
    }
    cout << count;
}