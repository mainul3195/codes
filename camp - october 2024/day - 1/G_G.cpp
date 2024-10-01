#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % mod;
    long long tmp = bigMod(b, p / 2);
    return (tmp * tmp) % mod;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    if (v[0] != 0)
    {
        cout << "0\n";
        return;
    }
    sort(v.rbegin(), v.rend());
    if (v.back() != 0)
    {
        cout << "0\n";
        return;
    }
    v.pop_back();
    int prev_node_count = 1;
    int cur_node_dis = 1;
    long long ans = 1;
    while (v.size())
    {
        if (v.back() != cur_node_dis)
        {
            cout << "0\n";
            return;
        }
        int cur_node_count = 0;
        while (v.size() && (v.back() == cur_node_dis))
        {
            cur_node_count++;
            v.pop_back();
        }
        ans = (ans * bigMod(prev_node_count, cur_node_count)) % mod;
        prev_node_count = cur_node_count;
        cur_node_dis++;
    }
    cout << ans << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}