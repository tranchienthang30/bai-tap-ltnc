#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n>=2 && n<=5)
	{
		if(n%2==1) cout<<"Weird";
		else cout<<"Not Weird";
	}
     if(n>=6 &&n<=20)
	{
		if(n%2==0) cout<<"Weird";
		else cout<<"Not Weird";
	}
	if(n>20)
	{
		if(n%2==0) cout<<"Not Weird";
		else cout<<"Weird";
	}
}
