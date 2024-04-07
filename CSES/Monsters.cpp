#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, pair<int, int> p)
{
    return os << "( " << p.first << " , " << p.second << " )\n";
}
int n, m, x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
vector<string> grid;
vector<vector<int>> dis_me, dis_mons, vis;
bool valid(int &i, int &j)
{
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#';
}
void multi_source_bfs(vector<vector<int>> &v)
{

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 0)
                q.push({i, j});

    while (q.size())
    {
        auto [a, b] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nu = a + x[i];
            int nv = b + y[i];
            if (valid(nu, nv) && (v[nu][nv] > v[a][b] + 1))
            {
                v[nu][nv] = v[a][b] + 1;
                q.push({nu, nv});
            }
        }
    }
    return;
}

string path;
char dir[5] = "DLUR";
int dfs(int i, int j)
{
    vis[i][j] = 1;
    if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
        return 1;
    for (int k = 0; k < 4; k++)
    {
        int ni = i + x[k];
        int nj = j + y[k];
        if (valid(ni, nj) && dis_me[ni][nj] < dis_mons[ni][nj] && !vis[ni][nj])
        {
            int t = dfs(ni, nj);
            if (t)
            {
                path.push_back(dir[k]);
                return t;
            }
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> m;
    grid = vector<string>(n);
    for (auto &i : grid)
        cin >> i;
    dis_me = dis_mons = vector<vector<int>>(n + 1, vector<int>(m + 1, 2000000000));
    vis = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    pair<int, int> start, monster;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                start = {i, j};
                dis_me[i][j] = 0;
            }
            else if (grid[i][j] == 'M')
            {
                monster = {i, j};
                dis_mons[i][j] = 0;
            }
        }
    multi_source_bfs(dis_me);
    multi_source_bfs(dis_mons);
    if (!dfs(start.first, start.second))
        cout << "NO\n";
    else
    {
        reverse(path.begin(), path.end());
        cout << "YES\n"
             << path.size() << "\n"
             << path << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}