#include <bits/stdc++.h>
using namespace std;
int n, q;
pair<long long, long long> find1(long long r, long long d, long long val)
{
    // cout << "find1(" << r << ", " << d << ", " << val << ")\n";
    if (r == 1)
        return {1, 1};
    if (val < d)
    {
        return find1(r / 2, d / 4, val);
    }
    if (val < 2 * d)
    {
        auto p = find1(r / 2, d / 4, val - d);
        return {r / 2 + p.first, r / 2 + p.second};
    }
    if (val < 3 * d)
    {
        auto p = find1(r / 2, d / 4, val - 2 * d);
        return {r / 2 + p.first, p.second};
    }
    else
    {
        auto p = find1(r / 2, d / 4, val - 3 * d);
        return {p.first, r / 2 + p.second};
    }
}
long long find2(long long s, long long d, long long l, long long r)
{
    if (s == 1)
        return 1;
    if ((l <= s / 2) && (r <= s / 2))
    {
        return find2(s / 2, d / 4, l, r);
    }
    if ((l > s / 2) && (r > s / 2))
    {
        return d + find2(s / 2, d / 4, l - s / 2, r - s / 2);
    }
    if ((l > s / 2) && (r <= s / 2))
    {
        return 2 * d + find2(s / 2, d / 4, l - s / 2, r);
    }
    else
    {
        return 3 * d + find2(s / 2, d / 4, l, r - s / 2);
    }
}
void solve()
{
    cin >> n >> q;
    char c1, c2;
    while (q--)
    {
        cin >> c1 >> c2;
        if (c1 == '<')
        {
            long long val;
            cin >> val;
            val--;
            auto p = find1((1LL << n), (1LL << (2 * n - 2)), val);
            cout << p.first << " " << p.second << "\n";
        }
        else
        {
            long long l, r;
            cin >> l >> r;
            cout << find2((1LL << n), (1LL << (2 * n - 2)), l, r) << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}