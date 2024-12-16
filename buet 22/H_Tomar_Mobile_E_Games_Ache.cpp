#include <bits/stdc++.h>
using namespace std;
int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
int yshift[] = {0, 20, 20, 0, -20, -20, -20, 0, 20}, xshift[] = {0, 0, -16, -16, -16, 0, 16, 16, 16};
void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int mn = 10000000;
    for (int i = 0; i < 9; i++)
        mn = min(mn, dist(x1, y1, x2 + xshift[i], y2 + yshift[i]));
    cout << mn << "\n";
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