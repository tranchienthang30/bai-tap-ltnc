#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=n;i>0;i--)
	{
		cout<<a[i]<<" ";
	}
}
