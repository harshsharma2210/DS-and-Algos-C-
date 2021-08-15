class Solution
{
public:
    long long int dp[1001];

    long long int solve(int h)
    {
        if (h == 0 || h == 1)
            return 1;

        if (dp[h] != -1)
            return dp[h];

        dp[h] = (solve(h - 1) * (2 * solve(h - 2) + solve(h - 1)) % 1000000007) % 1000000007;
        return dp[h] % 1000000007;
    }

    long long int countBT(int h)
    {
        memset(dp, -1, sizeof(dp));
        return solve(h);
    }
};