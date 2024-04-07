#include <bits/stdc++.h>
using namespace std;
#define lim 500005
int n, k;
vector<int> seg_tree;
void update(int ind, int val, int node = 1, int start = 1, int end = lim - 1)
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

int query(int l, int r, int node = 1, int start = 1, int end = lim - 1)
{
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return seg_tree[node];
    int mid = (start + end) / 2;
    return max(query(l, r, 2 * node, start, mid), query(l, r, 2 * node + 1, mid + 1, end));
}
void print()
{
    for (int i = 1; i <= 5; i++)
        cout << i << " -> " << query(i, i) << "\n";
    return;
}
void solve()
{
    cin >> n >> k;
    seg_tree = vector<int>(4 * lim, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        update(x, query(max(x - k, 1), min(x + k, lim - 1)) + 1);
        // print();
        // cout << "\n";
    }
    cout << query(1, lim - 1) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}