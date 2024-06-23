#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    long long tot = 0;
    long long mx = 0;
    int ans = 0;
    for (auto i : v)
    {
        tot += i;
        mx = max(i, mx);
        if (tot - mx == mx)
            ans++;
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