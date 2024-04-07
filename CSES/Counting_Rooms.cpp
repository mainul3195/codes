#include <bits/stdc++.h>
using namespace std;
int n, m, x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
vector<string> grid;
bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '.';
}
void dfs(int i, int j)
{
    grid[i][j] = '#';
    for (int k = 0; k < 4; k++)
    {
        int ni = i + x[k];
        int nj = j + y[k];
        if (valid(ni, nj))
            dfs(ni, nj);
    }
    return;
}
void solve()
{
    cin >> n >> m;
    grid = vector<string>(n);
    for (auto &s : grid)
        cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.')
            {
                ans++;
                dfs(i, j);
            }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}