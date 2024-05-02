#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v, solid, janina;
vector<vector<long long>> dp, path;
long long okdone(int l = 0, int r = n - 1)
{
    if (l > r)
        return 0;
    if (l == r)
        return max(1LL, v[l]);
    if (~dp[l][r])
        return dp[l][r];
    long long ans = (r - l + 1) * (r - l + 1);
    path[l][r] = 20;
    for (int i = l; i <= r; i++)
    {
        long long tmp = okdone(l, i - 1) + v[i] + okdone(i + 1, r);
        if (tmp > ans)
            path[l][r] = i;
        ans = max(ans, tmp);
    }
    return dp[l][r] = ans;
}
vector<pair<int, int>> range, operations;

void make_path(int l = 0, int r = n - 1)
{
    if (l > r)
        return;
    if (l == r)
    {
        if (v[l] >= 1)
            solid[l] = 1;
        else
            range.push_back({l, r});
        return;
    }
    if (path[l][r] == 20)
    {
        range.push_back({l, r});
        return;
    }
    else
    {
        solid[path[l][r]] = 1;
        make_path(l, path[l][r] - 1);
        make_path(path[l][r] + 1, r);
    }
    return;
}
void make_zero(int l, int r)
{
    int start = -1, end;
    for (int i = l; i <= r; i++)
    {
        if (v[i])
        {
            if (start == -1)
                start = i, end = i;
            else
                end = i;
        }
        else
        {
            if (start != -1)
                operations.push_back({start, end});
            start = -1;
        }
    }
    if (start != -1)
        operations.push_back({start, end});
    return;
}
void fill(int l, int r)
{
    if (l == r)
        return;
    fill(l, r - 1);
    operations.push_back({l, r});
    make_zero(l, r - 1);
    fill(l, r - 1);
    return;
}
void solve()
{
    cin >> n;
    v = solid = vector<long long>(n, 0);
    dp = path = vector<vector<long long>>(n + 2, vector<long long>(n + 2, -1));
    for (auto &i : v)
        cin >> i;
    int ans = okdone();
    make_path();

    for (auto [a, b] : range)
    {
        make_zero(a, b);
        fill(a, b);
        operations.push_back({a, b});
    }
    cout << ans << " " << operations.size() << "\n";
    for (auto [a, b] : operations)
        cout << a + 1 << " " << b + 1 << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}