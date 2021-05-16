// Alice and Bob have candy bars of different sizes: aliceSizes[i] is the size of the i-th bar of candy that Alice has, and bobSizes[j] is the size of the j-th bar of candy that Bob has.

// Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

// Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

// If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

// Example 1:

// Input: aliceSizes = [1,1], bobSizes = [2,2]
// Output: [1,2]
// Example 2:

// Input: aliceSizes = [1,2], bobSizes = [2,3]
// Output: [1,2]
// Example 3:

// Input: aliceSizes = [2], bobSizes = [1,3]
// Output: [2,3]
// Example 4:

// Input: aliceSizes = [1,2,5], bobSizes = [2,4]
// Output: [5,4]

// Note:

// 1 <= aliceSizes.length <= 10000
// 1 <= bobSizes.length <= 10000
// 1 <= aliceSizes[i] <= 100000
// 1 <= bobSizes[i] <= 100000
// It is guaranteed that Alice and Bob have different total amounts of candy.
// It is guaranteed there exists an answer.

class Solution
{
    /* We need to find a swap such that:
     * sum_of_candy_a - A[i] + B[j] == sum_of_candy_b - B[j] + A[i]
     * sum_of_candy_a - sum_of_candy_b == 2A[i] - 2B[j]
     * diff/2 = A[i] - B[j]
     *
     * for each A find in B if there is a  A[i] - diff/2
     */
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int diff = (accumulate(A.begin(), A.end(), 0) -
                    accumulate(B.begin(), B.end(), 0)) /
                   2;
        for (auto i : A)
            if (find(B.begin(), B.end(), i - diff) != B.end())
                return {i, i - diff};
        return {};
    }
};
