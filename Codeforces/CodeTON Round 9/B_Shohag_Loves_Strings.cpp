#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1])
        {
            cout << s[i] << s[i] << "\n";
            return;
        }
    for (int i = 2; i < s.size(); i++)
        if ((s[i] != s[i - 1]) && (s[i - 1] != s[i - 2]) && (s[i - 2] != s[i]))
        {
            cout << s[i - 2] << s[i - 1] << s[i] << "\n";
            return;
        }
    cout << "-1\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}