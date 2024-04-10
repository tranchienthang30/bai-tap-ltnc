#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b){
    return a * (b / __gcd(a, b));
}

int main()
{
    int n, m; 
	cin>>n>>m;
    int a[n+1], b[m+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<m;i++)
    {
        cin >> b[i];
    }

    int bc = a[0];
    for(int i=1;i<n;i++)
    {
        bc=lcm(bc, a[i]);
    }

    int uc=b[0];
    for(int i=1;i<m;i++)
	{
        uc = __gcd(uc,b[i]);
    }
    int dem = 0;
    for(int i=bc;i<=uc; i+= bc)
    {
        if(uc%i==0)
        {
            dem++;
        }
    }
    cout<<bc<<" "<<uc<<endl;
    cout<<dem;
    return 0;
}
