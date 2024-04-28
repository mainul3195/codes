#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int cc, d, x;
    bool operator<(const nd &a) const
    {
        return d > a.d || (d == a.d && cc < a.cc) || (cc == a.cc && d == a.d && x < a.x);
    }
};
int n, k;
vector<vector<int>> adj;
vector<int> depth, vis, par, leaves, current_cc, available;
bool ok(int m)
{
    set<nd> st;
    for (int i = 1; i <= n; i++)
        st.insert({current_cc[i], depth[i], i});
    int cut = 0;
    while (st.size())
    {

        auto it = st.begin();
        auto [cc, d, x] = *it;
        if (st.size() == 1)
        {
            if (cc < m)
                return cut > k;
            break;
        }
        if (cc >= m)
            cut++;
        else
        {
            for (auto v : adj[x])
                if (available[v])
                {
                    auto it1 = st.find({current_cc[v], depth[v], v});
                    current_cc[v] += cc;
                    st.erase(it1);
                    st.insert({current_cc[v], depth[v], v});
                }
        }
        available[x] = 0;
        st.erase(it);
    }
    return cut >= k;
}
int farthest_node, cur_dis;
void dfs(int u, int l, int p)
{
    par[u] = p;
    vis[u] = l;
    if (l > cur_dis)
        farthest_node = u, cur_dis = l;
    for (auto v : adj[u])
        if (!vis[v])
            dfs(v, l + 1, u);
    return;
}
void solve()
{
    cin >> n >> k;
    adj = vector<vector<int>>(n + 1);
    depth = vis = par = vector<int>(n + 1, 0);
    leaves.clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cur_dis = -1;
    dfs(1, 1, -1);
    int one_end = farthest_node;
    cur_dis = -1;
    vis = vector<int>(n + 1, 0);
    dfs(one_end, 1, -1);
    vector<int> path;
    int cur = farthest_node;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = par[cur];
    }
    int middle = path[path.size() / 2];
    vis = vector<int>(n + 1, 0);
    cur_dis = -1;
    // cout << "middle - " << middle << "\n";
    dfs(middle, 1, -1);
    depth = vis;
    // for (int i = 1; i <= n; i++)
    //     cout << i << " -> " << depth[i] << "\n";
    // cout << "\n\n";
    int l = 1, r = n, mid, ans = 1;
    while (l <= r)
    {
        current_cc = vector<int>(n + 1, 1);
        available = vector<int>(n + 1, 1);
        int mid = (l + r) / 2;
        if (ok(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
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