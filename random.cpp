#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void bfs(vector<vector<int>> input, int starting_index, int end, int m, int n)
{
    queue<int> q;
    q.push(starting_index);
    bool visited[m * n + 1];
    unordered_map<int, int> parent;
    parent[starting_index] = -1;
    for (int i = 0; i < m * n + 1; i++)
    {
        visited[i] = false;
    }
    visited[starting_index] = true;
    while (!q.empty())
    {
        int current_element = q.front();
        q.pop();
        if (current_element == end)
        {
            vector<int> output;
            output.push_back(current_element);
            while (current_element != starting_index)
            {
                output.push_back(parent[current_element]);
                current_element = parent[current_element];
            }
            for (int i = output.size() - 1; i >= 0; i--)
            {
                cout << output[i] << " ";
            }
            cout << endl;
            return;
        }
        if (input[current_element][1] == 1 && current_element - n > 0 && current_element <= m * n && visited[current_element - n] == false)
        {
            q.push(current_element - n);
            visited[current_element - n] = true;
            parent[current_element - n] = current_element;
        }
        if (input[current_element][2] == 1 && current_element - n + 1 > 0 && current_element <= m * n && visited[current_element - n + 1] == false)
        {
            q.push(current_element - n + 1);
            visited[current_element - n + 1] = true;
            parent[current_element - n + 1] = current_element;
        }
        if (input[current_element][3] == 1 && current_element + 1 > 0 && current_element <= m * n && visited[current_element + 1] == false)
        {
            q.push(current_element + 1);
            visited[current_element + 1] = true;
            parent[current_element + 1] = current_element;
        }
        if (input[current_element][4] == 1 && current_element + n + 1 > 0 && current_element <= m * n && visited[current_element + n + 1] == false)
        {
            q.push(current_element + n + 1);
            visited[current_element + n + 1] = true;
            parent[current_element + n + 1] = current_element;
        }
        if (input[current_element][5] == 1 && current_element + n > 0 && current_element <= m * n && visited[current_element + n] == false)
        {
            q.push(current_element + n);
            visited[current_element + n] = true;
            parent[current_element + n] = current_element;
        }
        if (input[current_element][6] == 1 && current_element + n - 1 > 0 && current_element <= m * n && visited[current_element + n - 1] == false)
        {
            q.push(current_element + n - 1);
            visited[current_element + n - 1] = true;
            parent[current_element + n - 1] = current_element;
        }
        if (input[current_element][7] == 1 && current_element - 1 > 0 && current_element <= m * n && visited[current_element - 1] == false)
        {
            q.push(current_element - 1);
            visited[current_element - 1] = true;
            parent[current_element - 1] = current_element;
        }
        if (input[current_element][8] == 1 && current_element - n - 1 > 0 && current_element <= m * n && visited[current_element - n - 1] == false)
        {
            q.push(current_element - n - 1);
            visited[current_element - n - 1] = true;
            parent[current_element - n - 1] = current_element;
        }

        // 		for(int i = 0; i < current_element.size(); i++){
        // 		    if(i == current_element){
        // 		    continue;
        // 		    }
        //     		if(visited[i]){
        //     		    continue;
        //     		}
        // 		if(input[current_element][i] == 1){
        // 		    q.push(i);
        // 		    parent[i] = current_element;
        //             visited[i] = true;
        // 		}
        // 		}
    }
}
int main()
{
    // your code goes here
    int m = 0, n = 0, s = 0;
    cin >> m;
    cin >> n;
    cin >> s;
    vector<vector<int>> input(m * n + 1, vector<int>(9));
    for (int i = 1; i < m * n + 1; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> input[i][j];
        }
    }
    bfs(input, s, 1, m, n);
    bfs(input, s, n, m, n);
    bfs(input, s, 1 + n * (m - 1), m, n);
    bfs(input, s, m * n, m, n);
}