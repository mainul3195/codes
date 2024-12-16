#include <bits/stdc++.h>
using namespace std;
int n;
vector<double> prob;
double dp[101][101];
double sum(int l, int r)
{
    if (l > r)
        return 0;
    return prob[r] - prob[l - 1];
}
double okdone(int i, int j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    double ans = 1000000000;
    for (int k = i; k <= j; k++)
        ans = min(ans, okdone(i, k - 1) + sum(i, k - 1) + sum(k, k) + okdone(k + 1, j) + sum(k + 1, j));
    // cout << i << " -> " << j << ": " << ans << "\n";
    return dp[i][j] = ans;
}
void solve()
{
    while (cin >> n)
    {
        prob = vector<double>(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> prob[i];
        for (int i = 2; i <= n; i++)
            prob[i] += prob[i - 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;
        cout << fixed << setprecision(4) << okdone(1, n) << "\n";
        ;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}