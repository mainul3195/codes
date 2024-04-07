#include <bits/stdc++.h>
using namespace std;
int n, m, k;
void solve()
{
    cin >> n >> m >> k;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    int x = 0, y = 0, dir = 0;
    for (int i = 0; i < k; i++)
    {
        // cout << dir << "\n";
        int cur = grid[x][y];
        if (cur == 0)
            dir = (dir + 1) % 4;
        else
            dir = (dir - 1 + 4) % 4;
        grid[x][y] ^= 1;
        if (dir == 0)
            x = (x - 1 + n) % n;
        else if (dir == 2)
            x = (x + 1) % n;
        else if (dir == 1)
            y = (y + 1) % m;
        else
            y = (y - 1 + m) % m;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j])
                cout << "#";
            else
                cout << ".";
        }
        cout << "\n";
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