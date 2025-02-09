#include <bits/stdc++.h>
using namespace std;
int n, k, d;
vector<long long> v;
#define neg -1000000000000000LL;
long long dp[101][101][101];
long long okdone(int i = 0, int done = 0, int md = 0)
{
    if (done == k)
    {
        if (md == 0)
            return 0;
        return neg;
    }
    if (i == n)
        return neg;
    if (~dp[i][done][md])
        return dp[i][done][md];
    return dp[i][done][md] = max(okdone(i + 1, done, md), v[i] + okdone(i + 1, done + 1, (md + v[i]) % d));
}
void solve()
{
    cin >> n >> k >> d;
    v = vector<long long>(n);
    for (auto &i : v)
        cin >> i;
    memset(dp, -1, sizeof(dp));
    long long val = okdone();
    if (val < 0)
        cout << "-1\n";
    else
        cout << val << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}