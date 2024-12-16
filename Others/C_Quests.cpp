#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    for (int i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
        b[i] = max(b[i], b[i - 1]);
    }
    long long ans = 0;
    for (int i = 0; i < n && i < k; i++)
        ans = max(ans, a[i] + b[i] * (k - i - 1));
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