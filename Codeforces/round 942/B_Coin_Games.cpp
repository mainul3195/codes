#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'U')
            ans ^= 1;

    if (ans)
        cout << "YES\n";
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