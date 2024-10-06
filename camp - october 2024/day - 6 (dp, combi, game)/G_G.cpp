#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> pos, sg_tree;
void update(int ind, int val, int node = 1, int start = 1, int end = n)
{
    sg_tree[node] = max(sg_tree[node], val);
    if (start == end)
        return;
    int mid = (start + end) / 2;
    ind <= mid ? update(ind, val, 2 * node, start, mid) : update(ind, val, 2 * node + 1, mid + 1, end);
    return;
}
int query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (start > r || end < l || l > r)
        return 0;
    if (start >= l && end <= r)
        return sg_tree[node];
    int mid = (start + end) / 2;
    return max(query(l, r, 2 * node, start, mid), query(l, r, 2 * node + 1, mid + 1, end));
}
void printtree()
{
    for (int i = 1; i <= 10; i++)
        cout << i << " -> " << sg_tree[i] << "\n";
    return;
}
void solve()
{
    cin >> n;
    sg_tree = vector<int>(4 * n, 0);
    pos = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pos[a] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        int p = pos[b];
        update(p, query(1, p - 1) + 1);
    }
    // printtree();
    cout << 2 * (n - query(1, n)) << "\n";
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