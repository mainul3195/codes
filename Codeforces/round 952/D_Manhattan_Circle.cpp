#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (auto &i : grid)
        cin >> i;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '#')
            {
                int start = i;
                while (i < h && grid[i][j] == '#')
                    i++;
                i--;
                cout << (start + i) / 2 + 1 << " " << j + 1 << "\n";
                return;
            }
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