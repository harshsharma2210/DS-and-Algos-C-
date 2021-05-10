// Just see number of times every position occurs in all the odd length subarray.
// Multiply the contribution of position with element at that position.

// How to calculate contribution?
// Every element will contribute size of array to its right (n-i) * size of array to its left(i+1)
// Since here we only consider odd length divide it by two (ceil divison)

// Example
// Given array: arr = [1, 2, 3, 4, 5] (n = 5) and formula (i + 1) * (n - i)
// i = 0, contribution = 1 * 5 = 5
// i = 1, contribution = 2 * 4 = 8
// i = 2, contribution = 3 * 3 = 9
// i = 3, contribution = 4 * 2 = 8
// i = 4, contribution = 5 * 1 = 5

// For detailed explanation on example refer to comment below
// Please upvote if you like the approach :)

// It took me a while to figure out what it means for Every element will contribute size of array to its right (n-i) * size of array to its left(i+1)
// For people who are still confused, please refer to the following explanation:

// Given array: arr = [1, 2, 3, 4, 5] (n = 5) and formula (i + 1) * (n - i)
// i = 0, contribution = 1 * 5 = 5
// i = 1, contribution = 2 * 4 = 8
// i = 2, contribution = 3 * 3 = 9
// i = 3, contribution = 4 * 2 = 8
// i = 4, contribution = 5 * 1 = 5

// How to understand the above?
// i + 1 means how many start index there are to the left of arr[i] (included), n - i means how many end index there are to the right of arr[i] (included)

// Example:
// i = 2 -> i + 1 = 3, n - i = 3
// there are 3 start index to the left of arr[2] (included), they are: i = 0, 1, 2
// there are 3 end index to the right of arr[2] (included), they are: i = 2, 3, 4
// so there are 3 * 3 = 9 in total subarrays that contains arr[2]
// if we choose start = 0, end = 2, we get [1, 2, 3]
// if we choose start = 2, end = 2, we get [3]
// if we choose start = 2, end = 4, we get [3, 4, 5]

// i = 4 -> i + 1 = 5, n - i = 1
// there are 5 start index to the left of arr[4] (included), they are: i = 0, 1, 2, 3, 4
// there are 1 end index to the right of arr[4] (included), they are: i = 4
// so there are 5 * 1 = 5 in total subarrays that contains arr[4]

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++)
        {
            int end = i + 1;
            int start = n - i;
            int contribution = start * end;
            int odd = contribution / 2;
            if (contribution % 2 != 0)
                odd++;
            sum += arr[i] * odd;
        }
        return sum;
    }
};