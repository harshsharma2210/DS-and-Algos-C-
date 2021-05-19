// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].

// Constraints:

// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

// We start at either step 0 or step 1. The target is to reach either last or second last step, whichever is minimum.

// Step 1 - Identify a recurrence relation between subproblems. In this problem,
// Recurrence Relation:
// mincost(i) = cost[i]+min(mincost(i-1), mincost(i-2))
// Base cases:
// mincost(0) = cost[0]
// mincost(1) = cost[1]

// Step 2 - Covert the recurrence relation to recursion

// Recursive Top Down - O(2^n) Time Limit Exceeded
public
int minCostClimbingStairs(int[] cost)
{
    int n = cost.length;
    return Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
}
private
int minCost(int[] cost, int n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return cost[n];
    return cost[n] + Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
}
// Step 3 - Optimization 1 - Top Down DP - Add memoization to recursion - From exponential to linear.

// Top Down Memoization - O(n) 1ms
int[] dp;
public
int minCostClimbingStairs(int[] cost)
{
    int n = cost.length;
    dp = new int[n];
    return Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
}
private
int minCost(int[] cost, int n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return cost[n];
    if (dp[n] != 0)
        return dp[n];
    dp[n] = cost[n] + Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
    return dp[n];
}
// Step 4 - Optimization 2 -Bottom Up DP - Convert recursion to iteration - Getting rid of recursive stack

// Bottom up tabulation - O(n) 1ms
public
int minCostClimbingStairs(int[] cost)
{
    int n = cost.length;
    int[] dp = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (i < 2)
            dp[i] = cost[i];
        else
            dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
    }
    return Math.min(dp[n - 1], dp[n - 2]);
}
Step 5 - Optimization 3 - Fine Tuning - Reduce O(n) space to O(1).

                                        // Bottom up computation - O(n) time, O(1) space
                                        public int minCostClimbingStairs(int[] cost)
{
    int n = cost.length;
    int first = cost[0];
    int second = cost[1];
    if (n <= 2)
        return Math.min(first, second);
    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + Math.min(first, second);
        first = second;
        second = curr;
    }
    return Math.min(first, second);
}

// C++

// While trying to solve this problem like this. If I'm at my current location what was the minimum cost
// I paid to reach this location.
// Let  cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
// at the first location the minimum cost I have to pay is 1.
// cost = [1,]
// for the second stair the minum cost I have to pay is that stair itself because u can skep a stair.
// cost = [1,100]
// for the third stair i could have come from the first stair or the second stair.Since the q states minmum cost
// I am going to pick the 1st stair + cost of the current stair.
// cost = [1,100,2]
// cost = [1,100,2,3] <--picked stair 3.
// cost = [1,100,2,3,3] <---picked stair 3
// cost = [1,100,2,3,3,103,4,5,104,6].
// Thus the final answer is dp[n]. Not necessarily!
// lets take this example:
// cost = [10,15,20]
// cost = [10,15,30] but i can reach my destination by skipping the 3 stair thus giving me a minimum cost of 15.
// thus you final answer must be min(dp[n],dp[n-1]).

int minCostClimbingStairs(vector<int> &cost)
{
    for (int i = 2; i < cost.size(); i++)
    {
        cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    return min(cost[cost.size() - 1], cost[cost.size() - 2]);
}