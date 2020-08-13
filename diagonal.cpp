
// Diagonal

#include <iostream>
using namespace std;
int main()
{   
    int i, j, a[100],size;
    cout<<"Enter Size of Matrix\n";
    cin>>size;
    cout<<"Enter elements:\n";    
    for (i = 0; i < size; i++)
        cin>>a[i];
    cout<<("\nThe matrix is...\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i==j)
                cout<<a[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<("\n");
    }
    return 0;
}
