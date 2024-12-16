#include <bits/stdc++.h>
using namespace std;
int n, mx_el;
vector<long long> v;
vector<int> seg_tree;
void update(int ind, int val, int node = 1, int start = 1, int end = mx_el)
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
int query(int l, int r, int node = 1, int start = 1, int end = mx_el)
{
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return seg_tree[node];
    int mid = (start + end) / 2;
    return max(query(l, r, 2 * node, start, mid), query(l, r, 2 * node + 1, mid + 1, end));
}
vector<int> forwared, backward;
void solve()
{
    cin >> n;
    v = vector<long long>(n);
    forwared = backward = vector<int>(n);
    set<long long> st;
    for (auto &i : v)
    {
        cin >> i;
        st.insert(i);
    }
    map<long long, int> mp;
    mx_el = 2;
    while (st.size())
    {
        mp[*(st.begin())] = mx_el++;
        st.erase(st.begin());
    }
    seg_tree = vector<int>(4 * mx_el, 0);
    for (auto &i : v)
        i = mp[i];
    for (int i = 0; i < n; i++)
    {
        int el = v[i];
        int mx = query(1, el - 1);
        update(el, mx + 1);
        forwared[i] = mx + 1;
    }
    seg_tree = vector<int>(4 * mx_el, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int el = v[i];
        int mx = query(1, el - 1);
        update(el, mx + 1);
        backward[i] = mx + 1;
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
        if (forwared[i] > 1 && backward[i] > 1)
            ans = max(ans, forwared[i] + backward[i] - 1);
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}