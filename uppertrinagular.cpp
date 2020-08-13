
// Upper Triangular

#include<iostream>
using namespace std;
int main()
{
	int n,m,k=0,i,j;
	cout<<"Enter the size of the matrix\n";
	cin>>n;
	m = n*(n+1)/2;
	int a[m];
	cout<<"Enter the elements\n";
	for(i=0;i<m;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<=j)
			{
				cout<<a[k]<<" ";
				k++;
				
			}
			else
			cout<<"0"<<" ";
		}
		cout<<endl;
	}
}