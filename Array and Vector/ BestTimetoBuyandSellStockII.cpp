// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e., max profit = 0.

// The profit is the sum of sub-profits. Each sub-profit is the difference between selling at day j, and buying at day i (with j > i). The range [i, j] should be chosen so that the sub-profit is maximum:

// sub-profit = prices[j] - prices[i]

// We should choose j that prices[j] is as big as possible, and choose i that prices[i] is as small as possible (of course in their local range).

// Let's say, we have a range [3, 2, 5], we will choose (2,5) instead of (3,5), because 2<3.
// Now, if we add 8 into this range: [3, 2, 5, 8], we will choose (2, 8) instead of (2,5) because 8>5.

// From this observation, from day X, the buying day will be the last continuous day that the price is smallest. Then, the selling day will be the last continuous day that the price is biggest.

// Take another range [3, 2, 5, 8, 1, 9], though 1 is the smallest, but 2 is chosen, because 2 is the smallest in a consecutive decreasing prices starting from 3.
// Similarly, 9 is the biggest, but 8 is chosen, because 8 is the biggest in a consecutive increasing prices starting from 2 (the buying price).
// Actually, the range [3, 2, 5, 8, 1, 9] will be splitted into 2 sub-ranges [3, 2, 5, 8] and [1, 9].

// We come up with the following code:

// public int maxProfit(int[] prices) {
//         int i = 0, buy, sell, profit = 0, N = prices.length - 1;
//         while (i < N) {
//             while (i < N && prices[i + 1] <= prices[i]) i++;
//             buy = prices[i];

//             while (i < N && prices[i + 1] > prices[i]) i++;
//             sell = prices[i];

//             profit += sell - buy;
//         }
//         return profit;
// }

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, buy = 0, sell = 0, i = 0;
        while (i < prices.size() - 1)
        {
            while (i < prices.size() - 1 && prices[i + 1] <= prices[i])
                i++;
            buy = prices[i];
            while (i < prices.size() - 1 && prices[i + 1] > prices[i])
                i++;
            sell = prices[i];
            profit += sell - buy;
        }
        return profit;
    }
};