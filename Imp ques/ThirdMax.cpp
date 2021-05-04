// Third Maximum Number
// Easy

// 995

// 1717

// Add to List

// Share
// Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.

// Example 1:

// Input: nums = [3,2,1]
// Output: 1
// Explanation: The third maximum is 1.
// Example 2:

// Input: nums = [1,2]
// Output: 2
// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:

// Input: nums = [2,2,3,1]
// Output: 1
// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

// Follow up: Can you find an O(n) solution?

int thirdMax(vector<int> &nums)
{
    long long a, b, c;
    a = b = c = LLONG_MIN;
    for (auto num : nums)
    {
        if (num <= c || num == b || num == a)
            continue;
        c = num;
        if (c > b)
            swap(b, c);
        if (b > a)
            swap(a, b);
    }
    return c == LLONG_MIN ? a : c;
}
int thirdMax(vector<int> &nums)
{
    set<int> top3;
    for (int num : nums)
    {
        top3.insert(num);
        if (top3.size() > 3)
            top3.erase(top3.begin());
    }
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}