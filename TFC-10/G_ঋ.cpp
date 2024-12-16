#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
void solve()
{
    int n;
    long long L = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        L = lcm(L, x);
    }
    cout << L * 35 << "\n";
    return;
}
int main()
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