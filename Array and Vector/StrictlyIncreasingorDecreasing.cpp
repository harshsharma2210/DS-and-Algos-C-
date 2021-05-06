/*
Check if Array forms an increasing-decreasing sequence or vice versa
Difficulty Level : Medium
Last Updated : 18 Aug, 2020
Given an array arr[] of N integers, the task is to find if the array can be divided into 2 sub-array such that the first sub-array is strictly increasing and the second sub-array is strictly decreasing or vice versa. If the given array can be divided then print “Yes” else print “No”.
Examples: 
 

Input: arr[] = {3, 1, -2, -2, -1, 3} 
Output: Yes 
Explanation: 
First sub-array {3, 1, -2} which is strictly decreasing and second sub-array is {-2, 1, 3} is strictly increasing.
Input: arr[] = {1, 1, 2, 3, 4, 5} 
Output: No 
Explanation: 
The entire array is increasing. 
 

 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Naive Approach: The naive idea is to divide the array into two subarrays at every possible index and explicitly check if the first subarray is strictly increasing and the second subarray is strictly decreasing or vice-versa. If we can break any subarray then print “Yes” else print “No”. 
Time Complexity: O(N2) 
Auxiliary Space: O(1)
Efficient Approach: To optimize the above approach, traverse the array and check for the strictly increasing sequence and then check for strictly decreasing subsequence or vice-versa. Below are the steps: 
 

If arr[1] > arr[0], then check for strictly increasing then strictly decreasing as: 
Check for every consecutive pair until at any index i arr[i + 1] is less than arr[i].
Now from index i + 1 check for every consecutive pair check if arr[i + 1] is less than arr[i] till the end of the array or not. If at any index i, arr[i] is less than arr[i + 1] then break the loop.
If we reach the end in the above step then print “Yes” Else print “No”.
If arr[1] < arr[0], then check for strictly decreasing then strictly increasing as: 
Check for every consecutive pair until at any index i arr[i + 1] is greater than arr[i].
Now from index i + 1 check for every consecutive pair check if arr[i + 1] is greater than arr[i] till the end of the array or not. If at any index i, arr[i] is greater than arr[i + 1] then break the loop.
If we reach the end in the above step then print “Yes” Else print “No”.
Below is the implementation of above approach:
*/

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to check if the given array
// forms an increasing decreasing
// sequence or vice versa
bool canMake(int n, int ar[])
{
    // Base Case
    if (n == 1)
        return true;
    else
    {

        // First subarray is
        // stricly increasing
        if (ar[0] < ar[1])
        {

            int i = 1;

            // Check for strictly
            // increasing condition
            // & find the break point
            while (i < n && ar[i - 1] < ar[i])
            {
                i++;
            }

            // Check for strictly
            // decreasing condition
            // & find the break point
            while (i + 1 < n && ar[i] > ar[i + 1])
            {
                i++;
            }

            // If i is equal to
            // length of array
            if (i >= n - 1)
                return true;
            else
                return false;
        }

        // First subarray is
        // strictly Decreasing
        else if (ar[0] > ar[1])
        {
            int i = 1;

            // Check for strictly
            // increasing condition
            // & find the break point
            while (i < n && ar[i - 1] > ar[i])
            {
                i++;
            }

            // Check for strictly
            // increasing condition
            // & find the break point
            while (i + 1 < n && ar[i] < ar[i + 1])
            {
                i++;
            }

            // If i is equal to
            // length of array - 1
            if (i >= n - 1)
                return true;
            else
                return false;
        }

        // Condition if ar[0] == ar[1]
        else
        {
            for (int i = 2; i < n; i++)
            {
                if (ar[i - 1] <= ar[i])
                    return false;
            }
            return true;
        }
    }
}

// Driver Code
int main()
{
    // Given array arr[]
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof arr / sizeof arr[0];

    // Function Call
    if (canMake(n, arr))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}