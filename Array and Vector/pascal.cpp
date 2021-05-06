#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++)
        {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> v = {1};
        vector<vector<int>> v2(rowIndex);
        int i;
        for (i = 0; i <= rowIndex; i++)
        {
            v2[i].resize(i + 1);
            v2[i][0] = v2[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                v2[i][j] = v2[i - 1][j - 1] + v2[i - 1][j];
            }
        }
        for (auto x : v2[i])
        {
            cout << x;
        }
        return v;
    }
};