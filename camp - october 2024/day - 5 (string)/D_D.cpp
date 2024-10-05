#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
string s;
vector<long long> isp;
void pre()
{
    isp = vector<long long>(s.size(), -1);
    long long l = -1, r = 1;
    while (r < s.size())
    {
        if (s[l + 1] == s[r])
            isp[r++] = ++l;
        else
        {
            if (!l)
                l = -1;
            else if (l > 0)
                l = isp[l - 1];
            else
                r++;
        }
    }
    for (auto &i : isp)
        i++;
    reverse(isp.begin(), isp.end());
    isp.push_back(0);
    reverse(isp.begin(), isp.end());

    return;
}
int n;
vector<vector<long long>> dp;
long long okdone(int i = 0, int matched = 0)
{
    if (matched == s.size())
        return 0;
    if (i == n)
        return 1;
    if (~dp[i][matched])
        return dp[i][matched];
    long long tot = 0;
    for (char a = 'A'; a <= 'Z'; a++)
    {
        if (a == s[matched])
            (tot += okdone(i + 1, matched + 1)) %= mod;
        else
        {
            while (!((matched == 0) || (s[matched] == a)))
                matched = isp[matched];
            if (a == s[matched])
                (tot += okdone(i + 1, matched + 1)) %= mod;
            else
                (tot += okdone(i + 1, matched)) %= mod;
        }
    }
    return dp[i][matched] = tot;
}
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % mod;
}
void solve()
{
    cin >> n >> s;
    dp = vector<vector<long long>>(n + 5, vector<long long>(s.size() + 5, -1));
    pre();
    cout << bigMod(26, n) << " " << okdone() << "\n";
    cout << (bigMod(26, n) - okdone() + mod) % mod << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}