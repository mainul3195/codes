#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string a = s;
    string b = s;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    if (a != s)
        cout << "YES\n"
             << a << "\n";
    else if (b != s)
        cout << "YES\n"
             << b << "\n";
    else
        cout << "NO\n";
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