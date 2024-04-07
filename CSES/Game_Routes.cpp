#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n, m;
vector<vector<int>> adj;
vector<long long> ans;
vector<int> indegree;
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    indegree = vector<int>(n + 1, 0);
    ans = vector<long long>(n + 1, 0);
    for (int i = 1; i <= m; i++)
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
    ans[1] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            (ans[v] += ans[u]) %= mod;
            indegree[v]--;
            if (!indegree[v])
                q.push(v);
        }
    }
    cout << ans[n] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}