#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        int x;
        int y;
        cin >> x >> y;
        int count = 1;
        v.push_back(x + 3);
        v.push_back(y + 2);
        while (true)
        {
            if (v[0] > 5 && v[1] > 10)
            {
                count++;
                v[0] -= 5;
                v[1] -= 10;
                v[0] += 3;
                v[1] += 2;
                count++;
            }
            else if (v[0] > 20 && v[1] > 5)
            {
                count++;
                v[0] -= 20;
                v[1] += 5;
                v[0] += 3;
                v[1] += 2;
                count++;
            }
            else
            {
                break;
            }
        }
        cout << count << endl;
    }
    return 0;
}