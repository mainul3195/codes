#include <bits/stdc++.h>
using namespace std;
long long egcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

void solve()
{
    long long x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    long long a = y2 - y1;
    long long b = x1 - x2;
    long long c = gcd(abs(x2 - x1), abs(y2 - y1)) - x2 * y1 + x1 * y2;
    // cout << "here -> " << a << " " << b << " " << c << "\n";
    if (c < 0)
        a *= -1, b *= -1, c *= -1;
    long long x0, y0, g;
    g = egcd(abs(a), abs(b), x0, y0);
    x0 = (c / g) * x0;
    y0 = (c / g) * y0;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    // cout << x0 << " " << y0 << "\n";
    for (int i = 0; i < k; i++)
    {
        x0 = x0 + b / g;
        y0 = y0 - a / g;
        cout << x0 << " " << y0 << "\n";
    }
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