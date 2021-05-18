// Given an array of positive integers arr,  find a pattern of length m that is repeated k or more times.

// A pattern is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times consecutively without overlapping. A pattern is defined by its length and the number of repetitions.

// Return true if there exists a pattern of length m that is repeated k or more times, otherwise return false.

// Example 1:

// Input: arr = [1,2,4,4,4,4], m = 1, k = 3
// Output: true
// Explanation: The pattern (4) of length 1 is repeated 4 consecutive times. Notice that pattern can be repeated k or more times but not less.
// Example 2:

// Input: arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
// Output: true
// Explanation: The pattern (1,2) of length 2 is repeated 2 consecutive times. Another valid pattern (2,1) is also repeated 2 times.
// Example 3:

// Input: arr = [1,2,1,2,1,3], m = 2, k = 3
// Output: false
// Explanation: The pattern (1,2) is of length 2 but is repeated only 2 times. There is no pattern of length 2 that is repeated 3 or more times.
// Example 4:

// Input: arr = [1,2,3,1,2], m = 2, k = 2
// Output: false
// Explanation: Notice that the pattern (1,2) exists twice but not consecutively, so it doesn't count.
// Example 5:

// Input: arr = [2,2,2,2], m = 2, k = 3
// Output: false
// Explanation: The only pattern of length 2 is (2,2) however it's repeated only twice. Notice that we do not count overlapping repetitions.
class Solution
{
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {

        int cnt = 0;
        for (int i = 0; i + m < arr.size(); i++)
        {

            if (arr[i] != arr[i + m])
            {
                cnt = 0;
            }
            cnt += (arr[i] == arr[i + m]);
            if (cnt == (k - 1) * m)
                return true;
        }
        return false;
    }
};

// For each character in the string, check if the ith character and (i+m)th characters are matching.
// If they match, increase the count by 1. Otherwise, this is a nonmatch, so reset the count variable to 0.
// Because we need to find k repetitions of a pattern of length m, if there is any such pattern, the count value will be k*m at some point.
// The reason why it is shifted to (k-1) * m is that if there exist k occurrences of a pattern, you will be successfully making k-1 comparisons, which is between every adjacent occurrence of the pattern.

// For example, consider this:

// s = 123123123
// m = 3
// k = 3
// In this case you compare values at indices 0,1,2 with 3,4,5 (1 with 1, 2 with 2, 3 with 3)
// Subsequently, you compare value at indices 3,4,5 with 6,7,8
// In total, you count value reaches 6, which (k-1) * m