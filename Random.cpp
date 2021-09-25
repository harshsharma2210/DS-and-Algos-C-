// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int ally(long long int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        cout << ally(n) << endl;
    }
    return 0;
} // } Driver Code Ends

int findSmallestPermutation(string &s)
{
    int len = s.length();

    // sort the string
    sort(s.begin(), s.end());

    // check for leading zero in string
    // if there are any leading zeroes,
    // swap the first zero with first non-zero number
    int i = 0;
    while (s[i] == '0')
        i++;

    swap(s[0], s[i]);
    int a = stoi(s);
    return (a);
}
int ally(long long int n)
{
    // code here
    for (long long int i = 1; i <= n; i++)
    {
        string a=to_string(i);
        if (i != findSmallestPermutation(a))
        {
            return i;
        }
    }
    return -1;
}