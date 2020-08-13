#include<iostream>
using namespace std;
int main()
{
	int i, j, k=0, size, a[100];
	 cout<<"Enter Size of Matrix\n";
    cin>>size;	
	int l=size*3-2;
	cout<<"\nEnter elements\n";
	for (i = 0; i < l; i++)
		cin>>a[i];
	cout<<"\nThe matrix is...\n";
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i-j == -1 || i-j == 0 || i-j == 1)
			{
				cout<<a[k]<<" "; 
				k++;
			}
			else
				cout<<"0 ";
		}
		cout<<"\n";
	}
	return 0;
}