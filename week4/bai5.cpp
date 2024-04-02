#include <bits/stdc++.h>

using namespace std;

bool check(string s){
    string tmp = "hackerrank";
    int pos = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == tmp[pos]) pos++;
    }
    return pos == tmp.length();
}

int main(){
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        if (check(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
