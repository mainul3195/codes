#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> indegree, vis, main_cycle_elements;
int cnt;
void dfs(int u = 1)
{
    vis[u] = 1;
    for (auto v : adj[u])
        if (!vis[v])
            dfs(v);
    cnt++;
    return;
}
bool cycle_check(int u, int root)
{
    if (indegree[u] != 2 && u != root)
        return 0;
    vis[u] = 1;
    bool ok = 1;
    for (auto v : adj[u])
        if (!vis[v])
        {
            if (indegree[v] == 2)
            {
                ok &= cycle_check(v, root);
                if (!ok)
                    return 0;
            }
            else if (indegree[v] == 4 && v != root && u != root)
                return 0;
            else if (indegree[v] == 4 && u == root)
                continue;
            else
                return 0;
        }
    cnt++;
    return ok;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    indegree = vis = vector<int>(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indegree[u]++;
        indegree[v]++;
    }

    // No of nodes
    int k = sqrt(n + .5);
    if (k * k != n)
    {
        cout << "NO\n";
        return;
    }

    // conected
    cnt = 0;
    dfs();
    if (cnt != n)
    {
        cout << "NO\n";
        return;
    }

    main_cycle_elements.clear();
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 4)
            main_cycle_elements.push_back(i);
    if (main_cycle_elements.size() != k)
    {
        cout << "NO\n";
        return;
    }
    vis = vector<int>(n + 1, 0);
    // for (int i = 1; i <= n; i++)
    //     cout << indegree[i] << " ";
    // cout << "\n";
    for (auto u : main_cycle_elements)
    {
        cnt = 0;
        if (cycle_check(u, u) == 0 || cnt != k)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}