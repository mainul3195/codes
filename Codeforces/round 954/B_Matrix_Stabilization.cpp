#include <bits/stdc++.h>
using namespace std;
int x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
int n, m;
vector<vector<int>> grid;
bool ok(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}
int nei(int i, int j)
{
    int mx = 0;
    for (int k = 0; k < 4; k++)
    {
        int ni = i + x[k];
        int nj = j + y[k];
        if (ok(ni, nj))
        {
            if (grid[i][j] <= grid[ni][nj])
                return 0;
            mx = max(mx, grid[ni][nj]);
        }
    }
    return mx;
}
void solve()
{
    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m));
    for (auto &v : grid)
        for (auto &i : v)
            cin >> i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int x = nei(i, j);
            if (x)
                grid[i][j] = x;
        }
    for (auto v : grid)
    {
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}