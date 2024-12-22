#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> adj;
int n, q;
vector<int> ans;
void dfs(int u = 1, int p = -1, int cur = 0)
{
    ans[u] += cur;
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u, ans[u]);
    return;
}
void solve()
{
    cin >> n >> q;
    adj = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans = vector<int>(n + 1, 0);
    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p >> x;
        ans[p] += x;
    }
    // for(int i = 1; i<=n; i++)

    dfs();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}