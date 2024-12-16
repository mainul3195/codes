#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> grid, down, lft, rght;
vector<int> tot;
bool possible(int x)
{
    int len = 2 * x - 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if ((j - len / 2 >= 1) && (j + len / 2 <= m) && (i + len - 1 <= n) &&
                (down[i][j] - down[i + len / 2 + 1][j - len / 2] - down[i + len / 2 + 1][j + len / 2] + down[i + len][j] - lft[i + len / 2 + 1][j - len / 2 - 1] - rght[i + len / 2 + 1][j + len / 2 + 1] == tot[x]))
                return 1;
        }
    return 0;
}
void solve()
{
    cin >> n >> m;
    grid = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '#')
                grid[i][j + 1] = 1;
    }
    lft = rght = down = grid;
    for (int i = n; i; i--)
        for (int j = 1; j <= m; j++)
        {
            lft[i][j] += lft[i + 1][j - 1];
            rght[i][j] += rght[i + 1][j + 1];
        }
    for (int i = n; i; i--)
        for (int j = 1; j <= m; j++)
            down[i][j] += down[i + 1][j] + lft[i + 1][j - 1] + rght[i + 1][j + 1];
    int l = 1, r = 250, ans = 0;
    // for (int i = 0; i <= n + 1; i++)
    // {
    //     for (int j = 0; j <= n + 1; j++)
    //         cout << lft[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    // for (int i = 0; i <= n + 1; i++)
    // {
    //     for (int j = 0; j <= n + 1; j++)
    //         cout << rght[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    // for (int i = 0; i <= n + 1; i++)
    // {
    //     for (int j = 0; j <= n + 1; j++)
    //         cout << down[i][j] << " ";
    //     cout << "\n";
    // }
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (possible(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << max(0, 2 * ans - 1) << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    tot.push_back(0);
    int cur = 1, d = 4;
    {
        for (int i = 1; i <= 250; i++)
        {
            tot.push_back(cur);
            cur += d;
            d += 4;
        }
    }
    // for (auto i : tot)
    //     cout << i << "\n";
    cin >> t;
    while (t--)
        solve();
    return 0;
}