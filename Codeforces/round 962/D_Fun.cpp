#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x;
    cin >> n >> x;
    int lim = sqrt(n + .5);
    long long ans = 0;
    for (int i = 1; i <= lim; i++)
        for (int j = i; j <= lim; j++)
        {
            long long high = (n - i * j) / (i + j);
            high = min(high, x - i - j);
            if (high < j)
                break;
            // cout << i << " " << j << " " << high << "\n";
            if (i == j)
                ans += 3 * (high - j + 1) - 2;
            else
                ans += 6 * (high - j + 1) - 3;
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