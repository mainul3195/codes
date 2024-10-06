#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
void solve()
{
    int q, k;
    cin >> q >> k;
    long long dp[k + 5] = {0};
    dp[0] = 1;
    while (q--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            for (int i = k - x; i >= 0; i--)
                (dp[i + x] += dp[i]) %= mod;
        }
        else
        {
            for (int i = 0; i + x <= k; i++)
                (dp[i + x] -= dp[i]) %= mod;
        }
        cout << (dp[k] + mod) % mod << "\n";
    }

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}