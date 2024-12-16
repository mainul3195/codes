#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long on, toggle;
    nd()
    {
        on = toggle = 0;
    }
};
vector<nd> sg_tree;
int n, q;
void push_down(int node, int start, int end)
{
    int len = end - start + 1;
    sg_tree[node].on = len - sg_tree[node].on;
    if (start != end)
    {
        sg_tree[2 * node].toggle ^= 1;
        sg_tree[2 * node + 1].toggle ^= 1;
    }
    sg_tree[node].toggle ^= 1;
    return;
}
void update(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (sg_tree[node].toggle)
    {
        push_down(node, start, end);
    }
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        sg_tree[node].toggle ^= 1;
        if (sg_tree[node].toggle)
            push_down(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(l, r, 2 * node, start, mid);
    update(l, r, 2 * node + 1, mid + 1, end);
    sg_tree[node].on = sg_tree[2 * node].on + sg_tree[2 * node + 1].on;
    return;
}
int query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (sg_tree[node].toggle)
        push_down(node, start, end);
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return sg_tree[node].on;
    int mid = (start + end) / 2;
    return query(l, r, 2 * node, start, mid) + query(l, r, 2 * node + 1, mid + 1, end);
}
void solve()
{
    cin >> n >> q;
    sg_tree = vector<nd>(4 * n);
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t)
            cout << query(l, r) << "\n";
        else
            update(l, r);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}