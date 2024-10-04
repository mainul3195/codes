#include <bits/stdc++.h>
using namespace std;
#define eps 1e-12
struct pt
{
    double x, y;
};
bool positive(pt a, pt b, pt c)
{
    double val = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    return (val > 0);
}
bool point_in_triangle(pt a, pt b, pt c, pt d)
{
    if ((positive(a, b, d) == positive(b, c, d)) &&
        (positive(b, c, d) == positive(c, a, d)) &&
        (positive(c, a, d) == positive(a, b, d)))
        return 1;
    return 0;
}
// // double cross()
double dot(pt a, pt b)
{
    return a.x * b.x + a.y * b.y;
}
double dist(pt a)
{
    // return sqrt((b.y - a.y) * (b.y - a.y) + (b.x - a.x) * (b.x - a.x));
    return sqrt(a.x * a.x + a.y * a.y);
}
double angle(pt a1, pt a2, pt b1, pt b2)
{
    pt a, b;
    a.x = a2.x - a1.x;
    a.y = a2.y - a1.y;
    b.x = b2.x - b1.x;
    b.y = b2.y - b1.y;
    return acos(dot(a, b) / (dist(a) * dist(b)));
}
double cross(pt a, pt b)
{
    return a.x * b.y - a.y * b.x;
}
bool possible(pt a1, pt a2, pt b1, pt b2, pt c1, pt c2)
{
    double tot = angle(a2, a1, b1, b2) + angle(b2, b1, c1, c2) + angle(c2, c1, a1, a1);
    if (tot + eps > (2 * acos(0.0)))
        return 0;
    return 1;
}
pt intersection(pt a, pt b, pt c, pt d)
{
    double a1 = a.y - b.y, b1 = b.x - a.x, c1 = cross(a, b);
    double a2 = c.y - d.y, b2 = d.x - c.x, c2 = cross(c, d);
    double det = a1 * b2 - a2 * b1;
    pt ans;
    ans.x = (b1 * c2 - b2 * c1) / det + eps;
    ans.y = (c1 * a2 - a1 * c2) / det + eps;
    return ans;
}
double pdist(pt a, pt b)
{
    return sqrt((b.y - a.y) * (b.y - a.y) + (b.x - a.x) * (b.x - a.x));
}
void solve()
{
    int n;
    while (cin >> n && n)
    {
        vector<pt> v(n);
        for (auto &[x, y] : v)
            cin >> x >> y;
        v.push_back(v[0]);
        double ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    if (possible(v[i], v[i + 1], v[j], v[j + 1], v[k], v[k + 1]))
                    {
                        pt a = intersection(v[i], v[i + 1], v[j], v[j + 1]);
                        pt b = intersection(v[j], v[j + 1], v[k], v[k + 1]);
                        pt c = intersection(v[i], v[i + 1], v[k], v[k + 1]);
                        // cout << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y << "\n";
                        double d1 = pdist(a, b);
                        double d2 = pdist(b, c);
                        double d3 = pdist(c, a);
                        double s = (d1 + d2 + d3) / 2;
                        // cout << d1 << " " << d1 << " " << d3 << " " << s << "\n";
                        double r = pdist(a, b) * pdist(b, c) * sin(angle(b, a, b, c)) / (2 * s);
                        // cout << r << "\n";
                        ans = max(ans, r);
                    }
        cout << ans << "\n";
    }
    // pt a, b;
    // a.x = 0, a.y = 0;
    // b.x = b.y = 1;
    // pt ab, ba;
    // ab.x = b.x - a.x;
    // ab.y = b.y - a.y;
    // ba.x = a.x - b.x;
    // ba.y = a.y - b.y;
    // cout << dist(a, b) << "\n";
    // cout << acos(dot(ab, ba) / (dist(a, b) * dist(b, a))) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}