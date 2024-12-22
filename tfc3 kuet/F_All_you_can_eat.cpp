#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> dp(t + 3003, 0), nd(t + 3003, 0);
    nd[0] = 1;
    vector<pair<int, int>> inp;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        inp.push_back({a, b});
    }
    // sort(inp.begin(), inp.end());
    for (int i = 0; i < n; i++)
    {
        auto [a, b] = inp[i];
        for (int j = t - 1; j >= 0; j--)
        {
            if (nd[j])
            {
                if (dp[j] + b > dp[j + a])
                {
                    nd[j + a] = 1;
                    dp[j + a] = dp[j] + b;
                }
            }
        }
    }
    int mx = 0;
    for (int i = 0; i <= t + 3000; i++)
        mx = max(mx, dp[i]);
    cout << mx << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}