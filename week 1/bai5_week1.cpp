#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 3e5+6;
int arr[maxN];
int maxOfFour(int a, int b, int c, int d) {
    return max(a, max(b, max(c, d)));
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << maxOfFour(a, b, c, d);
}
