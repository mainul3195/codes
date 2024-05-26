#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    for(auto c: s)
        cout << (char)toupper(c);
        cout << "\n";
    return 0;

}