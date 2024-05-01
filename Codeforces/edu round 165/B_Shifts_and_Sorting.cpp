#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int one_count = 0;
    long long ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            one_count++;
        else
            ans += (one_count ? one_count + 1 : 0);
    }
    cout << ans << "\n";
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