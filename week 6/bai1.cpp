#include <bits/stdc++.h>

using namespace std;

void update(int *a,int *b) 
{
    int pa = *a + *b;
    int pb = abs(*a - *b);
    *a = pa;
    *b = pb;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
   cin>>a>>b;
    update(pa, pb);
  cout<<a<<endl;
  cout<<b;

    return 0;
}
