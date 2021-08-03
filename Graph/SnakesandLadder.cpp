// 909. Snakes and Ladders
// Medium

// 86

// 4

// Add to List

// Share
// You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

// You start on square 1 of the board. In each move, starting from square curr, do the following:

// Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
// This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
// If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
// The game ends when you reach the square n2.
// A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

// Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

// For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
// Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

// Example 1:

// Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
// Output: 4
// Explanation:
// In the beginning, you start at square 1 (at row 5, column 0).
// You decide to move to square 2 and must take the ladder to square 15.
// You then decide to move to square 17 and must take the snake to square 13.
// You then decide to move to square 14 and must take the ladder to square 35.
// You then decide to move to square 36, ending the game.
// This is the lowest possible number of moves to reach the last square, so return 4.
// Example 2:

// Input: board = [[-1,-1],[-1,3]]
// Output: 1

// Constraints:

// n == board.length == board[i].length
// 2 <= n <= 20
// grid[i][j] is either -1 or in the range [1, n2].
// The squares labeled 1 and n2 do not have any ladders or snakes.

class Solution
{
public:
    static vector<int> findCoordinate(int x, int n)
    {
        int r = n - (x - 1) / n - 1;
        int c = (x - 1) % n;
        if (r % 2 == n % 2)
            return {r, n - c - 1};
        return {r, c};
    }
    int bfs(vector<vector<int>> &board, vector<vector<int>> &vis)
    {
        queue<pair<int, int>> q;
        int size = board.size();
        q.push({1, 0});
        vis[size - 1][0] = 1;
        int c = 0;
        while (!q.empty())
        {
            int curr = q.front().first;
            int step = q.front().second;
            q.pop();
            cout << curr << " " << step << endl;
            if (curr == size * size)
                return step;
            for (int i = 1; i <= 6; i++)
            {
                int currp = curr + i;
                if (currp > size * size)
                    break;
                int x = size - (currp - 1) / size - 1; // getting row of board matrix
                int y = (currp - 1) % size;            // getting column of board matrix
                if (x % 2 == size % 2)                 // this step is imp because the value after n will come just above n like 7 will
                    y = size - y - 1;                  // come just above 6 and not above 1  , if we are given in other format we can skip this
                if (vis[x][y] == 0)
                {
                    vis[x][y] = 1;
                    if (board[x][y] != -1)
                        q.push({board[x][y], step + 1});
                    else
                        q.push({currp, step + 1});
                }
            }
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int size = board.size();
        vector<vector<int>> vis(size, vector<int>(size, 0));

        int c = bfs(board, vis);
        return c;
    }
};