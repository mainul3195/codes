#include <bits/stdc++.h>
using namespace std;
#define int long long
struct pt
{
    long long x, y;
};
int positive(pt a, pt b, pt c)
{
    long long val = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}
bool point_in_triangle(pt a, pt b, pt c, pt d)
{
    if ((positive(a, b, d) == positive(b, c, d)) &&
        (positive(b, c, d) == positive(c, a, d)) &&
        (positive(c, a, d) == positive(a, b, d)))
        return 1;
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    vector<pt> v(n);
    for (auto &[x, y] : v)
        cin >> x >> y;
    for (int i = 0; i < n; i++)
        v.push_back(v[i]);
    for (int i = 0; i < n; i++)
        v.push_back(v[i]);
    int t;
    cin >> t;
    while (t--)
    {
        pt c;
        cin >> c.x >> c.y;
        if (n == 3)
        {
            if (point_in_triangle(v[0], v[1], v[2], c))
                cout << "1\n";
            else
                cout << "0\n";
            continue;
        }
        long long ans = 0, minant = 0;
        for (int i = 0; i < n; i++)
        {
            pt a = v[i];
            pt b = v[i + 1];
            int l = i + 1, r = i + n - 1, mid, lft = 100000000;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (positive(a, v[mid], c) > 0)
                    r = mid - 1;
                else
                {
                    lft = mid;
                    l = mid + 1;
                }
            }
            l = i + 2, r = i + n;
            int rght = -1;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (positive(b, v[mid], c) > 0)
                    r = mid - 1, rght = mid;
                else
                    l = mid + 1;
            }
            if (rght > lft)
                ans += rght - lft - 1;
        }
        for (int i = 0; i < n; i++)
            minant += point_in_triangle(v[i], v[i + 1], v[i + 2], c);
        cout << ans - minant << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}