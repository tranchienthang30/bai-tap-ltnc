#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int a[],int n,int x)
{
	int left, right, mid; left=0; right=n-1;
	do{
		mid=(left+right)/2;
		if(a[mid]==x){
			return mid;
		}
		else if(a[mid]<x){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}while(left<=right);
	return -1;
}
int main()
{
	int n,x;
	cin>>n>>x;
	int a[x+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<BinarySearch(a,n,x);
}
