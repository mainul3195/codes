#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
int h, w, X[] = {1, 0, -1, 0}, Y[] = {0, -1, 0, 1};
bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < h && y < w;
}
void solve()
{
    cin >> h >> w;
    grid = vector<string>(h);
    for (auto &s : grid)
        cin >> s;
    int i = 0, j = 0;
    while (1)
    {
        grid[i][j] = '.';
        if (i == h - 1 && j == w - 1)
            break;
        int x = i, y = j + 1;
        if (valid(x, y) && grid[x][y] == '#')
        {
            i = x, j = y;
            continue;
        }
        x = i + 1, y = j;
        if (valid(x, y) && grid[x][y] == '#')
        {
            i = x, j = y;
            continue;
        }
        break;
    }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '#')
            {
                cout << "Impossible\n";
                return;
            }
    cout << "Possible\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}