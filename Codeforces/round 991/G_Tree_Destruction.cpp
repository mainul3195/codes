#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> dp, degree;
int ans = 0;
void dfs(int u = 1, int p = -1)
{
    dp[u] = max(dp[u], degree[u]);
    if (degree[u] == 1 && p != -1)
    {
        return;
    }
    multiset<int> st;
    for (auto v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
            st.insert(dp[v]);
            if (st.size() > 2)
                st.erase(st.begin());
            dp[u] = max(dp[u], dp[v] - 1 + degree[u] - 1);
        }
    }
    if (st.size() == 2)
    {
        int sum = 0;
        for (auto el : st)
            sum += el;
        ans = max(ans, sum - 2 + degree[u] - 2);
    }
    return;
}
void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    dp = degree = vector<int>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++, degree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0;
    dfs();
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " -> " << dp[i] << "\n";
    // }
    for (auto i : dp)
        ans = max(ans, i);
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}