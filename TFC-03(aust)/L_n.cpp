#include <bits/stdc++.h>
using namespace std;

struct pt
{
    long long x, y;
    pt()
    {
        x = y = 0;
    }
    pt(long long a, long long b)
    {
        x = a, y = b;
    }
    pt operator-(const pt a) const
    {
        return pt(x - a.x, y - a.y);
    }
    bool operator<(const pt a) const
    {
        return x < a.x || ((x == a.x) && (y < a.y));
    }
};
int sign(long long x)
{
    return (x > 0) - (x < 0);
}
long long cross(pt a, pt b)
{
    return a.x * b.y - a.y * b.x;
}
long long orientation(pt a, pt b, pt c)
{
    return sign(cross(b - a, c - a));
}

vector<pt> convex_hull(vector<pt> &p)
{
    if (p.size() <= 1)
        return p;
    vector<pt> v = p;
    sort(v.begin(), v.end());
    vector<pt> up, dn;
    for (auto &p : v)
    {
        while (up.size() > 1 && orientation(up[up.size() - 2], up.back(), p) >= 0)
            up.pop_back();
        while (dn.size() > 1 && orientation(dn[dn.size() - 2], dn.back(), p) <= 0)
            dn.pop_back();
        up.push_back(p);
        dn.push_back(p);
    }
    v = dn;
    if (v.size() > 1)
        v.pop_back();
    reverse(up.begin(), up.end());
    up.pop_back();
    for (auto &p : up)
        v.push_back(p);
    if (v.size() == 2 && ((v[0].x == v[1].x) && (v[0].y == v[1].y)))
        v.pop_back();
    return v;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pt> points(n);
    for (auto &[x, y] : points)
        cin >> x >> y;
    map<int, pt> prev_ind;
    int ind = 0;

    for (auto p : points)
        prev_ind[ind++] = p;

    points = convex_hull(points);

    map<pt, int> new_ind;
    ind = 0;
    for (auto p : points)
        new_ind[p] = ind++;

    // for (auto [x, y] : points)
    //     cout << x << " " << y << "\n";
    vector<__int128_t> cum_sum;
    cum_sum.push_back(0);
    for (int i = 1; i < points.size(); i++)
        cum_sum.push_back(cross(points[i - 1], points[i]));
    cum_sum.push_back(cross(points[points.size() - 1], points[0]));
    for (int i = 1; i <= points.size(); i++)
        cum_sum.push_back(cum_sum[i]);

    // for (int i = 0; i < cum_sum.size(); i++)
    //     cout << i << " -> " << cum_sum[i] << "\n";
    for (int i = 1; i < cum_sum.size(); i++)
        cum_sum[i] += cum_sum[i - 1];
    __int128_t tot_area = cum_sum[points.size()];
    __int128_t ans = 0;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int c = new_ind[prev_ind[a]];
        int d = new_ind[prev_ind[b]];
        if (c > d)
            d += points.size();
        __int128_t area = cum_sum[d] - cum_sum[c] + cross(points[new_ind[prev_ind[b]]], points[new_ind[prev_ind[a]]]);
        ans = max(ans, min(area, tot_area - area));
    }
    long long fin_area = ans;
    cout << fin_area / 2;
    if (fin_area % 2 == 1)
        cout << ".5";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}