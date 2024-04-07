#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> seg_tree;
vector<int> v;
void update(int ind, int val, int node = 1, int s = 1, int e = n)
{
    if (s == e)
    {
        seg_tree[node] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (ind <= mid)
        update(ind, val, 2 * node, s, mid);
    else
        update(ind, val, 2 * node + 1, mid + 1, e);
    seg_tree[node] = min(seg_tree[2 * node], seg_tree[2 * node + 1]);
    return;
}
int query(int l, int r, int node = 1, int s = 1, int e = n)
{
    if (s > r || e < l)
        return 2000000000;
    if (s >= l && e <= r)
        return seg_tree[node];
    int mid = (s + e) / 2;
    return min(query(l, r, 2 * node, s, mid), query(l, r, 2 * node + 1, mid + 1, e));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    seg_tree = vector<int>(4 * n, 2000000000);
    v = vector<int>(n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, x);
    }
    while (q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
            update(a, b);
        else
            cout << query(a, b) << "\n";
    }
    return 0;
}