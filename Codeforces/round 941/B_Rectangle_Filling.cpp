#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
int r, c;
void solve()
{
    cin >> r >> c;
    grid = vector<string>(r);
    for (auto &i : grid)
        cin >> i;
    int bmnx = 2000000000, wmnx = 2000000000, bmny = 2000000000, wmny = 2000000000, bmxx = -2000000000, wmxx = -2000000000, bmxy = -2000000000, wmxy = -2000000000;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'B')
            {
                bmnx = min(bmnx, i);
                bmxx = max(bmxx, i);
                bmny = min(bmny, j);
                bmxy = max(bmxy, j);
            }
            else
            {
                wmnx = min(wmnx, i);
                wmxx = max(wmxx, i);
                wmny = min(wmny, j);
                wmxy = max(wmxy, j);
            }
        }
    if ((bmnx == 0 && bmny == 0 && bmxx == r - 1 && bmxy == c - 1) || (wmnx == 0 && wmny == 0 && wmxx == r - 1 && wmxy == c - 1))
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}