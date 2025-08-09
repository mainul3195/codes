#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<string> grid;
int visited[505][505];
int X[] = {1, 0, -1, 0};
int Y[] = {0, -1, 0, 1};

bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && (!visited[x][y]) && (grid[x][y] != '#'));
}

void dfs(int x, int y)
{
    if (k == 0)
        return;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + X[i];
        int new_y = y + Y[i];

        if (valid(new_x, new_y))
            dfs(new_x, new_y);
    }
    if (k)
    {
        grid[x][y] = 'X';
        k--;
    }
    return;
}

void solve()
{
    cin >> n >> m >> k;
    memset(visited, 0, sizeof(visited));

    grid = vector<string>(n);
    for (auto &s : grid)
        cin >> s;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.')
            {
                dfs(i, j);
                for (auto s : grid)
                    cout << s << "\n";
                return;
            }

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}