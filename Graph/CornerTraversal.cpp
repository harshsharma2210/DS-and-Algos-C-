#include <bits/stdc++.h>
#include <queue>;

using namespace std;

queue<int> q;
void bfs1(vector<vector<int>> a, int s, int rows)
{
    cout << s << " ";
    int i = s, u;
    int visited[40] = {0};
    visited[i] = 1;
    q.push(i);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        if (a[i][1] == 1 && visited[1] == 0)
        {
        }
    }
}
int main()
{
    // your code goes here
    // m*n and starting pixel s
    int m, n, s;
    cin >> m >> n >> s;
    int rows = m * n;
    vector<vector<int>> a(rows, vector<int>(9, 0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
        }
    }
    bfs1(a, s, rows);

    return 0;
}
// 5 8 20
// 1 0 0 1 1 1 0 0 0
// 2 0 0 1 0 1 1 1 0
// 3 0 0 1 1 0 1 1 0
// 4 0 0 0 0 1 1 1 0
// 5 0 0 1 1 1 0 0 0
// 6 0 0 1 1 1 1 1 0
// 7 0 0 1 1 0 1 1 0
// 8 0 0 0 0 1 0 1 0
// 9 1 1 1 0 1 0 0 0
// 10 1 1 0 0 0 1 1 1
// 11 0 1 1 1 0 0 0 0
// 12 1 0 0 0 1 1 1 1
// 13 1 1 0 0 1 0 0 0
// 14 1 1 1 1 0 0 0 1
// 15 0 0 0 0 1 1 1 1
// 16 1 0 0 0 1 0 0 1
// 17 1 1 0 0 1 0 0 0
// 18 0 0 1 1 1 0 0 0
// 19 0 1 1 1 0 1 1 0
// 20 1 0 0 0 1 0 1 1
// 21 1 0 0 0 1 0 0 0
// 22 0 1 1 0 1 0 0 0
// 23 1 0 0 0 0 1 1 1
// 24 1 0 0 0 0 0 0 0
// 25 1 0 0 1 1 0 0 0
// 26 1 1 1 1 0 0 0 0
// 27 0 0 0 0 1 0 1 1
// 28 1 0 0 1 1 0 0 1
// 29 1 0 0 0 1 1 0 0
// 30 1 1 0 1 1 0 0 0
// 31 0 0 1 1 1 1 0 0
// 32 0 0 0 0 1 1 1 0
// 33 1 0 1 0 0 0 0 0
// 34 0 0 0 0 0 0 1 1
// 35 1 0 0 0 0 0 0 1
// 36 1 1 1 0 0 0 0 0
// 37 1 0 0 0 0 0 1 1
// 38 1 1 1 0 0 0 0 0
// 39 1 1 1 0 0 0 1 1
// 40 1 0 0 0 0 0 1 1