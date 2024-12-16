#include <bits/stdc++.h>
using namespace std;
vector<int> bit;
int n, q;
void upd(int ind)
{
    for (int i = ind; i <= n; i += (i & (-i)))
        bit[i]++;
    return;
}
int query(int ind)
{
    int ans = 0;
    for (int i = ind; i > 0; i -= (i & (-i)))
        ans += bit[i];
    return ans;
}
void solve()
{
    cin >> n >> q;
    bit = vector<int>(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
            upd(i);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        long long odds = query(r) - query(l - 1);
        long long even = (r - l + 1) - odds;
        long long ans = 0;
        if (even >= 3)
            ans += even * (even - 1) * (even - 2) / 6;
        if (odds >= 2)
            ans += odds * (odds - 1) / 2 * even;
        cout << ans << "\n";
    }
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