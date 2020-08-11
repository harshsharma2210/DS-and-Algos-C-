#include<bits/stdc++.h>
using namespace std;
int main() {
	long long int k;
	cin>>k;
	if(k%2!=0)
	{
		long long int m,n;
		m=(k+1)/2;
		n=(k-1)/2;
		if((m*m+n*n)<(2*m*n+m*m-n*n))
		cout<<2*m*n<<" "<<(m*m+n*n);
		else 
		cout<<"-1";
	}
	else
	{
		long long int m,n;
		m=k/2;
		n=1;
		if((m*m+n*n)<(2*m*n+m*m-n*n))
		cout<<(m*m-n*n)<<" "<<(m*m+n*n);
		else
		cout<<"-1";

	}
	return 0;
}