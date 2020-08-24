#include <iostream>
using namespace std;

int recursive(int *a,int n,int data,int pos)
{
    if(pos<n)
    {
        if(a[pos]==data)
        {
            cout<<"Found at"<<pos+1;
            return 0;
        }
        pos++;
        recursive(a,n,data,pos);
    }

    else
    {
        cout<<"Not found\n";
    }
}

int main()
{
    int a[25],n,data;
    cout<<"Enter the no of elements:\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter element to be searched:\n";
    cin>>data;
    recursive(a,n,data,0);
}