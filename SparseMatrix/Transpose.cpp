#include <iostream>
using namespace std;

int main()
{
    int rows, columns, size;
    cout << "Enter the no of rows of the matrix\n";
    cin >> rows;
    cout << "Enter the no of columns of the matrix\n";
    cin >> columns;
    int sparseMatrix[rows][columns];
    cout << "Enter Elements";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> sparseMatrix[i][j];
            if (sparseMatrix[i][j] != 0)
                size++;
        }
    }
    int compactMatrix[3][size];
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
    }
    
}