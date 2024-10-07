#include <bits/stdc++.h>
using namespace std;
vector<set<int>> adj;
int n, m;
void solve()
{
    cin >> n >> m;
    adj = vector<set<int>>(n + 1, set<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
    }
    vector<vector<int>> paths;
    while (1)
    {
        vector<int> par(n + 1, -1);
        queue<int> q;
        q.push(1);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            bool found = 0;
            for (auto v : adj[u])
                if (par[v] == -1)
                {
                    par[v] = u;
                    q.push(v);
                    if (v == n)
                    {
                        found = 1;
                        break;
                    }
                }
            if (found)
                break;
        }
        if (par[n] == -1)
            break;
    }
    cout << paths.size() << "\n";
    for (auto v : paths)
    {
        cout << v.size() << "\n";
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    }

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}