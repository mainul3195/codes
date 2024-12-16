#include <bits/stdc++.h>
using namespace std;
#define int long long
struct nd
{
    long long sum, start, d, lz;
    nd()
    {
        sum = start = d = lz = 0;
    }
    nd operator+(const nd &a)
    {
        nd b;
        b.sum = a.sum + sum;
        b.start = b.d = b.lz = 0;
        return b;
    }
};
vector<nd> seg_tree;
int n, m, q;
void push_down(int node, int start, int end)
{
    long long len = (end - start + 1);
    seg_tree[node].sum = len * (2 * seg_tree[node].start + (len - 1) * seg_tree[node].d) / 2;
    if (start != end)
    {
        int mid = (start + end) / 2;
        seg_tree[2 * node].start = seg_tree[node].start + (end - mid) * seg_tree[node].d;
        seg_tree[2 * node + 1].start = seg_tree[node].start;
        seg_tree[2 * node].d = seg_tree[node].d;
        seg_tree[2 * node + 1].d = seg_tree[node].d;
        seg_tree[2 * node].lz = seg_tree[2 * node + 1].lz = 1;
    }
    seg_tree[node].start = seg_tree[node].d = seg_tree[node].lz = 0;
    return;
}
void update(int l, int r, int d, int node = 1, int start = 1, int end = n)
{
    if (seg_tree[node].lz)
        push_down(node, start, end);
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        seg_tree[node].lz = 1;
        seg_tree[node].start = (r - end) * d;
        seg_tree[node].d = d;
        push_down(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(l, r, d, 2 * node, start, mid);
    update(l, r, d, 2 * node + 1, mid + 1, end);
    seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1];
}
long long query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (seg_tree[node].lz)
        push_down(node, start, end);
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return seg_tree[node].sum;
    int mid = (start + end) / 2;
    return query(l, r, 2 * node, start, mid) + query(l, r, 2 * node + 1, mid + 1, end);
}
long long bit[300005];
long long qr(long long x)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void upd(long long x, long long val)
{
    for (; x <= n; x += (x & (-x)))
        bit[x] += val;
}
int harbour_value[300005];
void print_tree()
{
    for (int i = 1; i <= 15; i++)
    {
        cout << i << " -> \n";
        cout << seg_tree[i].sum << "\n";
        cout << seg_tree[i].start << "\n";
        cout << seg_tree[i].d << "\n";
        cout << seg_tree[i].lz << "\n\n";
    }
}
void solve()
{
    cin >> n >> m >> q;
    seg_tree = vector<nd>(4 * n);
    memset(bit, 0, (n + 1) * sizeof(long long));
    memset(harbour_value, 0, (n + 1) * sizeof(int));
    vector<pair<int, int>> v(m);
    for (auto &[a, b] : v)
        cin >> a;
    for (auto &[a, b] : v)
        cin >> b;
    sort(v.begin(), v.end());
    int last = -1;
    for (auto [a, b] : v)
    {
        if (last != -1)
            update(last + 1, a, harbour_value[last]);
        last = a;
        harbour_value[a] = b;
        upd(a, 1);
    }
    // print_tree();
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int ind, val;
            cin >> ind >> val;
            int prev = qr(ind);
            int l = 1, r = ind, mid, prev_ind, next_ind;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (qr(mid) != prev)
                    l = mid + 1;
                else
                {
                    prev_ind = mid;
                    r = mid - 1;
                }
            }
            l = ind, r = n;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (qr(mid) == prev)
                    l = mid + 1;
                else
                {
                    next_ind = mid;
                    r = mid - 1;
                }
            }
            update(prev_ind + 1, ind, harbour_value[prev_ind]);
            update(ind + 1, next_ind, val);
            harbour_value[ind] = val;
            upd(ind, 1);
            // print_tree();
            // break;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << "\n";
            // print_tree();
        }
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}