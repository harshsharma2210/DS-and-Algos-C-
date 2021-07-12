#include <bits/stdc++.h>
using namespace std;

int main()
{

    // your code here
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        m--;
        n--;
        vector<int> x, y;
        for (int i = 0; i < m; i++)
        {
            int a;
            cin >> a;
            x.push_back(a);
        }
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            y.push_back(a);
        }
        int cost = 0;
        sort(x.begin(), x.begin() + m, greater<int>());
        sort(y.begin(), y.begin() + n, greater<int>());
        int hz = 1, vr = 1;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (x[i] > y[i])
            {
                cost += x[i] * vr;
                hz++;
                i++;
            }
            else
            {
                cost += y[j] * hz;
                vr++;
                j++;
            }
        }
        while (i < m)
        {
            cost += x[i] * vr;
            i++;
        }
        while (j < n)
        {
            cost += y[j] * hz;
            j++;
        }
        cout << cost << endl;
    }

    return 0;
}