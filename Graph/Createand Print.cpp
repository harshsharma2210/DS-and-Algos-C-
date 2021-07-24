#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main()
{

    int v, e;
    cin >> v >> e;
    int g[v + 1][v + 1];
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
            g[i][j] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }

    for (int i = 1; i <= v; i++)
    {
        cout << i << "--> ";
        for (int j = 1; j <= v; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//  stdin copy
// 6 5
// 1 2
// 1 5
// 2 3
// 3 4
// 3 6
//  stdout copy
// 1--> 0 1 0 0 1 0
// 2--> 1 0 1 0 0 0
// 3--> 0 1 0 1 0 1
// 4--> 0 0 1 0 0 0
// 5--> 1 0 0 0 0 0
// 6--> 0 0 1 0 0 0
#define int long long int

int32_t main()
{

    int v, e;
    cin >> v >> e;
    vector<int> g[v + 1];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= v; i++)
    {
        cout << i << "--> ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//  stdin copy
// 6 5
// 1 2
// 1 5
// 2 3
// 3 4
// 3 6
//  stdout copy
// 1--> 2 5
// 2--> 1 3
// 3--> 2 4 6
// 4--> 3
// 5--> 1
// 6--> 3