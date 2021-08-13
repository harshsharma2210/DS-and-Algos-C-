// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends

class Solution
{
public:
    //Function to find a solved Sudoku.
    bool isValid(int x, int y, int grid[N][N], int val)
    {
        for (int i = 0; i < N; i++)
        {
            if (grid[x][i] == val)
                return false;
        }
        for (int i = 0; i < N; i++)
        {
            if (grid[i][y] == val)
                return false;
        }
        int smi = x / 3 * 3;
        int smy = y / 3 * 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                if (grid[smi + x][smi + j] == val)
                    return false;
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N], int i, int j)
    {
        // Your code here
        if (i == N)
        {
            printGrid(grid);
            return true;
            ;
        }
        int ni, nj;
        ni = nj = 0;
        if (j == N)
        {

            ni = i + 1;
            nj = 0;
        }
        else
        {
            ni = i + 1;
            nj = j + 1;
        }

        for (int po = 1; po <= 9; po++)
        {
            if (isValid(i, j, grid, po))
            {
                grid[i][j] = po;
                if (SolveSudoku(grid, ni, nj))
                    return true;
                grid[i][j] = 0;
            }
        }
        return false;
    }

    //Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        // Your code here
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
} // } Driver Code Ends