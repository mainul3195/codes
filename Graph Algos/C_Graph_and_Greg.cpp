#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1)), dis(n + 1, vector<int>(n + 1, 2000000000));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];
    vector<int> nodes(n);
    for (auto &i : nodes)
        cin >> i;
    vector<long long> ans;
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    vector<int> found;
    while (nodes.size())
    {
        int u = nodes.back();
        nodes.pop_back();
        found.push_back(u);
        for (int i = 1; i <= n; i++)
            dis[i][u] = min(dis[i][u], grid[i][u]),
            dis[u][i] = min(dis[u][i], grid[u][i]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][u] + dis[u][j]);
        long long tot = 0;
        for (auto i : found)
            for (auto j : found)
                tot += dis[i][j];
        ans.push_back(tot);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}