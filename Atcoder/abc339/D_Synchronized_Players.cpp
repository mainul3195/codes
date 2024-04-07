#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int x1, y1, x2, y2;
};
vector<string> grid;
int n;
nd move(nd cur, int move)
{
    if (move == 0)
    {
        if (cur.x1 > 0 && grid[cur.x1 - 1][cur.y1] != '#')
            cur.x1--;
        if (cur.x2 > 0 && grid[cur.x2 - 1][cur.y2] != '#')
            cur.x2--;
    }
    else if (move == 2)
    {
        if (cur.x1 < n - 1 && grid[cur.x1 + 1][cur.y1] != '#')
            cur.x1++;
        if (cur.x2 < n - 1 && grid[cur.x2 + 1][cur.y2] != '#')
            cur.x2++;
    }
    else if (move == 3)
    {
        if (cur.y1 > 0 && grid[cur.x1][cur.y1 - 1] != '#')
            cur.y1--;
        if (cur.y2 > 0 && grid[cur.x2][cur.y2 - 1] != '#')
            cur.y2--;
    }
    else
    {
        if (cur.y1 < n - 1 && grid[cur.x1][cur.y1 + 1] != '#')
            cur.y1++;
        if (cur.y2 < n - 1 && grid[cur.x2][cur.y2 + 1] != '#')
            cur.y2++;
    }
    return cur;
}
int vis[61][61][61][61];
void solve()
{
    cin >> n;
    grid = vector<string>(n);
    for (auto &s : grid)
        cin >> s;
    memset(vis, 0, sizeof(vis));
    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'P')
                pos.push_back({i, j});
        }
    vis[pos[0].first][pos[0].second][pos[1].first][pos[1].second] = 1;
    queue<nd> q;
    q.push({pos[0].first, pos[0].second, pos[1].first, pos[1].second});
    while (q.size())
    {
        auto cur = q.front();
        auto [x1, y1, x2, y2] = cur;
        if (x1 == x2 && y1 == y2)
        {
            cout << vis[x1][y1][x2][y2] - 1 << "\n";
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nd tmp = move(cur, i);
            if (!vis[tmp.x1][tmp.y1][tmp.x2][tmp.y2])
            {
                vis[tmp.x1][tmp.y1][tmp.x2][tmp.y2] = vis[cur.x1][cur.y1][cur.x2][cur.y2] + 1;
                q.push(tmp);
            }
        }
    }
    cout << "-1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}