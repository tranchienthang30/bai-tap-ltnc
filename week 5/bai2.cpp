#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    set <int>s;
    map<int,int>m;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
        s.insert(a[i]);
    }
    int max1=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=s.count(a[i]))
        {
            max1=max(m[a[i]],max1);
            s.erase(a[i]);
        }
    }
    cout<<n-max1;
    
}
