#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
bool can_place(int x, int y)
{
    if (grid[x][y] == '*')
        return 0;
    for (int i = 0; i < 8; i++)
        if (grid[x][i] == '#' || grid[i][y] == '#')
            return 0;
    for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
        if (grid[i][j] == '#')
            return 0;
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; j--, i--)
        if (grid[i][j] == '#')
            return 0;
    for (int i = x + 1, j = y - 1; i >= 0 && j >= 0 && i < 8 && j < 8; i++, j--)
        if (grid[i][j] == '#')
            return 0;
    for (int i = x - 1, j = y + 1; i >= 0 && j >= 0 && i < 8 && j < 8; i--, j++)
        if (grid[i][j] == '#')
            return 0;
    return 1;
}
int done, ans;
void okdone(int i = 0)
{
    if (done == 8)
    {
        // for (auto s : grid)
        //     cout << s << "\n";
        // cout << "\n";
        ans++;
    }
    if (i == 8)
        return;
    for (int j = 0; j < 8; j++)
    {
        if (can_place(i, j))
        {
            grid[i][j] = '#';
            done++;
            okdone(i + 1);
            done--;
            grid[i][j] = '.';
        }
    }
}
void solve()
{
    grid = vector<string>(8);
    done = ans = 0;
    for (auto &s : grid)
        cin >> s;
    okdone();
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}