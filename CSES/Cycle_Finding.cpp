#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> dist;
vector<int> par;
vector<tuple<int, int, long long>> edges;
void solve()
{
    cin >> n >> m;
    dist = vector<long long>(n + 1, 0);
    par = vector<int>(n + 1, 0);
    edges = vector<tuple<int, int, long long>>(m);
    for (auto &[u, v, w] : edges)
        cin >> u >> v >> w;
    int last;
    for (int i = 1; i <= n; i++)
    {
        last = -1;
        for (auto [u, v, w] : edges)
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                last = v;
            }
    }
    if (!(~last))
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (int i = 1; i < n; i++)
            last = par[last];
        vector<int> cycle;
        for (int tmp = last;; tmp = par[tmp])
        {
            cycle.push_back(tmp);
            if (cycle.size() > 1 && tmp == last)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        for (auto i : cycle)
            cout << i << " ";
        cout << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}