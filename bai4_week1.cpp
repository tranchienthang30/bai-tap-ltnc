#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    switch(n)
    {
        case 1:
        {
            printf("one");
            break;
        }
        case 2:
        {
            printf("two");
            break;
        }
        case 3:
        {
            printf("three");
            break;
        }
        case 4:
        {
            printf("four");
            break;
        }
        case 5:
        {
            printf("five");
            break;
        }
        case 6:
        {
            printf("six");
            break;
        }
        case 7:
        {
            printf("seven");
            break;
        }
        case 8:
        {
            printf("eight");
            break;
        }
        case 9:
        {
            printf("nine");
            break;
        }
        default:
        {
            printf("Greater than 9");
            break;
        }
    }
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
