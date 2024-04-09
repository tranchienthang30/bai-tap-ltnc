#include <bits/stdc++.h>

using namespace std;
int n, q, a[1000000];

int search(int x) 
{
    int i = 1;
    int j = n;
    while (i < j) {
        int m = i + (j - i) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) i = m + 1;
        else j = m - 1;
    }
    return i;
}

int main(){

    cin >> n;
    for (int i=1;i<= n;i++) 
	{
		cin >> a[i];
	}
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int tmp = search(x);
        if (a[tmp] != x) {
            if (a[tmp] < x) tmp++;
            cout<<"No "<<tmp<<endl;
        }
        else {
            for (int i = tmp; i >= 0; --i) {
                if (a[i] == x) tmp = i;
                else break;
            }
            cout << "Yes " << tmp <<endl;
        }
    }

    return 0;
}
