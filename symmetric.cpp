
// Symmetric

// #include <iostream>
// using namespace std;
// int main()
// {
// 	int n, m;
// 	cout << "Enter the size of the matrix\n";
// 	cin >> n;
// 	m = n * (n + 1) / 2;
// 	int a[m];
// 	cout << "Enter the elements\n";
// 	for (int i = 0; i < m; i++)
// 		cin >> a[i];
// 	int k = n - 1;
// 	for (int i = 0; i < n; i++)
// 		cout << a[i] << " ";
// 	cout<<"\n";
// 	for (int i = 1; i < n; i++)
// 	{
// 		cout << a[i] << " ";
// 		int j = 0, m = k, ind = 0, last = i + m;
// 		for (; j < i; j++)
// 		{
// 			cout << a[last] << " ";
// 			ind = last;
// 			m--;
// 			last = last + m;
// 			if (m == 0)
// 				m = 1;
// 		}
// 		for (; j < n - 1; j++)
// 		{
// 			cout << a[++ind] << " ";
// 		}
// 		cout << "\n";
// 	}
// }

#include<iostream>
using namespace std;
int main()
{
	int i,j,k,m,n,l,s;
	cout<<"Enter the size of the matrix \n";
	cin>>n;
	m = n*(n+1)/2;
	l = n-2;
	s = -2;
	k = 0;
	int a[m];
	cout<<"Enter the elements\n";
	for(i=0;i<m;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<=j)
			{
				cout<<a[k++]<<" ";
			}
			else
			{
				cout<<a[i+j+s]<<" ";
				s = s+l;
				l--;
			}
		}
		l = n-2;
		s = -2;
		cout<<endl;
	}
}