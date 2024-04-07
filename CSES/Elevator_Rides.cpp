#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, pair<long long, long long> p)
{
    return os << "( " << p.first << " , " << p.second << " )\n";
}
long long n, x;
vector<long long> w;
vector<pair<long long, long long>> dp;
pair<long long, long long> combine(pair<long long, long long> a, pair<long long, long long> b)
{
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    return a.second < b.second ? a : b;
}
pair<long long, long long> okdone(int mask)
{
    if (~dp[mask].first && ~dp[mask].second)
        return dp[mask];
    if (__builtin_popcount(mask) == 1)
    {
        int i;
        for (i = 0; i < n; i++)
            if (mask & (1LL << i))
                break;
        return dp[mask] = {1LL, w[i]};
    }

    pair<long long, long long> p, ans = {-2000000000, 2000000000}, tmp;
    for (int i = 0; i < n; i++)
        if (mask & (1LL << i))
        {
            tmp = okdone(mask ^ (1LL << i));
            if (tmp.second + w[i] <= x)
                p = {tmp.first, tmp.second + w[i]};
            else
                p = {tmp.first + 1, w[i]};
            ans = combine(ans, p);
        }
    return dp[mask] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    w = vector<long long>(n);
    for (auto &i : w)
        cin >> i;
    dp = vector<pair<long long, long long>>(1LL << n + 2);
    for (auto &[a, b] : dp)
        a = b = -1;
    cout << okdone((1ll << n) - 1).first << "\n";
    // cout << dp[1];
    // cout << dp[2];
    // cout << dp[4];
    // cout << dp[12];
    // cout << ((1LL << n) - 1) << "\n";
    return 0;
}