#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int n;
map<int, int> mp;
struct nd
{
    int xr;
    nd *left, *right;
    nd()
    {
        xr = 0;
        left = right = NULL;
    }
    nd(int v)
    {
        xr = v;
        left = right = NULL;
    }
    nd(nd *a, nd *b)
    {
        xr = (a->xr) ^ (b->xr);
        left = a;
        right = b;
    }
    nd(nd *a)
    {
        xr = a->xr;
        left = a->left;
        right = a->right;
    }
};
nd *build(int start = 0, int end = n - 1)
{
    if (start == end)
        return new nd(0);
    return new nd(build(start, (start + end) / 2), build((start + end) / 2 + 1, end));
}
nd *update(nd *node, int ind, int val, int start = 0, int end = n - 1)
{
    if (start == end)
        return new nd(val);
    int mid = (start + end) / 2;
    if (ind <= mid)
        return new nd(update(node->left, ind, val, start, mid), node->right);
    else
        return new nd(node->left, update(node->right, ind, val, mid + 1, end));
    return NULL;
}
vector<nd> roots;

int query(nd *node, int l, int r, int start = 0, int end = n - 1)
{
    if (l > end || r < start)
        return 0;
    if (l <= start && r >= end)
        return node->xr;
    int mid = (start + end) / 2;
    return query(node->left, l, r, start, mid) ^ query(node->right, l, r, mid + 1, end);
}
void print(nd *node, int start = 0, int end = n - 1)
{
    if (!node)
        return;
    cout << node->xr << " ";
    // cout << "l-> ";
    print(node->left, start, end);
    // cout << "r-> ";
    print(node->right, start, end);
    return;
}
void solve()
{
    cin >> n;
    v = vector<pair<int, int>>(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (mp.find(x) == mp.end())
            mp[x] = ((long long)rand() * rand()) % 1000000000;
        v[i].first = x;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    roots.push_back(*build());
    for (auto [x, i] : v)
        roots.push_back(update(&roots.back(), i, mp[x]));
    roots.erase(roots.begin());
    int prev = -1;
    nd node;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i].first != prev)
            node = roots[i];
        else
            roots[i] = node;
        prev = v[i].first;
    }
    int ans = 0;
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l = ans ^ l;
        r = ans ^ r;
        int lft = 0, rght = n - 1, mid;
        int ind = -1;
        while (lft <= rght)
        {
            mid = (lft + rght) / 2;
            if (query(&roots[mid], l - 1, r - 1))
            {
                ind = mid;
                rght = mid - 1;
            }
            else
                lft = mid + 1;
        }
        if (~ind)
            ans = v[ind].first;
        else
            ans = 0;
        cout << ans << "\n";
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