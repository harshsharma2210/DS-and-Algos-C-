#include <bits/stdc++.h>
#include <queue>;

using namespace std;
void display(vector<int> s)
{
    reverse(s.begin(), s.end());
    for (auto i : s)
    {
        cout << i << " ";
    }
}

void bfs(vector<vector<int>> a, int s, int rows, int n, int dest)
{
    int visited[rows + 1] = {0};
    int ways[9] = {0, -n, -n + 1, 1, n + 1, n, n - 1, -1, -n - 1};
    int S[rows + 1] = {INT_MAX};
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    int curr;
    vector<int> f;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr == dest)
        {
            while (curr != s)
            {
                f.push_back(curr);
                curr = S[curr];
            }
            cout << s << " ";
            display(f);
        }

        for (int i = 1; i < 9; i++)
        {
            // if (curr == 20)
            // {
            //     cout << a[curr - 1][i] << " ";
            // }
            if (curr <= rows && a[curr - 1][i] && (curr + ways[i]) > 0 && (curr + ways[i]) <= rows)
            {
                if (visited[curr + ways[i]] == 0)
                {
                    q.push(curr + ways[i]);
                    visited[curr + ways[i]] = 1;
                    S[curr + ways[i]] = curr;
                }
            }
        }
    }
    cout << endl;
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
    bfs(a, s, rows, n, 1);
    bfs(a, s, rows, n, n);
    bfs(a, s, rows, n, rows - n + 1);
    bfs(a, s, rows, n, rows);
    return 0;
}