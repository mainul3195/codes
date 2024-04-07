#include <bits/stdc++.h>
using namespace std;
#define inf 100000000000000
int n, m, k;
vector<vector<pair<int, long long>>> adj;
vector<multiset<long long>> dist;
void solve()
{
    cin >> n >> m >> k;
    adj = vector<vector<pair<int, long long>>>(n + 1);
    dist = vector<multiset<long long>>(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, (long long)w});
    }
    for (auto &st : dist)
        for (int i = 0; i < k; i++)
            st.insert(inf);
    dist[1].clear();
    dist[1].insert(0);
    for (int i = 1; i < k; i++)
        dist[1].insert(inf);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 1});
    while (q.size())
    {
        auto [w, u] = q.top();
        q.pop();
        if ((*dist[u].rbegin()) < w)
            continue;
        for (auto [v, c] : adj[u])
            if ((*dist[v].rbegin()) > w + c)
            {
                dist[v].insert(w + c);
                auto it = dist[v].end();
                it--;
                dist[v].erase(it);
                q.push({w + c, v});
            }
    }
    for (auto i : dist[n])
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}