#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Matrix Size\n";
    cin >> n;
    int a[n][n];
    int flag=0;
    cout<<"Enter elements\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {

        int minrow = a[i][0],col=0;
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] < minrow)
            {
                minrow =a[i][j];
                col=j;
            }

        }
        flag=1;
        for(int j=0;j<n;j++)
        {
            if(minrow<a[j][col])
            {
                flag=0;
            }

        }
        if(flag==1)
        {
            cout<<"Saddle Point is = "<<minrow<<" at ("<<i<<","<<col<<")";
            return 0;
        }
    }
    if(flag==0)
    {
        cout<<"No saddle point found";
    }
}