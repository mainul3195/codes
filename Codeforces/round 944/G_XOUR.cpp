#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> elem, pos;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int ind = x / 4;
        elem[ind].push_back(x);
        pos[ind].push_back(i);
    }
    vector<int> ans(n);
    for (auto [ind, v] : elem)
    {
        sort(v.begin(), v.end());
        auto indexes = pos[ind];
        for (int i = 0; i < indexes.size(); i++)
            ans[indexes[i]] = v[i];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}