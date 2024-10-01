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
void solve()
{
    int n;
    cin >> n;
    vector<nd> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].val;
        v[i].ind = i;
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> b(n, 0);
    vector<nd> strt;
    strt.push_back({v[0].val, 0});
    for (int i = 1; i < n; i++)
        if (v[i].val != strt.back().val)
            strt.push_back({v[i].val, i});
    // for (auto [a, b] : strt)
    //     cout << a << " " << b << "\n";
    // cout << "------------\n";
    vector<nd> ans;
    for (int i = 0; i < strt[0].val; i++)
        ans.push_back({1, i});
    for (int i = 1; i < strt.size(); i += 2)
    {
        int lim = n;
        if (i + 1 < strt.size())
        {
            lim = strt[i + 1].ind;
            for (int j = strt[i + 1].ind; j < n; j++)
                ans.push_back({2, v[j].ind});
            for (int j = strt[i - 1].val + 1; j < strt[i + 1].val; j++)
                ans.push_back({1, j});
        }
        for (int j = strt[i].ind; j < lim; j++)
            ans.push_back({2, v[j].ind});
        for (int j = strt[i - 1].val + 1; j < strt[i].val; j++)
            ans.push_back({1, j});
    }
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