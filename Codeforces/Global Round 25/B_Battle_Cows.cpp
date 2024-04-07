#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int val = v[m - 1];
    for (auto &i : v)
    {
        if (i > val)
            i = 1;
        else
            i = 0;
    }
    vector<int> nxt(n), prev(n);
    int cur = n;
    for (int i = n - 1; i >= 0; i--)
    {
        nxt[i] = cur;
        if (v[i] == 1)
            cur = i;
    }
    cur = -1;
    for (int i = 0; i < n; i++)
    {
        prev[i] = cur;
        if (v[i] == 1)
            cur = i;
    }
    // for (auto i : nxt)
    //     cout << i << " ";
    // cout << "\n";
    // for (auto i : prev)
    //     cout << i << " ";
    // cout << "\n";
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        if (prev[i] == -1)
        {
            if (v[i] == 0)
            {
                tmp += nxt[i] - i - 1;
                if (prev[i] != i - 1)
                    tmp++;
            }
            else
            {
                int nx = nxt[i], pv = prev[i];
                if (i < m - 1)
                    nx = min(nx, m - 1);
                if (i > m - 1)
                    pv = max(pv, m - 1);
                tmp += nx - i - 1 + (pv != i - 1);
                if (pv != -1)
                    tmp = 0;
            }
        }
        // cout << "i = " << i << "\t" << tmp << "\n";
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
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