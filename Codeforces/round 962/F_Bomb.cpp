#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<long long> a, b;
bool possible(int x)
{
    long long tot = 0;
    for (int i = 0; i < n; i++)
        if (x <= a[i])
            tot += max(0LL, a[i] - x + b[i] - 1) / b[i];
    // cout << x << " -> " << tot << "\n";
    return tot < k;
}
void solve()
{
    cin >> n >> k;
    a = b = vector<long long>(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    long long l = 0, r = 0, mid, stop;
    for (auto i : a)
        r = max(r, i);
    // cout << "l = " << l << "\tr = " << r << "\n";
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (possible(mid))
        {
            stop = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    // cout << stop << "\n";
    long long ans = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > stop)
        {
            long long t = (a[i] - stop + b[i] - 1) / b[i];
            // cout << i << " : " << a[i] << " : " << t << "\n";
            ans += t * (2 * a[i] - (t - 1) * b[i]) / 2;
        }
    // cout << " before -> " << ans << "\n";
    long long mn = 2000000000;
    for (int i = 0; i < n; i++)
        if (stop <= a[i])
            mn = min(mn, (b[i] - (a[i] - stop) % b[i]) % b[i]);
    // cout << "mn = " << mn << "\n";
    long long tot = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > stop)
            tot += (a[i] - stop + b[i] - 1) / b[i];
    // cout << "tot = " << tot << "\n";
    stop -= mn;
    stop = max(0LL, stop);
    ans += (k - tot) * stop;
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