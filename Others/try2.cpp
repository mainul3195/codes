#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int tot, lazy;
    nd()
    {
        tot = lazy = 0;
    }
};
vector<nd> seg_tree[26];
int n, q;
string s;
void push_down(int ind, int node, int start, int end)
{
    seg_tree[ind][node].tot = seg_tree[ind][node].lazy == 1 ? 0 : end - start + 1;
    if (start != end)
        seg_tree[ind][2 * node].lazy = seg_tree[ind][2 * node + 1].lazy = seg_tree[ind][node].lazy;
    seg_tree[ind][node].lazy = 0;
    return;
}
void update(int ind, int l, int r, int val, int node = 1, int start = 1, int end = n)
{
    if (l > r)
        return;
    if (seg_tree[ind][node].lazy)
        push_down(ind, node, start, end);
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        seg_tree[ind][node].lazy = (val ? 2 : 1);
        push_down(ind, node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(ind, l, r, val, 2 * node, start, mid);
    update(ind, l, r, val, 2 * node + 1, mid + 1, end);
    seg_tree[ind][node].tot = seg_tree[ind][2 * node].tot + seg_tree[ind][2 * node + 1].tot;
    return;
}
int query(int ind, int l, int r, int node = 1, int start = 1, int end = n)
{
    if (seg_tree[ind][node].lazy)
        push_down(ind, node, start, end);
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return seg_tree[ind][node].tot;
    int mid = (start + end) / 2;
    return query(ind, l, r, 2 * node, start, mid) + query(ind, l, r, 2 * node + 1, mid + 1, end);
}
void solve()
{
    cin >> n >> q;
    cin >> s;
    s = '.' + s;
    for (int i = 0; i < 26; i++)
        seg_tree[i] = vector<nd>(4 * n);
    for (int i = 1; i <= n; i++)
        update(s[i] - 'a', i, i, 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < 26; j++)
    //         if (query(j, i, i))
    //         {
    //             cout << (char)(j + 'a');
    //             break;
    //         }
    //     cout << "\n";
    // }
    // cout << "\n";
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 1; j <= n; j++)
    //         cout << query(i, j, j) << " ";
    //     cout << "\n";
    // }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ar[26] = {0};
        int odd_count = 0, odd_ind;
        for (int i = 0; i < 26; i++)
        {
            ar[i] = query(i, l, r);
            if (ar[i] & 1)
                odd_count++, odd_ind = i;
        }
        // cout << odd_count << "\n";
        if (odd_count > 1)
            continue;
        int cur = l;
        // cout << "Cur = " << cur << "\n";
        for (int i = 0; i < 26; i++)
        {
            int lim = ar[i] / 2;
            update(i, cur, cur + lim - 1, 1);
            for (int j = 0; j < 26; j++)
                if (i != j)
                    update(j, cur, cur + lim - 1, 0);
            cur += lim;
        }
        if (odd_count)
        {
            update(odd_ind, cur, cur, 1);
            for (int j = 0; j < 26; j++)
                if (j != odd_ind)
                    update(j, cur, cur, 0);
            cur++;
        }
        for (int i = 25; i >= 0; i--)
        {
            int lim = ar[i] / 2;
            update(i, cur, cur + lim - 1, 1);
            for (int j = 0; j < 26; j++)
                if (i != j)
                    update(j, cur, cur + lim - 1, 0);
            cur += lim;
        }
        // cout << "last -> " << cur << "\n";
    }
    for (int i = 1; i <= n; i++)
        // {
        //     cout << i << ": ";
        for (int j = 0; j < 26; j++)
            if (query(j, i, i))
            {
                cout << (char)(j + 'a');
                break;
            }
    //     cout << "\n";
    // }
    cout << "\n";
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 1; j <= n; j++)
    //         cout << query(i, j, j) << " ";
    //     cout << "\n";
    // }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}