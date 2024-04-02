#include <bits/stdc++.h>

using namespace std;

int palindromeIndex(string s) {
    int n = s.length(), z = -1;
    for (int i = 0; i < n / 2; ++i){
        if (s[i] != s[n - 1 - i]){
            z = i;
            break;
        }
    }
    if (z == -1) return -1;
    if (s[z + 1] == s[n - 1 - z]){
        int flag = 1;
        string d = s.substr(0, z) + s.substr(z + 1);
        int x = (int) d.length();
        for (int i = 0; i < x / 2; ++i){
            if (d[i] != d[x - 1 - i]){
                flag = 0;
                break;
            } 
        }
        if (flag) return z;
    }
    if (s[z] == s[n - 2 - z]){
        z = n - 1 - z;
        string d = s.substr(0, z) + s.substr(z + 1);
        int x = (int) d.length();
        for (int i = 0; i < x / 2; ++i){
            if (d[i] != d[x - 1 - i]) return -1;
        }
    }
    return z;
}

int main(){
    int q;
    cin >> q;
    cin.ignore();
    while(q--){
        string s;
        getline(cin, s);
        cout << palindromeIndex(s) << endl;
    }
}
