#include <bits/stdc++.h>
using namespace std;
#define int long long
struct nd
{
    int r, c, ind;
    bool operator<(const nd &a) const
    {
        return c < a.c || (c == a.c && r > a.r);
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<nd> f;
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        f.push_back({r, c, i});
    }
    sort(f.begin(), f.end());
    vector<int> ans(k, 0);
    int prev = 0;
    long long bad = 0;
    for (auto [r, c, i] : f)
    {
        if (r <= prev)
            continue;
        bad += (r - prev) * (m - c + 1);
        prev = r;
        ans[i] = 1;
    }
    cout << n * m - bad << "\n";
    for (int i = 0; i < k; i++)
        cout << ans[i] << " \n"[i == k - 1];

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