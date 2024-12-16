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

inline double dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline double dist2(PT a, PT b) { return dot(a - b, a - b); }
inline double dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
PT perp(PT a) { return PT(-a.y, a.x); }

PT rotatecw90(PT a) { return PT(a.y, -a.x); }
bool line_line_intersection(PT a, PT b, PT c, PT d, PT &ans)
{
    double a1 = a.y - b.y, b1 = b.x - a.x, c1 = cross(a, b);
    double a2 = c.y - d.y, b2 = d.x - c.x, c2 = cross(c, d);
    double det = a1 * b2 - a2 * b1;
    if (det == 0)
        return 0;
    ans = PT((b1 * c2 - b2 * c1) / det, (c1 * a2 - a1 * c2) / det);
    return 1;
}
struct line
{
    PT a, b; // goes through points a and b
    PT v;
    double c; // line form: direction vec [cross] (x, y) = c
    line() {}
    // direction vector v and offset c
    line(PT v, double c) : v(v), c(c)
    {
        auto p = get_points();
        a = p.first;
        b = p.second;
    }
    // equation ax + by + c = 0
    line(double _a, double _b, double _c) : v({_b, -_a}), c(-_c)
    {
        auto p = get_points();
        a = p.first;
        b = p.second;
    }
    // goes through points p and q
    line(PT p, PT q) : v(q - p), c(cross(v, p)), a(p), b(q) {}
    pair<PT, PT> get_points()
    { // extract any two points from this line
        PT p, q;
        double a = -v.y, b = v.x; // ax + by = c
        if (sign(a) == 0)
        {
            p = PT(0, c / b);
            q = PT(1, c / b);
        }
        else if (sign(b) == 0)
        {
            p = PT(c / a, 0);
            q = PT(c / a, 1);
        }
        else
        {
            p = PT(0, c / b);
            q = PT(1, (c - a) / b);
        }
        return {p, q};
    }
    // ax + by + c = 0
    array<double, 3> get_abc()
    {
        double a = -v.y, b = v.x;
        return {a, b, -c};
    }
    // 1 if on the left, -1 if on the right, 0 if on the line
    int side(PT p) { return sign(cross(v, p) - c); }
    // line that is perpendicular to this and goes through point p
    line perpendicular_through(PT p) { return {p, p + perp(v)}; }
    // translate the line by vector t i.e. shifting it by vector t
    line translate(PT t) { return {v, c + cross(v, t)}; }
    // compare two points by their orthogonal projection on this line
    // a projection point comes before another if it comes first according to vector v
    bool cmp_by_projection(PT p, PT q) { return dot(v, p) < dot(v, q); }
    line shift_left(double d)
    {
        PT z = v.perp().truncate(d);
        return line(a + z, b + z);
    }
};
PT project_from_point_to_seg(PT a, PT b, PT c)
{
    double r = dist2(a, b);
    if (sign(r) == 0)
        return a;
    r = dot(c - a, b - a) / r;
    if (r < 0)
        return a;
    if (r > 1)
        return b;
    return a + (b - a) * r;
}
double dist_from_point_to_seg(PT a, PT b, PT c)
{
    return dist(c, project_from_point_to_seg(a, b, c));
}
struct circle
{
    PT p;
    double r;
    circle() {}
    circle(PT _p, double _r) : p(_p), r(_r) {};
    // center (x, y) and radius r
    circle(double x, double y, double _r) : p(PT(x, y)), r(_r) {};
    // circumcircle of a triangle
    // the three points must be unique
    circle(PT a, PT b, PT c)
    {
        b = (a + b) * 0.5;
        c = (a + c) * 0.5;
        line_line_intersection(b, b + rotatecw90(a - b), c, c + rotatecw90(a - c), p);
        r = dist(a, p);
    }
    // inscribed circle of a triangle
    // pass a bool just to differentiate from circumcircle
    circle(PT a, PT b, PT c, bool t)
    {
        line u, v;
        double m = atan2(b.y - a.y, b.x - a.x), n = atan2(c.y - a.y, c.x - a.x);
        u.a = a;
        u.b = u.a + (PT(cos((n + m) / 2.0), sin((n + m) / 2.0)));
        v.a = b;
        m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
        v.b = v.a + (PT(cos((n + m) / 2.0), sin((n + m) / 2.0)));
        line_line_intersection(u.a, u.b, v.a, v.b, p);
        r = dist_from_point_to_seg(a, b, p);
    }
    bool operator==(circle v) { return p == v.p && sign(r - v.r) == 0; }
    double area() { return PI * r * r; }
    double circumference() { return 2.0 * PI * r; }
};
circle minimum_enclosing_circle(vector<PT> &p)
{
    random_shuffle(p.begin(), p.end());
    int n = p.size();
    circle c(p[0], 0);
    for (int i = 1; i < n; i++)
    {
        if (sign(dist(c.p, p[i]) - c.r) > 0)
        {
            c = circle(p[i], 0);
            for (int j = 0; j < i; j++)
            {
                if (sign(dist(c.p, p[j]) - c.r) > 0)
                {
                    c = circle((p[i] + p[j]) / 2, dist(p[i], p[j]) / 2);
                    for (int k = 0; k < j; k++)
                    {
                        if (sign(dist(c.p, p[k]) - c.r) > 0)
                        {
                            c = circle(p[i], p[j], p[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}
void solve()
{
    int n, R, r;
    cin >> n >> R >> r;
    int x = 0, y = 0;
    vector<PT> p;
    p.push_back(PT(0, 0));
    for (int i = 0; i < n; i++)
    {
        int dx, dy;
        cin >> dx >> dy;
        x += dx;
        y += dy;
        p.push_back(PT(x, y));
    }
    // for (auto [x, y] : p)
    //     cout << x << " " << y << "\n";
    circle c = minimum_enclosing_circle(p);
    cout << fixed << setprecision(10) << -c.p.x + eps << " " << -c.p.y + eps << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("robots.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}