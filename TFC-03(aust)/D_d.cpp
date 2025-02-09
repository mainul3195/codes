#include <bits/stdc++.h>
using namespace std;

void solve()
{

    long long ax, ay, bx, by, d;
    cin >> ax >> ay >> bx >> by >> d;
    long long dis_squared = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    // cout << dis << " " << d << ""
    if ((d * d >= 4 * dis_squared) || (d == 0))
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    double dis = sqrt(dis_squared);
    double theta = acos((2 * dis * dis - d * d) / (2 * dis * dis));
    double X = ax - bx;
    double Y = ay - by;
    double x1 = X * cos(theta) - Y * sin(theta);
    double y1 = X * sin(theta) + Y * cos(theta);
    theta = theta * (-1);
    double x2 = X * cos(theta) - Y * sin(theta);
    double y2 = X * sin(theta) + Y * cos(theta);
    cout << fixed << setprecision(8) << x1 + bx << " " << y1 + by << " " << x2 + bx << " " << y2 + by << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}