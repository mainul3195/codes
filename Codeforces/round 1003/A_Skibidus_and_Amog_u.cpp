#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        s.pop_back();
        s.pop_back();
        s.push_back('i');
        cout << s << "\n";
    }
    return 0;
}