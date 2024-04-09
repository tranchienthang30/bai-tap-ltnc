#include<bits/stdc++.h>
using namespace std;
int main()
{int n;
vector<int>v;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	int q;
	cin>>q;
	v.erase(v.begin()+q-1);
	int v2[2];
	for(int i=0;i<2;i++)
	{
		cin>>v2[i];
	}
	v.erase(v.begin()+v2[0]-1,v.begin()+v2[1]-1);
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}
