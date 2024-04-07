#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000000000
int n, m;
void solve()
{
    cin >> n >> m;
    map<pair<int, int>, long long> mp;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (mp.count({u, v}))
            mp[{u, v}] = max(mp[{u, v}], (long long)w);
        else
            mp[{u, v}] = w;
    }
    vector<tuple<int, int, long long>> v;
    for (auto it = mp.begin(); it != mp.end(); it++)
        v.push_back({(*it).first.first, (*it).first.second, (*it).second});
    vector<long long> dis(n + 1, -inf);
    dis[1] = 0;
    for (int i = 1; i < n; i++)
        for (auto [a, b, w] : v)
            if (dis[a] != -inf)
                dis[b] = max(dis[b], dis[a] + w);

    long long dis_n = dis[n];
    for (int i = 1; i < n; i++)
        for (auto [a, b, w] : v)
            if (dis[a] != -inf)
                if (dis[b] < dis[a] + w)
                    dis[b] = inf;
    if (dis_n == dis[n])
        cout << dis[n] << "\n";
    else
        cout << "-1\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}