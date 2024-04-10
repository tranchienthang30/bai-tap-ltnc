#include <bits/stdc++.h>

using namespace std;


int main() 
{
    int q; 
	cin>>q;
    set<int>s;
    for(int i=1;i<=q;i++)
    {
        int a,b; 
		cin>>a>>b;
        if(a==1) s.insert(b);
        else if(a==2) s.erase(b);
        else if(a==3)
        {
            if(s.count(b)==1) cout <<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }

    return 0;
}
