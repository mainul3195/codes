#include <bits/stdc++.h>
using namespace std;
vector<long long> a, c;
long long h, n;
bool possible(long long x)
{
    long long sum = 0;
    for (auto i : a)
        sum += i;
    if (sum >= h)
        return 1;
    for (int i = 0; i < n; i++)
    {
        sum += ((x - 1) / c[i] * a[i]);
        if (sum >= h)
            return 1;
    }
    return 0;
}
void solve()
{
    cin >> h >> n;
    a = c = vector<long long>(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : c)
        cin >> i;
    long long l = 1, r = 10000000000000LL, mid, ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (possible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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