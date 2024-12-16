#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}
void solve()
{
    long long a, b;
    cin >> a >> b;
    if (a == 1)
        cout << b * b << "\n";
    else if (a == 2)
        cout << a * b << "\n";
    else if (b % a == 0)
        cout << b * b / a << "\n";
    else
        cout << a * b / gcd(a, b) << "\n";
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