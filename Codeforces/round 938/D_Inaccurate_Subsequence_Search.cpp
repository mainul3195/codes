#include <bits/stdc++.h>
using namespace std;

void solve()
{
    map<int, int> bhas, wehave;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        bhas[x]++;
    }
    int matched = 0;
    for (int i = 0; i < m; i++)
    {
        wehave[v[i]]++;
        if (wehave[v[i]] <= bhas[v[i]])
            matched++;
    }
    int ans = (matched >= k);
    for (int i = m; i < n; i++)
    {
        // cout << wehave[v[i-m]] << "\n";
        wehave[v[i - m]]--;
        // cout << wehave[v[i-m]] << " " << bhas[v[i-m]] << " " << matched << "\n";
        if (wehave[v[i - m]] < bhas[v[i - m]])
            matched--;
        // cout << matched << ": ";
        wehave[v[i]]++;
        if (wehave[v[i]] <= bhas[v[i]])
            matched++;
        // cout << v[i] << " -> " << matched << "\n";
        ans += (matched >= k);
    }
    cout << ans << "\n";
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