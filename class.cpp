#include <bits/stdc++.h>
#include <vector>
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> a;

        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {

                if (nums[j] * a == target)
                {
                    a.push_back(i);
                    a.push_back(j);
                    break;
                }
            }
        }
        return a;
    }
};