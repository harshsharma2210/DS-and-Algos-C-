// CPP implementation of
// above algorithm
#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n)
{
    sort(a, a + n);
    int sum = 0;
    vector<int> v;
    for (int i = 0; i < n / 2; i++)
    {
        v.push_back(a[i]);
        v.push_back(a[n - i - 1]);
    }
    if (n % 2 != 0)
    {
        v.push_back(a[n / 2 + 1]);
    }
    for (int i = 1; i < n; i++)
    {
        sum += abs(v[i] - v[i - 1]);
    }
    sum += abs(v[n-1] - v[0]);
    return sum;
}

// Driver function
int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << MaxSumDifference(a, n) << endl;
}