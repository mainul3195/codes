#include <bits/stdc++.h>
using namespace std;
#define int long long
struct nd
{
    long long lazy, mx;
    nd()
    {
        lazy = mx = 0;
    }
};
int d = 0, n;
vector<vector<pair<int, long long>>> adj;
vector<long long> dist, ar, ans;
vector<nd> seg_tree;
vector<bool> vis;
vector<int> in, out;
void dfs(int u, int p)
{
    in[u] = ++d;
    for (auto [v, w] : adj[u])
        if (v != p)
            dfs(v, u);
    out[u] = d;
    return;
}
void push_down(int start, int end, int node)
{
    seg_tree[node].mx += seg_tree[node].lazy;
    if (start != end)
    {
        seg_tree[2 * node].lazy += seg_tree[node].lazy;
        seg_tree[2 * node + 1].lazy += seg_tree[node].lazy;
    }
    seg_tree[node].lazy = 0;
    return;
}
// void build(int node = 1, int start = 1, int end = n)
// {
//     if (start == end)
//     {
//         seg_tree[node].mx = ar[start];
//         return;
//     }
//     int mid = (start + end) / 2;
//     build(2 * node, start, mid);
//     build(2 * node + 1, mid + 1, end);
//     seg_tree[node].mx = max(seg_tree[2 * node].mx, seg_tree[2 * node + 1].mx);
//     return;
// }
void update(int l, int r, long long val, int node = 1, int start = 1, int end = n)
{
    if (seg_tree[node].lazy)
        push_down(start, end, node);
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        seg_tree[node].lazy += val;
        push_down(start, end, node);
        return;
    }
    int mid = (start + end) / 2;
    update(l, r, val, 2 * node, start, mid);
    update(l, r, val, 2 * node + 1, mid + 1, end);
    seg_tree[node].mx = max(seg_tree[2 * node].mx, seg_tree[2 * node + 1].mx);
    return;
}
long long query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (start > r || end < l)
        return 0;
    if (seg_tree[node].lazy)
        push_down(start, end, node);
    if (start >= l && end <= r)
        return seg_tree[node].mx;
    int mid = (start + end) / 2;
    return max(
        query(l, r, 2 * node, start, mid),
        query(l, r, 2 * node + 1, mid + 1, end));
}

void dfs2(int u, int p)
{
    update(in[u], in[u], -ar[u]);
    ans[u] = query(1, n);
    update(in[u], in[u], ar[u]);
    for (auto [v, w] : adj[u])
        if (v != p)
        {
            update(1, n, w);
            update(in[v], out[v], -2 * w);
            dfs2(v, u);
            update(1, n, -w);
            update(in[v], out[v], 2 * w);
        }
    return;
}
void printTree()
{
    for (int i = 1; i <= 5; i++)
        cout << i << " -> " << seg_tree[i].mx << " " << seg_tree[i].lazy << "\n";
    return;
}
void solve()
{
    cin >> n;
    seg_tree = vector<nd>(4 * n);
    dist = ar = ans = vector<long long>(n + 1, 0);
    vis = vector<bool>(n + 1, 0);
    in = out = vector<int>(n + 1, 0);
    adj = vector<vector<pair<int, long long>>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 1});
    for (int i = 2; i <= n; i++)
        dist[i] = __LONG_LONG_MAX__;
    while (q.size())
    {
        auto [c, u] = q.top();
        q.pop();
        if (dist[u] < c)
            continue;
        for (auto [v, w] : adj[u])
        {
            long long cost = c + w;
            if (cost < dist[v])
            {
                dist[v] = cost;
                q.push({cost, v});
            }
        }
    }
    dfs(1, -1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " -> " << in[i] << " " << out[i] << "\n";
    // }

    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        dist[i] += ar[i];
    }
    // for (int i = 1; i <= n; i++)
    //     cout << dist[i] << " ";
    // cout << "\n";
    for (int i = 1; i <= n; i++)
        update(in[i], in[i], dist[i]);
    // printTree();
    dfs2(1, -1);
    // for (int i = 1; i <= n; i++)
    //     cout << dist[i] << " ";
    // cout << "\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}