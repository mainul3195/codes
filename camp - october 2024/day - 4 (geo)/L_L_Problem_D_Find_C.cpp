#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
void solve()
{
    long long x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    long long a = y1-y2;
    long long b = x2-x1;
    long long c = gcd(abs(x2-x1), abs(y2-y1)) + x2*y1 - x1*y2;
    long long x0, y0, g;
    if (!find_any_solution(a, b, c, x0, y0, g)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << x0 << " " << y0 << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}