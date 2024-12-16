#include <bits/stdc++.h>
using namespace std;
int n, q;
int bit[100005];
int qr(int x)
{
    int ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += bit[x];
    return ans;
}
void upd(int x, int val)
{
    for (; x <= n; x += (x & (-x)))
        bit[x] += val;
}
vector<int> seg_tree;
vector<int> emni;
void build(int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg_tree[node] = emni[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    seg_tree[node] = max(seg_tree[2 * node], seg_tree[2 * node + 1]);
    return;
}
int find_max(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return seg_tree[node];
    int mid = (start + end) / 2;
    return max(find_max(l, r, 2 * node, start, mid),
               find_max(l, r, 2 * node + 1, mid + 1, end));
}

void solve()
{
    while (cin >> n && n)
    {
        cin >> q;
        vector<int> v(n);
        memset(bit, 0, sizeof(int) * (n + 2));
        emni = vector<int>(n + 1, 0);
        seg_tree = vector<int>(4 * n);
        for (auto &i : v)
            cin >> i;
        for (int i = 0; i < n; i++)
        {
            int cur = v[i], cnt = 0;
            while (i < n && v[i] == cur)
                cnt++, i++;
            upd(i, 1);
            emni[i] = cnt;
            i--;
        }
        build();
        int next, before;
        while (q--)
        {
            int s, e;
            cin >> s >> e;
            if (qr(e) - qr(s - 1) == 0)
            {
                cout << e - s + 1 << "\n";
                continue;
            }
            int l = s, r = e, next = s, val = qr(s - 1);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (qr(mid) > val)
                {
                    next = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            l = s, r = e, before = r, val = qr(e);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (qr(mid) == val)
                {
                    before = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            int middle = 0;
            if (next != before)
                middle = find_max(next + 1, before);

            cout << max({next - s + 1, middle, e - before}) << "\n";
        }
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