#include <bits/stdc++.h>
using namespace std;
const double inf = 1e100;
const double eps = 1e-9;
const double PI = acos((double)-1.0);
int sign(double x) { return (x > eps) - (x < -eps); }
struct PT
{
    double x, y;
    PT() { x = 0, y = 0; }
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator+(const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator-(const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator*(const double a) const { return PT(x * a, y * a); }
    friend PT operator*(const double &a, const PT &b) { return PT(a * b.x, a * b.y); }
    PT operator/(const double a) const { return PT(x / a, y / a); }
    bool operator==(PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator!=(PT a) const { return !(*this == a); }
    bool operator<(PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator>(PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    PT perp() { return PT(-y, x); }
    double arg() { return atan2(y, x); }
    PT truncate(double r)
    { // returns a vector with norm r and having same direction
        double k = norm();
        if (!sign(k))
            return *this;
        r /= k;
        return PT(x * r, y * r);
    }
};
inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }

struct HP
{
    PT a, b;
    HP() {}
    HP(PT a, PT b) : a(a), b(b) {}
    HP(const HP &rhs) : a(rhs.a), b(rhs.b) {}
    int operator<(const HP &rhs) const
    {
        PT p = b - a;
        PT q = rhs.b - rhs.a;
        int fp = (p.y < 0 || (p.y == 0 && p.x < 0));
        int fq = (q.y < 0 || (q.y == 0 && q.x < 0));
        if (fp != fq)
            return fp == 0;
        if (cross(p, q))
            return cross(p, q) > 0;
        return cross(p, rhs.b - a) < 0;
    }
    PT line_line_intersection(PT a, PT b, PT c, PT d)
    {
        b = b - a;
        d = c - d;
        c = c - a;
        return a + b * cross(c, d) / cross(b, d);
    }
    PT intersection(const HP &v)
    {
        return line_line_intersection(a, b, v.a, v.b);
    }
};
int check(HP a, HP b, HP c)
{
    return cross(a.b - a.a, b.intersection(c) - a.a) > -eps; //-eps to include polygons of zero area (straight lines, points)
}
vector<PT> half_plane_intersection(vector<HP> h)
{
    sort(h.begin(), h.end());
    vector<HP> tmp;
    for (int i = 0; i < h.size(); i++)
    {
        if (!i || cross(h[i].b - h[i].a, h[i - 1].b - h[i - 1].a))
        {
            tmp.push_back(h[i]);
        }
    }
    h = tmp;
    vector<HP> q(h.size() + 10);
    int qh = 0, qe = 0;
    for (int i = 0; i < h.size(); i++)
    {
        while (qe - qh > 1 && !check(h[i], q[qe - 2], q[qe - 1]))
            qe--;
        while (qe - qh > 1 && !check(h[i], q[qh], q[qh + 1]))
            qh++;
        q[qe++] = h[i];
    }
    while (qe - qh > 2 && !check(q[qh], q[qe - 2], q[qe - 1]))
        qe--;
    while (qe - qh > 2 && !check(q[qe - 1], q[qh], q[qh + 1]))
        qh++;
    vector<HP> res;
    for (int i = qh; i < qe; i++)
        res.push_back(q[i]);
    vector<PT> hull;
    if (res.size() > 2)
    {
        for (int i = 0; i < res.size(); i++)
        {
            hull.push_back(res[i].intersection(res[(i + 1) % ((int)res.size())]));
        }
    }
    return hull;
}
double maximum_inscribed_circle(vector<PT> p)
{
    int n = p.size();
    if (n <= 2)
        return 0;
    double l = 0, r = 20000;
    while (r - l > eps)
    {
        double mid = (l + r) * 0.5;
        vector<HP> h;
        const int L = 1e9;
        h.push_back(HP(PT(-L, -L), PT(L, -L)));
        h.push_back(HP(PT(L, -L), PT(L, L)));
        h.push_back(HP(PT(L, L), PT(-L, L)));
        h.push_back(HP(PT(-L, L), PT(-L, -L)));
        for (int i = 0; i < n; i++)
        {
            PT z = (p[(i + 1) % n] - p[i]).perp();
            z = z.truncate(mid);
            PT y = p[i] + z, q = p[(i + 1) % n] + z;
            h.push_back(HP(p[i] + z, p[(i + 1) % n] + z));
        }
        vector<PT> nw = half_plane_intersection(h);
        if (!nw.empty())
            l = mid;
        else
            r = mid;
    }
    return l;
}
void solve()
{
    int n;
    while (cin >> n && n)
    {
        vector<PT> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        cout << fixed << setprecision(10) << maximum_inscribed_circle(p) << "\n";
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