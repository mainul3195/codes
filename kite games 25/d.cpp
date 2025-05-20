#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &i : p)
    {
        cin >> i;
        i--;
    }
    vector<int> vis(n + 1, 0), cycles;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int len = 0, cur = i;
            while (!vis[cur])
            {
                vis[cur] = 1;
                cur = p[cur];
                len++;
            }
            if (len > 1)
                cycles.push_back(len);
        }
    }
    // for(int i = 0; i<n; i++)
    // {
    //     cout << vis[i] << " ";
    // }
    // cout << "\n";
    int mx = 0;
    for (auto i : cycles)
    {
        int lg = log2(i + .5);
        if ((1 << lg) != i)
        {
            cout << "-1\n";
            return;
        }
        mx = max(lg, mx);
    }
    cout << mx << "\n";
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