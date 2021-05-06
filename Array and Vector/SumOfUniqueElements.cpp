// You are given an integer array nums.The unique elements of an array are the elements that appear exactly once in the array.

//     Return the sum of all the unique elements of nums.

//     Example 1 :

//     Input : nums = [ 1, 2, 3, 2 ] Output : 4 Explanation : The unique elements are[1, 3],
//             and the sum is 4. Example 2 :

//     Input : nums = [ 1, 1, 1, 1, 1 ] Output : 0 Explanation : There are no unique elements,
//             and the sum is 0. Example 3 :

//     Input : nums = [ 1, 2, 3, 4, 5 ] Output : 15 Explanation : The unique elements are[1, 2, 3, 4, 5],
//             and the sum is 15.

//                 Constraints :

//                 1 <= nums.length <= 100 1 <= nums[i] <= 100
class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> a, b;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                a.push_back(nums[i]);
        }
        auto z = unique(a.begin(), a.end());
        a.resize(distance(a.begin(), z));
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(a.begin(), a.end(), nums[i]) != a.end())
            {
                continue;
            }
            b.push_back(nums[i]);
        }
        return accumulate(b.begin(), b.end(), 0);
    }
};