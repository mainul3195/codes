#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long dist;
    int x, y;
    long long cur, mx;
    bool operator<(const nd &a) const
    {
        return dist > a.dist;
    }
};
vector<vector<long long>> p, r, dwn;
int n;
void solve()
{
    cin >> n;
    p = vector<vector<long long>>(n, vector<long long>(n));
    r = vector<vector<long long>>(n, vector<long long>(n - 1));
    dwn = vector<vector<long long>>(n - 1, vector<long long>(n));
    for (auto &v : p)
        for (auto &i : v)
            cin >> i;
    for (auto &v : r)
        for (auto &i : v)
            cin >> i;
    for (auto &v : dwn)
        for (auto &i : v)
            cin >> i;
    priority_queue<nd> q;
    q.push({0, 0, 0, 0, p[0][0]});
    long long ans = 1000000000000000000LL;
    while (q.size())
    {
        auto [d, x, y, bal, mx] = q.top();
        if (x == n - 1 && y == n - 1)
            ans = min(ans, d);
        q.pop();
        if (y < n - 1)
        {
            if (r[x][y] <= bal)
                q.push({d + 1, x, y + 1, bal - r[x][y]});
            else
            {
                long long need = r[x][y] - bal;
                long long stay = (need + mx - 1) / mx;
                q.push({d + stay + 1, x, y + 1, bal + stay * mx - r[x][y], max(mx, p[x][y + 1])});
            }
        }
        if (x < n - 1)
        {
            if (dwn[x][y] <= bal)
                q.push({d + 1, x + 1, y, bal - dwn[x][y]});
            else
            {
                long long need = dwn[x][y] - bal;
                long long stay = (need + mx - 1) / mx;
                q.push({d + stay + 1, x + 1, y, bal + stay * mx - dwn[x][y], max(mx, p[x + 1][y])});
            }
        }
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}