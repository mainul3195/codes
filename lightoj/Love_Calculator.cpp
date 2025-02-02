#include <bits/stdc++.h>
using namespace std;

string a, b;
pair<long long, long long> dp[35][35];
pair<long long, long long> okdone(int i, int j)
{
    if (i == a.size() || j == b.size())
        return {0, 1};
    auto &ret = dp[i][j];
    if (~ret.first)
        return ret;

    if (a[i] == b[j])
    {
        auto p = okdone(i + 1, j + 1);
        ret.first = p.first + 1;
        ret.second = p.second;
        return ret;
    }
    auto p = okdone(i, j + 1);
    auto q = okdone(i + 1, j);
    if (p.first > q.first)
        return ret = p;
    if (p.first < q.first)
        return ret = q;
    ret.first = p.first;
    ret.second = p.second + q.second;
    return ret;
}
void solve()
{
    cin >> a >> b;
    for (int i = 0; i < 35; i++)
        for (int j = 0; j < 35; j++)
            dp[i][j] = {-1, -1};
    auto p = okdone(0, 0);
    cout << a.size() + b.size() - p.first << " " << p.second << "\n";
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