#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;
long long mx, mn;
bool possible(long long x, long long a)
{
    vector<long long> tmp = v;
    vector<bool> modified(n, 0);
    long long nw_mn = mn + a;

    for (int i = 0; i < n; i++)
    {

        if (tmp[i] + a <= mx)
            tmp[i] += a, modified[i] = 1;

        if (tmp[i] < nw_mn)
            return false;
    }
    if (v[0] >= nw_mn)
        modified[0] = 0;
    for (int i = 1; i < n; i++)
        if ((v[i] >= nw_mn) && (modified[i - 1] == 0))
            modified[i] = 0;
    if (v[n - 1] >= nw_mn)
        modified[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        if ((v[i] >= nw_mn) && (modified[i + 1] == 0))
            modified[i] = 0;

    for (int i = 0; i < n; i++)
    {
        if (modified[i])
        {
            while ((i < n) && modified[i])
            {
                modified[i] = 0;
                i++;
            }
            break;
        }
    }
    for (auto i : modified)
        if (i)
            return false;
    return true;
}

bool possible2(long long x, long long a)
{
    vector<long long> tmp = v;
    vector<bool> modified(n, 0);
    long long nw_mx = mx - a;

    for (int i = 0; i < n; i++)
    {

        if (tmp[i] - a >= mn)
            tmp[i] -= a, modified[i] = 1;

        if (tmp[i] > nw_mx)
            return false;
    }

    if (v[0] <= nw_mx)
        modified[0] = 0;
    for (int i = 1; i < n; i++)
        if ((v[i] <= nw_mx) && (modified[i - 1] == 0))
            modified[i] = 0;
    if (v[n - 1] <= nw_mx)
        modified[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        if ((v[i] <= nw_mx) && (modified[i + 1] == 0))
            modified[i] = 0;

    for (int i = 0; i < n; i++)
    {
        if (modified[i])
        {
            while ((i < n) && modified[i])
            {
                modified[i] = 0;
                i++;
            }
            break;
        }
    }
    for (auto i : modified)
        if (i)
            return false;
    return true;
}
void solve()
{
    cin >> n;
    v = vector<long long>(n);
    for (auto &i : v)
        cin >> i;
    mx = -10000000000000LL, mn = 20000000000000LL;
    for (auto i : v)
        mx = max(mx, i), mn = min(mn, i);
    long long l = 0, r = mx - mn, dif, ans = mx - mn;
    while (l <= r)
    {
        dif = (l + r) / 2;
        if (possible(dif, mx - mn - dif))
        {
            ans = min(dif, ans);
            r = dif - 1;
        }
        else
            l = dif + 1;
    }
    l = 0, r = mx - mn, dif;
    while (l <= r)
    {
        dif = (l + r) / 2;
        if (possible2(dif, mx - mn - dif))
        {
            ans = min(dif, ans);
            r = dif - 1;
        }
        else
            l = dif + 1;
    }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}