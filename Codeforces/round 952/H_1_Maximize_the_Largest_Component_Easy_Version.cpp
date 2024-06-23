#include <bits/stdc++.h>
using namespace std;
int h, w, X[] = {1, 0, -1, 0}, Y[] = {0, -1, 0, 1};
vector<string> grid;
vector<vector<int>> n_grid;
bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < h && y < w;
}
int dfs(int x, int y, int cc)
{
    int tot = 1;
    grid[x][y] = '.';
    n_grid[x][y] = cc;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + X[i];
        int ny = y + Y[i];
        if (valid(nx, ny) && grid[nx][ny] == '#')
            tot += dfs(nx, ny, cc);
    }
    return tot;
}
void solve()
{
    cin >> h >> w;
    grid = vector<string>(h);
    for (auto &i : grid)
        cin >> i;
    n_grid = vector<vector<int>>(h, vector<int>(w, 0));
    int cc = 1;
    vector<int> mp;
    mp.push_back(0);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '#')
            {
                int tot = dfs(i, j, cc);
                mp.push_back(tot);
                cc++;
            }
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //         cout << n_grid[i][j] << " ";
    //     cout << "\n";
    // }
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        set<int> st;
        int blank = 0;
        for (int j = 0; j < w; j++)
        {
            if (n_grid[i][j])
                st.insert(n_grid[i][j]);
            else
                blank++;
            for (int k = 0; k < 4; k++)
            {
                int ni = i + X[k];
                int nj = j + Y[k];
                if (valid(ni, nj) && n_grid[ni][nj])
                    st.insert(n_grid[ni][nj]);
            }
        }
        for (auto i : st)
            blank += mp[i];
        ans = max(ans, blank);
    }
    for (int j = 0; j < w; j++)
    {
        set<int> st;
        int blank = 0;
        for (int i = 0; i < h; i++)
        {
            if (n_grid[i][j])
                st.insert(n_grid[i][j]);
            else
                blank++;
            for (int k = 0; k < 4; k++)
            {
                int ni = i + X[k];
                int nj = j + Y[k];
                if (valid(ni, nj) && n_grid[ni][nj])
                    st.insert(n_grid[ni][nj]);
            }
        }
        for (auto i : st)
            blank += mp[i];
        ans = max(ans, blank);
    }
    cout << ans << "\n";
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