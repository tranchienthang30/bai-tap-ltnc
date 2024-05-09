#include<bits/stdc++.h>
using namespace std;
class Student {
    private:
        int a, b, c, d, e;
        
    public:
        void input() {
            cin >> a >> b >> c >> d >> e;
        }  
        int calculateTotalScore() {
            return a + b + c + d + e;
        }
};
int main() {
    int n; 
    cin >> n;
    Student *s = new Student[n]; 
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    int kristen_score = s[0].calculateTotalScore();

    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }
    cout << count;
    
    return 0;
}

