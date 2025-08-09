#include <bits/stdc++.h>
using namespace std;
#define mx 100005
int visited[mx], parent[mx];
vector<vector<int>> adj;
void solve()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        parent[i] = visited[i] = -1;

    visited[1] = 1;

    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (visited[v] == -1)
            {
                parent[v] = u;
                visited[v] = visited[u] + 1;
                q.push(v);
            }
    }

    if (visited[n] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;
    int current = n;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    cout << visited[n] << "\n";
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " \n"[i == path.size() - 1];
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}