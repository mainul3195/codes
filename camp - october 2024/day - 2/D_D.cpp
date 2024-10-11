#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long xr;
    nd *left, *right;
    nd()
    {
        xr = 0;
        left = right = NULL;
    }
    nd(long long v)
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
vector<pair<long long, int>> v;
int n;
map<int, long long> mp;
nd *build(int start = 0, int end = n - 1)
{
    if (start == end)
        return new nd(mp[v[start].first]);
    return new nd(build(start, (start + end) / 2), build((start + end) / 2 + 1, end));
}
nd *update(nd *node, int ind, long long val, int start = 0, int end = n - 1)
{
    if (start == end)
        return new nd(val);
    int mid = (start + end) / 2;
    return ind <= mid ? new nd(update(node->left, ind, val, start, mid)) : new nd(update(node->right, ind, val, mid + 1, end));
}
vector<nd> roots;
void solve()
{
    cin >> n;
    v = vector<pair<long long, int>>(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (mp.find(x) == mp.end())
            mp[x] = (long long)rand() * rand();
        v[i].first = x;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    roots.push_back(*build());
    for (auto [x, i] : v)
        roots.push_back(update(&roots.back(), i, mp[x]));
    reverse(roots.begin(), roots.end());
    roots.pop_back();
    reverse(roots.begin(), roots.end());
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}