#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n, m;
vector<int> v;
vector<vector<long long>> dp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    v = vector<int>(n);
    dp = vector<vector<long long>>(n + 2, vector<long long>(m + 2, 0));
    for (auto &i : v)
        cin >> i;
    if (v[0])
        dp[0][v[0]] = 1;
    else
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i])
            dp[i][v[i]] = (dp[i - 1][v[i] - 1] + dp[i - 1][v[i]] + dp[i - 1][v[i] + 1]) % mod;
        else
            for (int j = 1; j <= m; j++)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
    }
    if (v[n - 1])
        cout << dp[n - 1][v[n - 1]] << "\n";
    else
    {
        long long tot = 0;
        for (int i = 1; i <= m; i++)
            (tot += dp[n - 1][i]) %= mod;
        cout << tot << "\n";
    }
    return 0;
}