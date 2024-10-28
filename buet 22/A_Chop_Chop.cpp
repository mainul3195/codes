#include <bits/stdc++.h>
using namespace std;
#define double long double
int n;

const int N = 3e5 + 9;

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
inline double cross2(PT a, PT b, PT c) { return cross(b - a, c - a); }
PT perp(PT a) { return PT(-a.y, a.x); }
inline double dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
inline double dist(PT a, PT b) { return sqrtl(dot(a - b, a - b)); }

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

int seg_line_relation(PT a, PT b, PT c, PT d)
{
    double p = cross2(c, d, a);
    double q = cross2(c, d, b);
    if (sign(p) == 0 && sign(q) == 0)
        return 2;
    else if (p * q < 0)
        return 1;
    else
        return 0;
}
// intersection between segament ab and line cd assuming unique intersection exists
bool seg_line_intersection(PT a, PT b, PT c, PT d, PT &ans)
{
    bool k = seg_line_relation(a, b, c, d);
    assert(k != 2);
    if (k)
        line_line_intersection(a, b, c, d, ans);
    return k;
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
double polygon_line_intersection(vector<PT> p, PT a, PT b, int i, int j)
{
    double ans = 0;
    int l = j, r = i + n - 1, mid, a1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (orientation(a, b, p[mid]) <= 0)
        {
            a1 = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    l = j + 1, r = i + n;
    int a2;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (orientation(a, b, p[mid]) >= 0)
        {
            a2 = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (a1 == a2)
        return dist(a, p[a1]);

    PT inter;
    seg_line_intersection(p[a1], p[a2], a, b, inter);
    return dist(a, inter);
}

// int n = p.size();
// p.push_back(p[0]);
// line l = line(a, b);
// double ans = 0.0;
// vector<pair<double, int>> vec;
// for (int i = 0; i < n; i++)
// {
//     int s1 = orientation(a, b, p[i]);
//     int s2 = orientation(a, b, p[i + 1]);
//     if (s1 == s2)
//         continue;
//     line t = line(p[i], p[i + 1]);
//     PT inter = (t.v * l.c - l.v * t.c) / cross(l.v, t.v);
//     double tmp = dot(inter, l.v);
//     int f;
//     if (s1 > s2)
//         f = s1 && s2 ? 2 : 1;
//     else
//         f = s1 && s2 ? -2 : -1;
//     vec.push_back(make_pair((f > 0 ? tmp - eps : tmp + eps), f)); // keep eps very small like 1e-12
// }
// sort(vec.begin(), vec.end());
// for (int i = 0, j = 0; i + 1 < (int)vec.size(); i++)
// {
//     j += vec[i].second;
//     if (j)
//         ans += vec[i + 1].first - vec[i].first; // if this portion is inside the polygon
//     // else ans = 0; // if we want the maximum intersected length which is totally inside the polygon, uncomment this and take the maximum of ans
// }
// ans = ans / sqrt(dot(l.v, l.v));
// p.pop_back();

vector<PT> points;

PT centroid()
{
    int n = points.size();
    PT c(0, 0);
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += cross(points[i], points[(i + 1) % n]);
    double scale = 3.0 * sum;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        c = c + (points[i] + points[j]) * cross(points[i], points[j]);
    }
    return c / scale;
}
// find a point from a through b with distance d
PT point_along_line(PT a, PT b, double d)
{
    assert(a != b);
    return a + (((b - a) / (b - a).norm()) * d);
}
void solve()
{
    cin >> n;
    points = vector<PT>(n);
    for (auto &[x, y] : points)
        cin >> x >> y;
    auto c = centroid();
    double ans = 1e15;
    for (int i = 0; i < n; i++)
        points.push_back(points[i]);
    for (int i = 0; i < n; i++)
    {
        PT a = points[i];
        PT b = points[(i + 1) % n];
        int count = 40;
        double l = 0, r = dist(a, b), m1, m2;

        while (count--)
        {
            m1 = l + (r - l) / 3;
            m2 = r - (r - l) / 3;
            PT p1 = point_along_line(a, b, m1);
            PT p2 = point_along_line(a, b, m2);
            double d1 = polygon_line_intersection(points, p1, c, i, i + 1);
            double d2 = polygon_line_intersection(points, p2, c, i, i + 1);
            if (d1 > d2)
                l = m1;
            else
                r = m2;
        }
        ans = min(ans, polygon_line_intersection(points, point_along_line(a, b, l), c, i, i + 1));
    }
    double perimeter = 0;
    for (int i = 0; i < n; i++)
        perimeter += dist(points[i], points[(i + 1) % n]);
    cout << fixed << setprecision(10) << perimeter + 2 * ans << "\n";
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