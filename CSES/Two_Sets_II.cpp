#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<vector<long long>> dp;
int n;
long long okdone(int i, int rem)
{
    if (!rem)
        return 1;
    if (i > n || i > rem)
        return 0;
    if (~dp[i][rem])
        return dp[i][rem];
    return dp[i][rem] = (okdone(i + 1, rem - i) + okdone(i + 1, rem)) % mod;
}
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return b * bigMod(b, p - 1) % mod;
    long long t = bigMod(b, p / 2);
    return t * t % mod;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum & 1)
        cout << "0\n";
    else
    {
        long long inverse_2 = bigMod(2, mod - 2);
        dp = vector<vector<long long>>(n + 1, vector<long long>(sum / 2 + 2, -1));
        cout << okdone(1, sum / 2) * inverse_2 % mod << "\n";
    }
    return 0;
}