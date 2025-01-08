#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    long long tot = a + b + c;
    long long rem = n % tot;
    long long ans = n / tot * 3;
    if (rem)
    {
        rem -= a;
        ans++;
        if (rem > 0)
        {
            rem -= b;
            ans++;
            if (rem > 0)
                ans++;
        }
    }
    cout << ans << "\n";
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