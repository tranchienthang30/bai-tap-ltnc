#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[1000010];
signed main() {
    int n; cin >> n;
    int pos = 0;
    int neg = 0;
    int zero = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if (arr[i] < 0) neg++;
        else if (arr[i] == 0) zero++;
        else pos++;
    }
    cout << fixed << setprecision(6) << pos*1.0/n << endl << neg*1.0/n << endl << zero * 1.0 /n;
}
