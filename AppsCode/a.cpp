#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<long long> temperature(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> temperature[i];
        temperature[i] += temperature[i - 1];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << fixed << setprecision(2) << (double)(temperature[r] - temperature[l - 1]) / (r - l + 1) << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}