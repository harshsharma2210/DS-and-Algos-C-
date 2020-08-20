
#include <iostream>
using namespace std;
int main()
{
    int i, k, j, A, str, stc, enr, enc, dif;
    cout << "Enter the number: \n";
    cin >> A;
    if (A < 1 || A > 1000)
    {
        exit(0);
    }
    else
    {
        int a[A][A];
        str = stc = dif = 0;
        enr = A - 1;
        enc = A - 1;
        k = 1;
        cout << "\nThe matrix is: \n";
        while (str <= enr && stc <= enc)
        {

            for (i = stc; i <= enc; i++)
            {
                a[str][i] = k;
                k++;
            }
            str++;
            for (i = str; i <= enr; i++)
            {
                a[i][enc] = k;
                k++;
            }
            enc--;
            for (i = enc; i >= stc; i--)
            {
                a[enr][i] = k;
                k++;
            }
            enr--;
            for (i = enr; i >= str; i--)
            {
                a[i][stc] = k;
                k++;
            }
            stc++;
        }
    }
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < A; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
