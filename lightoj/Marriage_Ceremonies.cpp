#include <bits/stdc++.h>
using namespace std;
int gd[17][17], dp[17][(1 << 16) + 1];
int n;
int okdone(int i, int mask)
{
    if (i == n)
        return 0;
    if (~dp[i][mask])
        return dp[i][mask];
    int mul = 1;
    int ans = 0;
    for (int k = 0; k < n; k++)
    {
        if ((mask & mul) == 0)
            ans = max(ans, okdone(i + 1, mask | mul) + gd[i][k]);
        mul <<= 1;
    }
    return dp[i][mask] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> gd[i][j];
    memset(dp, -1, sizeof(dp));

    cout << okdone(0, 0) << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}