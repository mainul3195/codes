#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, seg_tree;
void update(int ind, int val, int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg_tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    ind <= mid ? update(ind, val, 2 * node, start, mid) : update(ind, val, 2 * node + 1, mid + 1, end);
    seg_tree[node] = max(seg_tree[2 * node], seg_tree[2 * node + 1]);
    return;
}
int query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (r < l || start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return seg_tree[node];
    int mid = (start + end) / 2;
    return max(query(l, r, 2 * node, start, mid), query(l, r, 2 * node + 1, mid + 1, end));
}
vector<int> ans;
vector<vector<int>> adj, prev_ans;
void dfs(int u, int p)
{
    int cur_val = a[u - 1];
    int prev_max = query(1, cur_val - 1);
    ans[u] = prev_max + 1;
    update(cur_val, ans[u]);
    prev_ans[cur_val].push_back(ans[u]);
    // cout << u << " -> " << cur_val << " " << prev_max << " " << ans[u] << " " << prev_ans[cur_val].size() << "\n";
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u);
    prev_ans[cur_val].pop_back();
    if (prev_ans[cur_val].size())
        update(cur_val, prev_ans[cur_val].back());
    else
        update(cur_val, 0);
    return;
}
void solve()
{
    cin >> n;
    a = vector<int>(n);
    for (auto &i : a)
        cin >> i;
    set<int> st;
    for (auto i : a)
        st.insert(i);
    int nw = 1;
    // for (auto i : a)
    //     cout << i << " ";
    // cout << "\n";
    map<int, int> mp;
    for (auto i : st)
        mp[i] = nw++;
    for (auto &i : a)
        i = mp[i];
    // for (auto i : a)
    //     cout << i << " ";
    // cout << "\n";
    seg_tree = vector<int>(4 * n, 0);
    adj = prev_ans = vector<vector<int>>(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = vector<int>(n + 1, 0);
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}