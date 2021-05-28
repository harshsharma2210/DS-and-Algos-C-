#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> p)
{
    for (auto i : p)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void mergeRow(vector<vector<int>> &a, int rlb, int rub, int midr, int cub, int clb, int midc)
{
    for (int z = rlb; z <= rub; z++)
    {
        int n1 = midc - clb + 1;
        int n2 = cub - midc;

        // Create temp arrays
        int L[n1], R[n2];

        // Copy data to temp arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = a[z][clb + i];
        for (int j = 0; j < n2; j++)
            R[j] = a[z][midc + 1 + j];

        // Merge the temp arrays back into arr[l..r]

        // Initial index of first subarray
        int i = 0;

        // Initial index of second subarray
        int j = 0;

        // Initial index of merged subarray
        int k = clb;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                a[z][k] = L[i];
                i++;
            }
            else
            {
                a[z][k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of
        // L[], if there are any
        while (i < n1)
        {
            a[z][k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of
        // R[], if there are any
        while (j < n2)
        {
            a[z][k] = R[j];
            j++;
            k++;
        }
    }
}

void mergeColumn(vector<vector<int>> &a, int rlb, int rub, int midr, int cub, int clb, int midc)
{
    for (int z = clb; z <= cub; z++)
    {
        int n1 = midr - rlb + 1;
        int n2 = rub - midr;

        // Create temp arrays
        int L[n1], R[n2];

        // Copy data to temp arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = a[rlb + i][z];
        for (int j = 0; j < n2; j++)
            R[j] = a[midr + 1 + j][z];

        // Merge the temp arrays back into arr[l..r]

        // Initial index of first subarray
        int i = 0;

        // Initial index of second subarray
        int j = 0;

        // Initial index of merged subarray
        int k = rlb;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                a[k][z] = L[i];
                i++;
            }
            else
            {
                a[k][z] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of
        // L[], if there are any
        while (i < n1)
        {
            a[k][z] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of
        // R[], if there are any
        while (j < n2)
        {
            a[k][z] = R[j];
            j++;
            k++;
        }
    }
}
void mergeSort(vector<vector<int>> &a, int rlb, int rub, int clb, int cub)
{
    if (rlb < rub || clb < cub)
    {
        int midr = (rlb + rub) / 2;
        int midc = (clb + cub) / 2;
        mergeSort(a, rlb, midr, clb, midc);
        mergeSort(a, rlb, midr, midc + 1, cub);
        mergeSort(a, midr + 1, rub, midc + 1, cub);
        mergeSort(a, midr + 1, rub, clb, midc);
        mergeRow(a, rlb, rub, midr, cub, clb, midc);
        mergeColumn(a, rlb, rub, midr, cub, clb, midc);
    }
}

int main()
{
    // your code goes here
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    mergeSort(a, 0, m - 1, 0, n - 1);
    display(a);
    return 0;
}
