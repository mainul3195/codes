#include <bits/stdc++.h>
using namespace std;
int x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
vector<string> grid;
int r, c;
bool valid(int x, int y)
{
    return x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == '.';
}
int dfs(int u, int v)
{
    int count = 0;
    grid[u][v] = '#';
    for (int i = 0; i < 4; i++)
    {
        int nx = u + x[i];
        int ny = v + y[i];
        if (valid(nx, ny))
            count += dfs(nx, ny);
    }
    return 1 + count;
}
void solve()
{
    cin >> c >> r;
    grid = vector<string>(r);
    for (int i = 0; i < r; i++)
        cin >> grid[i];
    int sx, sy;
    bool found = 0;
    for (int i = 0; !found && i < r; i++)
        for (int j = 0; j < c; j++)
            if (grid[i][j] == '@')
            {
                sx = i;
                sy = j;
                found = 1;
                break;
            }
    cout << dfs(sx, sy) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}