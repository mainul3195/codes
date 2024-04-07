#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> col;
vector<vector<int>> adj;
vector<int> ans;
vector<int> sz;
vector<int> *subtree_nodes[200005];
set<int> cols;
int find_sz(int u = 1, int p = -1)
{
    int tot = 1;
    for (auto v : adj[u])
        if (v != p)
            tot += find_sz(v, u);
    return sz[u] = tot;
}
void dfs(int u = 1, int p = -1, bool big = 0)
{
    int bigChild = -1, mx = -1;
    for (auto v : adj[u])
        if (v != p && sz[v] > mx)
            mx = sz[v], bigChild = v;
    for (auto v : adj[u])
        if (v != p && v != bigChild)
            dfs(v, u, 0);
    if (bigChild != -1)
        dfs(bigChild, u, 1), subtree_nodes[u] = subtree_nodes[bigChild];
    else
        subtree_nodes[u] = new vector<int>();
    subtree_nodes[u]->push_back(u);
    cols.insert(col[u]);
    for (auto v : adj[u])
        if (v != p && v != bigChild)
            for (auto x : *subtree_nodes[v])
            {
                cols.insert(col[x]);
                subtree_nodes[u]->push_back(x);
            }
    ans[u] = cols.size();
    if (!big)
        cols.clear();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    col = vector<int>(n + 1);
    adj = vector<vector<int>>(n + 1);
    ans = vector<int>(n + 1, 0);
    sz = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        col[i] = c;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_sz();
    dfs();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << "\n";
    return 0;
}