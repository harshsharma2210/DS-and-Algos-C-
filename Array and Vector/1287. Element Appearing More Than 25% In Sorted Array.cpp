// Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

// Example 1:

// Input: arr = [1,2,2,6,6,6,6,7,10]
// Output: 6
// Example 2:

// Input: arr = [1,1]
// Output: 1

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 105
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {

        int size = arr.size() / 4;
        for (int x : arr)
        {
            auto p = lower_bound(arr.begin(), arr.end(), x);
            auto q = upper_bound(arr.begin(), arr.end(), x);
            int num = distance(p, q);
            if (num > size)
            {
                return x;
            }
        }
        return -1;
    }
};
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size(), t = n / 4;
        for (int i = 0; i < n - t; i++)
        {
            if (arr[i] == arr[t + i])
                return arr[i];
        }
        return -1;
    }
};