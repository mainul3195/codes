#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    vector<int> giv(n * n), nw;
    for (auto &i : giv)
        cin >> i;
    sort(giv.begin(), giv.end());
    grid[1][1] = giv[0];
    for (int i = 2; i <= n; i++)
        grid[1][i] = grid[1][i - 1] + d;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++)
            grid[i][j] = grid[i - 1][j] + c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            nw.push_back(grid[i][j]);
    sort(nw.begin(), nw.end());
    if (giv == nw)
        cout << "YES\n";
    else
        cout << "NO\n";
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