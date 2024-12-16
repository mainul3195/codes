#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> val, ans;
vector<vector<int>> adj;
void dfs(int u, set<int> &st)
{
    if (val[u] != 2147483647)
    {
        st.insert(val[u]);
        return;
    }
    for (auto v : adj[u])
    {
        set<int> childSt;
        dfs(v, childSt);
        ans[u] = min(ans[u], ans[v]);
        if (childSt.size() > st.size())
            swap(st, childSt);
        for (auto el : childSt)
        {
            auto it = st.lower_bound(el);
            if (it != st.end())
                ans[u] = min(ans[u], *it - el);
            if (it != st.begin())
            {
                it--;
                ans[u] = min(ans[u], el - *it);
            }
        }
        for (auto el : childSt)
            st.insert(el);
    }
    return;
}
void solve()
{
    cin >> n >> m;
    ans = val = vector<int>(n + 1, 2147483647);
    adj = vector<vector<int>>(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = n - m + 1; i <= n; i++)
        cin >> val[i];
    set<int> st;
    dfs(1, st);
    for (int i = 1; i <= n - m; i++)
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