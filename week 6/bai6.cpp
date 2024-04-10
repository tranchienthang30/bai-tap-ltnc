#include <bits/stdc++.h>

using namespace std;


int main() {
    map<string,int> m;
    int q; 
	cin>>q;
    for(int i=1;i<=q;i++)
	{
        int n; cin>>n;
        if(n==1){
            string s; 
			cin>>s;
            int p; cin>>p;
            m[s]+=p;
        }
		else if(n==2){
            string s; 
			cin>>s;
            m.erase(s);
        }
		else if(n==3)
		{
            string s; 
			cin>>s;
            cout<<m[s]<<endl;
        }
    }
    return 0;
}
