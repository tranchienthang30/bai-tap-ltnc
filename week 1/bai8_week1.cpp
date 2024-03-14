#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 3e5+6;
int arr[maxN];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        bool flag = false;
        int n; cin >> n;
        int sumL = 0; int sumR = 0;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        for(int i = 1; i <= n; i++) sumL += arr[i];
        for(int i = 1; i <= n; ++i) {
            sumL -= arr[i];
            if (sumL == sumR) {
                flag = true;
            }
            sumR += arr[i];
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
