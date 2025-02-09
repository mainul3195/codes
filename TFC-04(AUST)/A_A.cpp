#include <bits/stdc++.h>
using namespace std;
#define lim 100005
vector<int> divs[lim];
void find_divs()
{
    for (int i = 1; i < lim; i++)
        for (int j = i + i; j < lim; j += i)
            divs[j].push_back(i);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1), dp(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        for (auto d : divs[i])
            if (v[d] < v[i])
                mx = max(mx, dp[d]);
        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    find_divs();
    cin >> t;
    while (t--)
        solve();
    return 0;
}