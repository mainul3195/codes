#include <bits/stdc++.h>
using namespace std;
// call build and init in main
long long n;
int lg[300005];
vector<vector<long long>> sp_t;
long long op(auto &a, auto &b) { return gcd(a, b); }
void build_st()
{
    for (long long i = 0; i < n; i++)
        cin >> sp_t[i][0];

    int lim = log2(n + .5) + 2;
    for (int k = 1; k < lim; k++)
        for (int i = 0; i < n; i++)
            if (i + (1 << k) - 1 < n)
                sp_t[i][k] = op(sp_t[i][k - 1], sp_t[i + (1 << (k - 1))][k - 1]);
}
long long q(long long l, long long r)
{
    int len = r - l;
    int k = lg[len];
    // if (l == 0 && r == 5)
    // {
    //     cout << "in\n";
    //     cout << len << " " << k << " " << sp_t[l][k] << " " << sp_t[r - (1 << k) + 1][k] << "\n";
    // }
    return gcd(sp_t[l][k], sp_t[r - (1 << k) + 1][k]);
}
void init_st()
{
    cin >> n;
    sp_t = vector<vector<long long>>(n + 2, vector<long long>((long long)log2(n) + 2));
}
vector<int> seg_tree;
// void build(int node = 1, int start = 0, int end = n - 1)
// {
//     if (start == end)
//     {
//         seg_tree[node] = sp_t[start][0];
//         return;
//     }
//     int mid = (start+end)/2;
//     build(2*node, start, mid);
//     build(2*node+1, mid+1, end);
//     return;
// }
void update(int l, int r, int val, int node = 1, int start = 0, int end = n - 1)
{
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        seg_tree[node] = max(seg_tree[node], val);
        return;
    }
    int mid = (start + end) / 2;
    update(l, r, val, 2 * node, start, mid);
    update(l, r, val, 2 * node + 1, mid + 1, end);
    return;
}
int query(int ind, int node = 1, int start = 0, int end = n - 1)
{
    if (start == end)
        return seg_tree[node];
    int mid = (start + end) / 2;
    return max(seg_tree[node], ind <= mid ? query(ind, 2 * node, start, mid) : query(ind, 2 * node + 1, mid + 1, end));
}
void solve()
{
    init_st();
    build_st();
    seg_tree = vector<int>(4 * n, 0);

    // int lim = log2(n + .5) + 2;
    // for (int k = 0; k < lim; k++)
    // {
    //     for (int i = 0; i < n; i++)
    //         cout << sp_t[i][k] << " ";
    //     cout << "\n";
    // }
    for (int i = 0; i < n; i++)
    {
        int len = 0;
        if (sp_t[i][0] > 1)
        {
            int l = i, r = n - 1, mid, ind1, ind2;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (q(i, mid) > 1)
                {
                    ind2 = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            // cout << ind2 << "\n";
            // return;
            // cout << ind1 << " " << ind2 << "\n";
            // return;
            len = ind2 - i + 1;
        }
        update(i, i + len - 1, len);
    }
    for (int i = 0; i < n; i++)
        cout << query(i) << " ";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lg[0] = lg[1] = 0;
    for (int i = 2; i < 300005; i++)
        lg[i] = lg[i / 2] + 1;
    // for (int i = 0; i <= 35; i++)
    //     cout << i << " " << lg[i] << "\n";
    solve();
    return 0;
}