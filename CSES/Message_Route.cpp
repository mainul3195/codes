#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis, par;
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = par = vector<int>(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vis[1] = 1;
    q.push(1);
    bool found = 0;
    while (!found && q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (!vis[v])
            {
                vis[v] = 1;
                par[v] = u;
                if (v == n)
                {
                    found = 1;
                    break;
                }
                q.push(v);
            }
    }
    if (found)
    {
        vector<int> route;
        route.push_back(n);
        int u = n;
        do
        {
            u = par[u];
            route.push_back(u);
        } while (u != 1);
        reverse(route.begin(), route.end());
        cout << route.size() << "\n";
        for (auto i : route)
            cout << i << " ";
        cout << "\n";
        return;
    }
    cout << "IMPOSSIBLE\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}