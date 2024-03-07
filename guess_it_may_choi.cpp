#include <bits/stdc++.h>

using namespace std;
int randomnumber()
{
    return rand() % 100+1;
}
void check(int guess, int secretnumber)
{
    if(guess>secretnumber) cout<<"too big "<<endl;
    else if(guess<secretnumber) cout<<"too small "<<endl;
    else cout<<"correct! ";
}
int choosemunber(int high, int low)
{
    return (high+low)/2;
}
void updateNumbers(int* num1, int* num2, int guess, int secretnumber) {
    if(guess>secretnumber) *num2=guess-1;
    if(guess<secretnumber) *num1=guess+1;
    cout<<"choosing of computer: "<<guess<<endl;
}
void print(int secretnumber)
{
    cout<<"correct number is: "<<secretnumber<<endl;
}
int main() {
    srand(time(0));
    int low=1,high=100;
   int secretnumber=randomnumber();
   int guess;
   do{
    guess=choosemunber(low,high);
   updateNumbers(&low,&high,guess,secretnumber);
    check(guess,secretnumber);
   }while(guess!=secretnumber);
   print(secretnumber);
}

