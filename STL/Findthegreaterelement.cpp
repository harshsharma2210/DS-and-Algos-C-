// Problem Name: Find the greater element
// Problem Difficulty: None
// Problem Constraints: 1 <= n <= 10^6 </br>
// -10^8 <= A<sub>i</sub> <= 10^8 , 0<= i< n
// Problem Description:
// We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element A<sub>i</sub> , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.
// Input Format: First line contains the length of the array n.
// Second line contains the n space separated integers.
// Sample Input: 3
// 1 2 3
// Output Format: Print n space separated integers each representing the next greater element.
// Sample Output: 2 3 -1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int> s;
    s.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push_back(s[i]);
            continue;
        }
        while (s.empty() == false && s.back() < v[i])
        {
            cout << v[i] << " ";
            s.pop_back();
        }
        s.push_back(v[i]);
    }
    while (s.empty() == false)
    {
        cout << -1 << endl;
        s.pop_back();
    }
}