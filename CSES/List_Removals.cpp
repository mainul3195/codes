#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> seg_tree, a;
void build(int node = 1, int s = 1, int e = n)
{
    if (s == e)
    {
        seg_tree[node] = 1;
        return;
    }
    int mid = (s + e) >> 1;
    build(2 * node, s, mid);
    build(2 * node + 1, mid + 1, e);
    seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1];
    return;
}
int query(int need, int node = 1, int s = 1, int e = n)
{
    if (s == e)
    {
        seg_tree[node] = 0;
        return s;
    }
    int mid = (s + e) >> 1;
    int ans = (seg_tree[2 * node] >= need) ? query(need, 2 * node, s, mid) : query(need - seg_tree[2 * node], 2 * node + 1, mid + 1, e);
    seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1];
    return ans;
}
void solve()
{
    cin >> n;
    seg_tree = vector<int>(4 * n, 0);
    build();
    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cout << a[query(x)] << " ";
    }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}