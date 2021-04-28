class Solution
{
public:
    bool isprime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int countPrimes(int n)
    {
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (isprime(i))
                ++cnt;
        }
        return cnt;
    }
};

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        vector<bool> passed(n, false);
        int sum = 1;
        int upper = sqrt(n);
        for (int i = 3; i < n; i += 2)
        {
            if (!passed[i])
            {
                sum++;
                //avoid overflow
                if (i > upper)
                    continue;
                for (int j = i * i; j < n; j += i)
                {
                    passed[j] = true;
                }
            }
        }
        return sum;
    }
};