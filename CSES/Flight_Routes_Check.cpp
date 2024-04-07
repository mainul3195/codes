#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj, rev;
vector<int> stck;
int vis[100005];
void dfs(int u, vector<vector<int>> &ad)
{
    vis[u] = 1;
    for (auto v : ad[u])
        if (!vis[v])
            dfs(v, ad);
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
    memset(vis, 0, (n + 2) * sizeof(int));

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, adj);
    memset(vis, 0, (n + 2) * sizeof(int));
    int bck = stck.back();
    dfs(bck, rev);
    for (int i = stck.size() - 2; i >= 0; i--)
        if (!vis[stck[i]])
        {
            cout << "NO\n";
            cout << stck[i] << " " << bck << "\n";
            return;
        }
    cout << "YES\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}