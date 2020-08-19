#include <iostream>
using namespace std;

int main()
{
    int rows, column;
    cout << "Enter no of rows and column\n";
    cin >> rows >> column;
    int a[rows][column];
    cout<<"Enter elements\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cin>>a[i][j];
        }
    }



    return 0;
}