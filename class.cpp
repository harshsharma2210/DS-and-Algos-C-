#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        cout << k << endl;
        for (int i = 0; i < s.length(); i = i)
        {
            for (int j = 0; j < k; j++)
            {
                char ch = s[i];
                s = ch + s;
                i++;
                cout << i;
            }
        }
        return s;
    }
};