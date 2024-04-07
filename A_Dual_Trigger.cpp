#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one_count = 0;
    for (auto c : s)
        if (c == '1')
            one_count++;
    if (one_count & 1)
    {
        cout << "NO\n";
        return;
    }
    if (one_count > 2 || !one_count)
    {
        cout << "YES\n";
        return;
    }
    int first = -1, second = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
        {
            if (first == -1)
                first = i;
            else
                second = i;
        }
    if (second - first > 1)
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