#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int val, ind;
};
bool cmp(nd &a, nd &b)
{
    return a.val < b.val;
}
vector<nd> v, ans;
int n;
void make(int l = 0, int r = n - 1, int base = 0)
{
    if (l > r)
        return;
    if (base < v[l].val)
    {
        for (int i = l; i <= r; i++)
            ans.push_back({2, v[i].ind});
        for (int i = base + 1; i < v[l].val; i++)
            ans.push_back({1, i});
    }
    if (l == r)
        return;
    int mid = (l + r) / 2;
    make(mid + 1, r, v[l].val);
    make(l, mid, v[l].val);
    return;
}
void solve()
{
    cin >> n;
    v = vector<nd>(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i - 1].val;
        v[i - 1].ind = i;
    }
    sort(v.begin(), v.end(), cmp);
    ans.clear();
    make();
    cout << ans.size() << "\n";
    for (auto [a, b] : ans)
        cout << a << " " << b << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}