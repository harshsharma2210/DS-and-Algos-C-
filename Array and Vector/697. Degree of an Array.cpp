// Easy

// 1340

// 956

// Add to List

// Share
// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

// Example 1:

// Input: nums = [1,2,2,3,1]
// Output: 2
// Explanation:
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
// Example 2:

// Input: nums = [1,2,2,3,1,4,2]
// Output: 6
// Explanation:
// The degree is 3 because the element 2 is repeated 3 times.
// So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

// Constraints:

// nums.length will be between 1 and 50,000.
// nums[i] will be an integer between 0 and 49,999.
// Accepted
// 110,226
// Submissions
// 201,766

int findShortestSubArray(vector<int> &nums)
{
    int number;
    unordered_map<int, pair<int, vector<int>>> hashmap;
    for (int i = 0; i < nums.size(); i++)
    {
        number = nums[i];
        hashmap[number].first++;
        hashmap[number].second.push_back(i);
    }
    int degree = -1;
    for (auto it : hashmap)
    {
        if (it.second.first > degree)
        {
            degree = it.second.first;
        }
    }

    int ans = nums.size();

    for (auto it : hashmap)
    {
        if (it.second.first == degree)
        {
            int minimum = *min_element(it.second.second.begin(), it.second.second.end());
            int maximum = *max_element(it.second.second.begin(), it.second.second.end());

            if (maximum - minimum < ans)
            {
                ans = maximum - minimum;
            }
        }
    }

    return ans + 1;
}