#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> edg, par;
int n;
struct nd
{
    int node, depth;
    bool operator<(const nd &a) const
    {
        return depth > a.depth || (depth == a.depth && node < a.node);
    }
};
set<nd> st;
void dfs(int u = 1, int l = 0)
{
    int edg_count = 0;
    for (auto v : adj[u])
    {
        edg_count++;
        dfs(v, l + 1);
    }
    if (!edg_count)
        st.insert({u, l});
    edg[u] = edg_count;
    return;
}
void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    edg = par = vector<int>(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        par[i] = p;
        adj[p].push_back(i);
    }
    st.clear();
    dfs();

    int cnt = 0;
    while (st.size() > 1)
    {
        auto [a, l1] = *st.begin();
        st.erase(st.begin());
        auto [b, l2] = *st.begin();
        st.erase(st.begin());
        cnt++;
        int c = par[a];
        edg[c]--;
        if (!edg[c])
            st.insert({c, l1 - 1});
        c = par[b];
        edg[c]--;
        if (!edg[c])
            st.insert({c, l2 - 1});
    }
    cout << cnt << "\n";
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