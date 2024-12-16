#include <bits/stdc++.h>
using namespace std;
int n, m;
#define inf 1000000000000000LL
struct nd
{
    long long u, v, w;
};
void solve()
{
    cin >> n >> m;
    vector<nd> edges(m);
    for (auto &[u, v, w] : edges)
        cin >> u >> v >> w;
    vector<long long> dist(n + 1, -inf);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
        for (auto [u, v, w] : edges)
        {
            if (dist[u] + w > dist[v])
                dist[v] = dist[u] + w;
        }
    long long mx = dist[n];
    for (int i = 0; i < n; i++)
        for (auto [u, v, w] : edges)
        {
            if (dist[u] + w > dist[v])
                dist[v] = dist[u] + w;
        }
    if (mx != dist[n])
        cout << "inf\n";
    else
        cout << mx << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}