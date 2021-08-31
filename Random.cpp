int sb(int arr[], int n, int x)
{
    // Your code goes here
    int i = 0;
    int j = 0;
    int currsum = 0;
    int ans = INT_MAX;
    while (j < n)
    {
        = "" currsum += "arr[j];" if (currsum < x) = ""
        {
            = "" j++;
            = ""
        }
        = "" else = "" if (currsum = "" >= x)
        {
            while (currsum > x)
            {
                ans = min(j - i + 1, ans);
                currsum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return ans;
}