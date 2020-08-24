#include <iostream>
using namespace std;
int main()
{
    int number[25], n, data, i, flag = 0;
    cout<<"\n Enter the number of elements:";
    cin>>n;
    cout<<"\n Enter the elements:";
    for (i = 0; i < n; i++)
        cin>>number[i];
    cout<<"\n Enter the element to be Searched: ";
    cin>>data;
    for (i = 0; i < n; i++)
    {
        if (number[i] == data)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout<<"\n Data found at location:"<< i + 1;
    else
        cout<<"\n Data not found ";
    
}