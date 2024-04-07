#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long dp[5003][5003];
long long okdone(int i, int j)
{
    if (i > j)
        return 0;
    if (~dp[i][j])
        return dp[i][j];
    return dp[i][j] = v[j] - v[i - 1] - min(okdone(i + 1, j), okdone(i, j - 1));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    v = vector<long long>(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i], v[i] += v[i - 1];
    memset(dp, -1, sizeof(dp));
    cout << okdone(1, n) << "\n";
    return 0;
}