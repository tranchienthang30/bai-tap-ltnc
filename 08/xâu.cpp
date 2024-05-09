#include<bits/stdc++.h>
using namespace std;
void generateStrings(vector<char>& characters, int n, string current) {
    if (n == 0) {
        cout << current << endl;
        return;
    }

    for (int i = 0; i < characters.size(); ++i) {
        generateStrings(characters, n - 1, current + characters[i]);
    }
}

int main() {
    vector<char> characters = {'a', 'b', 'c', 'd'};
    int length = 3;
    
    generateStrings(characters, length, "");
    
    return 0;
}
