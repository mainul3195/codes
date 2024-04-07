#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> dist, par, indegree;
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    dist = vector<int>(n + 1, 0);
    indegree = vector<int>(n + 1, 0);
    par = vector<int>(n + 1, -1);
    dist[1] = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            q.push(i);

    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            indegree[v]--;
            if (dist[v] < dist[u] + 1 && dist[u])
            {
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
            if (!indegree[v])
                q.push(v);
        }
    }
    if (dist[n] == 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> path;
    int i = n;
    while (i != -1)
    {
        path.push_back(i);
        i = par[i];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (auto i : path)
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