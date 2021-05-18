// The array-form of an integer num is an array representing its digits in left to right order.

// For example, for num = 1321, the array form is [1,3,2,1].
// Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

// Example 1:

// Input: num = [1,2,0,0], k = 34
// Output: [1,2,3,4]
// Explanation: 1200 + 34 = 1234
// Example 2:

// Input: num = [2,7,4], k = 181
// Output: [4,5,5]
// Explanation: 274 + 181 = 455
// Example 3:

// Input: num = [2,1,5], k = 806
// Output: [1,0,2,1]
// Explanation: 215 + 806 = 1021
// Example 4:

// Input: num = [9,9,9,9,9,9,9,9,9,9], k = 1
// Output: [1,0,0,0,0,0,0,0,0,0,0]
// Explanation: 9999999999 + 1 = 10000000000

/* An important observation ---
1) num%10 gives us the last digit of a number
2) num = num/10 cuts off the last digit of the number 
3) numVector.back() gives us the last digit of the number in vector form
4) numVector.pop_back() cuts off the last digit of the number in vector form
5) The extra space required can be reduced by overwriting the first vector. 
*/

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &a, int k);
};

/* Returns the sum of 2 numbers in vector form */
vector<int> Solution ::addToArrayForm(vector<int> &a, int k)
{
    // Get the length of the first number
    int n = a.size();

    // Vector to store the answer
    vector<int> answer;

    /* Start adding both the numbers from the end */

    int carry = 0;
    // As long as one of the number exists, keep adding them
    while (!a.empty() || k != 0)
    {
        // Get the last digits of both the numbers. If a vector has finished off, the last digit is zero
        int lastDigit_1 = a.empty() ? 0 : a.back();
        int lastDigit_2 = k % 10;

        // Sum up the digits and add the carry
        int sum = lastDigit_1 + lastDigit_2 + carry;
        answer.push_back(sum % 10);
        carry = sum / 10;

        // Remove the last digits of both the numbers
        if (!a.empty())
            a.pop_back();
        k = k / 10;
    }

    // If the carry is remaining, add it
    if (carry != 0)
        answer.push_back(carry);

    // Reverse the answer, since we were summing up from the end
    reverse(answer.begin(), answer.end());

    // Return the answer in vector format
    return answer;
}