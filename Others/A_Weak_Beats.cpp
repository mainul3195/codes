#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    bool ok = 1;
    for(int i = 1; i<s.size(); i+=2)
    {
        if(s[i] == '1')
        {
            ok = 0;
            break;
        }
    }
    if(ok)
        cout << "Yes\n";
    else cout << "No\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}