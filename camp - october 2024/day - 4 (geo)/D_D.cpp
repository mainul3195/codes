#include <bits/stdc++.h>
using namespace std;
#define int long long
const double eps = 1e-9;
int sign(int x) { return (x > eps) - (x < -eps); }
struct PT
{
    int x, y;
    PT() { x = 0, y = 0; }
    PT(int x, int y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator-(const PT &a) const { return PT(x - a.x, y - a.y); }
    bool operator==(PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator!=(PT a) const { return !(*this == a); }
    bool operator<(PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator>(PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    int norm() { return sqrt(x * x + y * y); }
    int norm2() { return x * x + y * y; }
    PT perp() { return PT(-y, x); }
    int arg() { return atan2(y, x); }
};
inline int cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
vector<PT> convex_hull(vector<PT> &p)
{
    if (p.size() <= 1)
        return p;
    vector<PT> v = p;
    sort(v.begin(), v.end());
    vector<PT> up, dn;
    for (auto &p : v)
    {
        while (up.size() > 1 && orientation(up[up.size() - 2], up.back(), p) >= 0)
        {
            up.pop_back();
        }
        while (dn.size() > 1 && orientation(dn[dn.size() - 2], dn.back(), p) <= 0)
        {
            dn.pop_back();
        }
        up.push_back(p);
        dn.push_back(p);
    }
    v = dn;
    if (v.size() > 1)
        v.pop_back();
    reverse(up.begin(), up.end());
    up.pop_back();
    for (auto &p : up)
    {
        v.push_back(p);
    }
    if (v.size() == 2 && v[0] == v[1])
        v.pop_back();
    return v;
}

// -1 if strictly inside, 0 if on the polygon, 1 if strictly outside
// it must be strictly convex, otherwise make it strictly convex first
int is_point_in_convex(vector<PT> &p, const PT &x)
{ // O(log n)
    int n = p.size();
    if (n < 3)
        return 1;
    int a = orientation(p[0], p[1], x), b = orientation(p[0], p[n - 1], x);
    if (a < 0 || b > 0)
        return 1;
    int l = 1, r = n - 1;
    while (l + 1 < r)
    {
        int mid = (l + r) >> 1;
        if (orientation(p[0], p[mid], x) >= 0)
            l = mid;
        else
            r = mid;
    }
    int k = orientation(p[l], p[r], x);
    if (k <= 0)
        return -k;
    if (l == 1 && a == 0)
        return 0;
    if (r == n - 1 && b == 0)
        return 0;
    return -1;
}
long long get_area(vector<PT> &p)
{
    long long ans = 0;
    int n = p.size();
    if (n < 3)
        return 0;
    for (int i = 0; i < n; i++)
        ans += cross(p[i], p[(i + 1) % n]);
    return abs(ans);
}
long long seed1, seed2;
long long get_random()
{
    seed1 = (seed1 * 1103515243 + 12345) % 2012345671;
    seed2 = (seed2 * 1092104927 + 54321) % 2094828103;
    return (seed1 * seed2) % 100000;
}
void solve()
{
    int n;
    cin >> n >> seed1 >> seed2;
    vector<PT> v;
    long long area = 0, tot_area = 0;
    for (int i = 0; i < n; i++)
    {
        int x = get_random();
        int y = get_random();
        auto p = PT(x, y);
        if (is_point_in_convex(v, p) <= 0)
            tot_area += area;
        else
        {
            v.push_back(p);
            v = convex_hull(v);
            area = get_area(v);
            tot_area += area;
        }
    }
    cout << tot_area << "\n";
    return;
}

int32_t main()
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