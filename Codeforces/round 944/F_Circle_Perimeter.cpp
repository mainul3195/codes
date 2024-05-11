#include <bits/stdc++.h>
using namespace std;
int X[] = {1, 0, -1, 0}, Y[] = {0, -1, 0, 1};
long long s, e;
bool ok(int x, int y)
{
    long long dis = (long long)x * x + (long long)y * y;
    return dis >= s && dis < e;
}
long long dist(long long x, long long y)
{
    return x * x + y * y;
}
void solve()
{
    long long r;
    cin >> r;
    s = r * r;
    e = (r + 1) * (r + 1);
    map<pair<int, int>, bool> vis;
    queue<pair<int, int>> q;
    q.push({r, 0});
    vis[{r, 0}] = 1;
    int cnt = 0;
    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        bool ook = ok(x, y);
        if (ook)
            cnt++;
        long long dista = dist(x, y);
        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i];
            int ny = y + Y[i];
            if (ook)
            {
                if (ok(nx, ny))
                {

                    if (vis.find({nx, ny}) == vis.end())
                    {
                        vis[{nx, ny}] = 1;
                        q.push({nx, ny});
                    }
                    continue;
                }
                long long distb = dist(nx, ny);
                if (distb > dista)
                {
                    if (vis.find({nx, ny}) == vis.end())
                    {
                        vis[{nx, ny}] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            else
            {
                if (ok(nx, ny) && vis.find({nx, ny}) == vis.end())
                {
                    vis[{nx, ny}] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << cnt << "\n";
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