#include <bits/stdc++.h>
using namespace std;
int grid[101][101];
int X[] = {1, 0, -1, 0}, Y[] = {0, -1, 0, 1};
struct nd
{
    int dist, x, y;
    bool operator<(const nd &a) const
    {
        return dist > a.dist;
    }
};
vector<vector<int>> dis;
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    dis = vector<vector<int>>(n, vector<int>(m, 2000000000));
    dis[a][b] = 0;
    priority_queue<nd> q;
    q.push({0, a, b});
    while (q.size())
    {
        auto [d, x, y] = q.top();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cx = x + X[i];
            int cy = y + Y[i];
            if (cx >= 0 && cy >= 0 && cx < n && cy < m)
            {
                int cost = d + (grid[x][y] != grid[cx][cy]);
                if (dis[cx][cy] > cost)
                {
                    dis[cx][cy] = cost;
                    q.push({cost, cx, cy});
                }
            }
        }
    }
    if (dis[c][d] & 1)
        cout << "Chairman\n";
    else
        cout << "Kaiji\n";
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