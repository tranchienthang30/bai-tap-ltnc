#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++){
        if (isalpha(s[i])){
            if (islower(s[i])){
                s[i] = (char)('a' + ((s[i] + k - 'a') % 26)); 
            }
            else s[i] = (char)('A' + ((s[i] + k - 'A') % 26));
        }
    }
    cout << s;
    return 0;
}
