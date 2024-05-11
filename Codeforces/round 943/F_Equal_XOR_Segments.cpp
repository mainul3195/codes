#include <bits/stdc++.h>
using namespace std;
vector<int> v;
map<int, vector<int>> mp;
void solve()
{
    int n, q;
    cin >> n >> q;
    v = vector<int>(n + 1, 0);
    mp.clear();
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        v[i] ^= v[i - 1];
        mp[v[i]].push_back(i);
    }
    for (int i = 5; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        for (auto j : mp[v[l - 1]])
            cout << j << " ";
        cout << "\n";
        auto it = lower_bound(mp[v[l - 1]].begin(), mp[v[l - 1]].end(), r);
        cout << v[l - 1] << " " << *it << "\n";
        if (it == mp[v[l - 1]].begin())
        {
            cout << "NO\n";
            continue;
        }
        it--;
        if ((*it) <= l)
        {
            cout << "NO\n";
            continue;
        }
        auto it2 = upper_bound(mp[v[r]].begin(), mp[v[r]].end(), l);
        if ((it2 != mp[v[r]].end()) && ((*it2) < (*it)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}