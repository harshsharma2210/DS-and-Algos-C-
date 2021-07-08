// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    static bool sorting(Item a, Item b)
    {
        double c = (double)a.value / a.weight;
        double d = (double)b.value / b.weight;
        return c > d;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, sorting);
        double weight = 0;
        double profit = 0;
        for (int i = 0; i < n; i++)
        {
            if (weight + arr[i].weight <= W)
            {
                profit += arr[i].value;
                weight += arr[i].weight;
            }
            else
            {
                double x = (double)(W - weight) / arr[i].weight;
                profit += (double)x * arr[i].value;
                break;
            }
        }
        return profit;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends