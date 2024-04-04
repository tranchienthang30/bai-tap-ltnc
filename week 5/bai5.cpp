#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	int a[n+1],b[m+1];
	set<int> s1;
	set<int>s2;
	map<int,int> m1;
	map<int, int>m2;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s1.insert(a[i]);
	}
	for(int i=0;i<n+1;i++)
	{
		cin>>b[i];
		m2[b[i]]++;
	}
	for(int i=0;i<n+1;i++)
	{
		if(m2[b[i]]==1 && s1.count(b[i])==0)
		{
			cout<<b[i];
		}
	}
}
