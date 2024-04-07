#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<long long> seg_tree;
void push_down(int node, int s, int e)
{
    if (s != e)
    {
        seg_tree[2 * node] += seg_tree[node];
        seg_tree[2 * node + 1] += seg_tree[node];
        seg_tree[node] = 0;
    }
    return;
}
void update(int l, int r, long long v, int node = 1, int s = 1, int e = n)
{
    if (s > r || e < l)
        return;
    if (s >= l && e <= r)
    {
        seg_tree[node] += v;
        push_down(node, s, e);
        return;
    }
    if (seg_tree[node])
        push_down(node, s, e);
    int mid = (s + e) / 2;
    update(l, r, v, 2 * node, s, mid);
    update(l, r, v, 2 * node + 1, mid + 1, e);
    return;
}
long long query(int ind, int node = 1, int s = 1, int e = n)
{
    if (seg_tree[node])
        push_down(node, s, e);
    if (s == e)
        return seg_tree[node];
    int mid = (s + e) / 2;
    return (ind <= mid) ? query(ind, 2 * node, s, mid) : query(ind, 2 * node + 1, mid + 1, e);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    seg_tree = vector<long long>(4 * n, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, i, x);
    }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            update(l, r, v);
        }
        else
        {
            int ind;
            cin >> ind;
            cout << query(ind) << "\n";
        }
    }
    return 0;
}