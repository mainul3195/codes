#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            q.push(i);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto v : adj[u])
        {
            indegree[v]--;
            if (!indegree[v])
                q.push(v);
        }
    }
    if (ans.size() != n)
        cout << "IMPOSSIBLE\n";
    else
    {
        for (auto i : ans)
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