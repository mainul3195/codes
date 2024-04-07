#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long okdone(int r, int c)
{
    if (r == c)
        return 0;
    if (r == 1)
        return c - 1;
    if (c == 1)
        return r - 1;
    if (~dp[r][c])
        return dp[r][c];
    long long mn = 2000000000;
    for (int i = 1; i + i <= r; i++)
        mn = min(mn, okdone(i, c) + okdone(r - i, c));
    for (int i = 1; i + i <= c; i++)
        mn = min(mn, okdone(r, i) + okdone(r, c - i));
    return dp[r][c] = mn + 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    dp = vector<vector<long long>>(a + 1, vector<long long>(b + 1, -1));
    cout << okdone(a, b) << '\n';
    return 0;
}