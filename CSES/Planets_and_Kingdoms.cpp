#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj, rev;
vector<int> stck;
int kingdom;
int vis[100005];
bool push;
void dfs(int u, vector<vector<int>> &ad)
{
    vis[u] = kingdom;
    for (auto v : ad[u])
        if (!vis[v])
            dfs(v, ad);
    if (push)
        stck.push_back(u);
}
void solve()
{
    cin >> n >> m;
    adj = rev = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    push = kingdom = 1;
    memset(vis, 0, (n + 2) * sizeof(int));
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, adj);
    memset(vis, 0, (n + 2) * sizeof(int));
    push = 0;
    while (stck.size())
    {
        int bck = stck.back();
        stck.pop_back();
        if (!vis[bck])
        {
            dfs(bck, rev);
            kingdom++;
        }
    }
    cout << kingdom - 1 << "\n";
    for (int i = 1; i <= n; i++)
        cout << vis[i] << " ";
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