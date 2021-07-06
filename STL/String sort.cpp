// Problem Name: String Sort
// Problem Difficulty: 2
// Problem Constraints: N<=1000
// Problem Description:
// Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all the strings   ( lexicographically ) but if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.
// Input Format: N(integer) followed by N strings.
// Sample Input: 3
// bat
// apple
// batman
// Output Format: N lines each containing one string.
// Sample Output: apple
// batman
// bat

#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b)
{
    string temp = b.substr(0, a.length());
    if (temp == a)
        return a < b;
    temp = a.substr(0, b.length());
    if (temp == b)
        return b < a;
    return (a < b);
}

int main()
{
    int a;
    cin >> a;
    vector<string> v;
    for (int i = 0; i < a; i++)
    {
        string x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), compare);
    for (auto i : v)
    {
        cout << i << endl;
    }
}