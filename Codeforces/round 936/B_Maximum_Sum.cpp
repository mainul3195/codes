#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % Mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % Mod;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    long long mx_sum = 0, local_max = 0, start = 0, end = -1, l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        local_max += v[i];
        if (local_max > mx_sum)
        {
            mx_sum = local_max;
            end = i;
            l = start, r = i;
        }
        if (local_max < 0)
        {
            local_max = 0;
            start = i + 1;
        }
    }
    long long ans = bigMod(2, k) * (mx_sum % Mod) % Mod;
    // cout << ans << "\n";
    for (int i = 0; i < n; i++)
        if (!(i >= l && i <= r))
            ans = (ans + v[i] + Mod) % Mod;
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