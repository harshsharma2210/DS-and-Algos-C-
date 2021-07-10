
// CPP program to find minimum number of
// elements such that their sum is greater
// than sum of remaining elements of the array.
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

// function to find minimum elements needed.
int minElements(int arr[], int n)
{
    sort(arr, arr + n, greater<int>());
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n-1; i++)
    {
        sum = sum + arr[i];
        count++;
        if (sum > accumulate(arr + i+1, arr + n, 0))
        {
            break;
        }
    }
    return count;
}

// Driver function
int main()
{
    int arr[] = {2,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElements(arr, n) << endl;
    return 0;
}