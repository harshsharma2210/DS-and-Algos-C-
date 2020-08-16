#include <iostream>
using namespace std;
int m, n;
void row_sum(int arr[][100])
{
    int i, j, sum = 0;

    cout << "\nFinding Sum of each row:\n\n";

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {

            sum = sum + arr[i][j];
        }

        cout << "Sum of the row " << i << " = " << sum << endl;
        sum = 0;
    }
}

void column_sum(int arr[][100])
{

    int i, j, sum = 0;

    cout << "\nFinding Sum of each column:\n\n";
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            sum = sum + arr[j][i];
        }

        cout << "Sum of the column " << i << " = " << sum << endl;
        sum = 0;
    }
}

int main()
{

    int i, j;
    cout << "Enter no of row\n";
    cin >> m;
    cout << "Enter no of column\n";
    cin >> n;

    int arr[m][n];
    cout<<"Enter the elements";
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin>>arr[i][j];

    row_sum(arr);

    column_sum(arr);

    return 0;
}