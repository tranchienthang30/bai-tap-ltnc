#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int c;
	c=s[1]-'0';

	if(s[s.size()-2]=='P' && s[0]!='1' && s[1]!='2')
	{
		c=c+12;
		cout<<c;
		for(int i=2;i<s.size()-2;i++)
        {
            cout<<s[i];
        }
	}
	else if(s[s.size()-2]=='P' && s[0]=='1' && (s[1]=='0'||s[1]=='1'))
    {
        c=c+2;
        cout<<2<<c;
        for(int i=2;i<s.size()-2;i++)
        {
            cout<<s[i];
        }

    }
    else if(s[s.size()-2]=='A' && s[0]=='1'&&s[1]=='2')
    {
        cout<<"00";
        for(int i=2;i<s.size()-2;i++)
        {
            cout<<s[i];
        }

    }
	else for(int i=0;i<s.size()-2;i++)
    {

        cout<<s[i];
    }



}

