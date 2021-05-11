// Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

// Return any answer array that satisfies this condition.

// Example 1:

// Input: nums = [4,2,5,7]
// Output: [4,5,2,7]
// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
// Example 2:

// Input: nums = [2,3]
// Output: [2,3]

// Constraints:

// 2 <= nums.length <= 2 * 104
// nums.length is even.
// Half of the integers in nums are even.
// 0 <= nums[i] <= 1000

// Follow Up: Could you solve it in-place?
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        vector<int> a, b;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
                a.push_back(nums[i]);

            else
                b.push_back(nums[i]);
        }
        int as = 0, bs = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = a[as++];
            }
            else
                nums[i] = b[bs++];
        }
        return nums;
    }
};
// Use two pointers to search for missplaced odd and even elements, and swap them.
vector<int> sortArrayByParityII(vector<int> &A)
{
    for (int i = 0, j = 1; i < A.size(); i += 2, j += 2)
    {
        while (i < A.size() && A[i] % 2 == 0)
            i += 2;
        while (j < A.size() && A[j] % 2 == 1)
            j += 2;
        if (i < A.size())
            swap(A[i], A[j]);
    }
    return A;
}