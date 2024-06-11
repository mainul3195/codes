#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    bool frst = 1;
    while (s.size())
    {
        char c = s.back();
        s.pop_back();
        if (!s.size())
        {
            if (c != '1')
                cout << "NO\n";
            else
                cout << "YES\n";
            return;
        }
        int tot = 10 + c - '0';
        if (frst && tot == 19)
        {
            cout << "NO\n";
            return;
        }
        if (frst)
            frst = 0;
        else
            tot--;
        if (tot < 10)
        {
            cout << "NO\n";
            return;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}