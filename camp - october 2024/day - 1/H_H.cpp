#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
vector<long long> dp;
int n;
void solve()
{
    cin >> n;
    dp = vector<long long>(n + 1, 0);
    long long f[65][2] = {0};
    for (int i = 0; i < 63; i++)
        f[i][0] = 1;
    dp[0] = 1;
    int pref = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pref ^= a;
        for (int j = 0; j < 63; j++)
        {
            if (pref & (1LL << j))
                (dp[i] += f[j][0] * ((1LL << j) % mod) % mod) %= mod;
            else
                (dp[i] += f[j][1] * ((1LL << j) % mod) % mod) %= mod;
        }
        for (int j = 0; j < 63; j++)
            (f[j][!!(pref & (1LL << j))] += dp[i]) %= mod;
    }
    cout << dp[n] << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}