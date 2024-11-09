#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;
    double s = (a + b + c) / 2.0;
    long long up = (s - a) * (s - b) * (s - c) * 8 + .0000000001;
    long long down = s * 8 + .000000001;
    long long g = gcd(up, down);
    cout << up / g << "/" << down / g << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}