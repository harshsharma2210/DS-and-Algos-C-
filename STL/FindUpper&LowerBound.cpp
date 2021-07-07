// Problem Name: Find Upper and Lower bound
// Problem Difficulty: None
// Problem Constraints: 1 <= N <= 10^5 <br>
// 1 <= Q <= 100

// Problem Description:
// Find position of the last and first occurrence of a given number in a sorted array. If number does not exist then print lower and upper bound as -1.
// Input Format: First line contains an integer n denoting the size of the array. <br>
// Second line contains n space separated integers denoting array elements. <br>
// Third line contains single integer Q denoting the no of queries. <br>
// Q lines follow , each containing a single integer x that is to be searched in the array.
// Sample Input: 5
// 1 2 3 3 4
// 3
// 2
// 3
// 10
// Output Format: For each query , print the lowerbound and the upperbound for the number x in a new line each.
// Sample Output: 1 1
// 2 3
// -1 -1

#include <bits/stdc++.h>
using namespace std;

// int upperBound(vector<int> v, int no, int n)
// {
// }
// int lowerBound(vector<int> v, int no, int n)
// {
// }

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int no;
        cin >> no;
        // int upper = upperBound(v, no, n);
        // int lower = lowerBound(v, no, n);
        cout << *lower_bound(v.begin(), v.end(), no) << " ";
        cout << *upper_bound(v.begin(), v.end(), no) << endl;
    }
}