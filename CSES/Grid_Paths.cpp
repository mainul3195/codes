#include <bits/stdc++.h>
using namespace std;
string s;

int ans = 0;
bool vis[7][7];
bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 7 && y < 7 && !vis[x][y];
}
void dfs(int i, int j, int &move)
{
    bool t = ((!valid(i, j + 1) && !valid(i, j - 1) && valid(i - 1, j) && valid(i + 1, j)) ||
              (!valid(i + 1, j) && !valid(i - 1, j) && valid(i, j + 1) && valid(i, j - 1)));
    if (t)
        return;
    if (i == 6 && j == 0)
    {
        if (move == 48)
            ans++;
        return;
    }
    vis[i][j] = 1;
    if (s[move] == '?')
    {
        if (valid(i + 1, j))
        {
            move++;
            dfs(i + 1, j, move); // down
            move--;
        }
        if (valid(i - 1, j))
        {
            move++;
            dfs(i - 1, j, move); // up
            move--;
        }
        if (valid(i, j + 1))
        {
            move++;
            dfs(i, j + 1, move); // right
            move--;
        }
        if (valid(i, j - 1))
        {
            move++;
            dfs(i, j - 1, move); // left
            move--;
        }
    }
    else
    {
        if (s[move] == 'D' && valid(i + 1, j))
        {
            move++;
            dfs(i + 1, j, move); // down
            move--;
        }
        else if (s[move] == 'U' && valid(i - 1, j))
        {
            move++;
            dfs(i - 1, j, move); // up
            move--;
        }
        else if (s[move] == 'R' && valid(i, j + 1))
        {
            move++;
            dfs(i, j + 1, move); // right
            move--;
        }
        else if (s[move] == 'L' && valid(i, j - 1))
        {
            move++;
            dfs(i, j - 1, move); // left
            move--;
        }
    }
    vis[i][j] = 0;
    return;
}
void solve()
{
    cin >> s;
    int move = 0;
    dfs(0, 0, move);
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