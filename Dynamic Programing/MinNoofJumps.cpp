// Minimum number of jumps
// Medium Accuracy: 32.96% Submissions: 100k+ Points: 4
// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.

// Example 1:

// Input:
// N = 11
// arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
// Output: 3
// Explanation:
// First jump from 1st element to 2nd
// element with value 3. Now, from here
// we jump to 5th element with value 9,
// and from here we will jump to last.
// Example 2:

// Input :
// N = 6
// arr = {1, 4, 3, 2, 6, 7}
// Output: 2
// Explanation:
// First we jump from the 1st to 2nd element
// and then jump to the last element.

// Your task:
// You don't need to read input or print anything. Your task is to complete function minJumps() which takes the array arr and it's size N as input parameters and returns the minimum number of jumps. If not possible returns -1.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ N ≤ 107
// 0 ≤ arri ≤ 107

// Time Complexity: O(n)
// Auxiliary Memory: O(1)
// Code similar to a top submission on LeetCode.
// Explanation: We traverse the array till the second last element, and maintain three things, all initialized to 0:
// 1. The number of minimum jumps we need

// 2. The farthest we can jump in the current window we're moving through
// 3. The end of the current window, currEnd

// We update the farthest as max. of the current farthest we have, and i + arr[i].
// We walk through the entire current window, collecting the best possible farthest, and when we reach the end of the current window, it's time to switch to another window. Switching to another window is analogous to incrementing a jump, and now we set the current end to the farthest we could find, meaning we make the jump to that point in the array which carried us the farthest. We can only come to know this after traversing the whole window, hence we keep collecting possible solutions.
// Finally, once we're at the last element, we've reached our destination (and don't need to loop through it), so we return the number of jumps we've collected so far.

// Optimizations:
// 1. If the index i is the farthest we can go, then we've reached a 0 and all previous jumps lead to this element at best, hence we can't proceed further and return a -1 there itself.
// 2. If we've encountered an array element which can take us to the last element (or beyond), we make a switch to that window, or alternatively count 1 jump for the switch, and add it to the number of jumps we need so far, hence returning jumps+1.

// Extra:
// If initially i >= n-1, the loop won't execute. What does this mean?
// Initially, i = 0, if 0 >= n - 1, it implies n <= 1, that means ither we have an empty array (n=0), or an array with a single element (n=1). Either way, it's going to take zero jumps to reach the end, so our initialization holds here and the code returns 0.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        int jumps = 0, farthest = 0, currEnd = 0;
        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + arr[i]);
            if (farthest >= n - 1)
                return 1 + jumps;

            if (i == farthest)
                return -1;

            if (i == currEnd)
            {
                jumps++;
                currEnd = farthest;
            }
        }
        return jumps;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends