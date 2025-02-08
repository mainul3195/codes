#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int dis[n + 1][n + 1];
    memset(dis, -1, sizeof(dis));
    dis[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    int done = 1, tot = n * n;
    int rad = sqrt(m + .5);
    while (q.size() && done < tot)
    {
        auto [i, j] = q.front();
        q.pop();
        for (int l = j - rad; l <= j + rad; l++)
        {
            int vitor = m - (j - l) * (j - l);

            if (vitor >= 0)
            {
                int sq = sqrt(vitor + .5);
                if (sq * sq == vitor)
                {
                    int k1 = i + sq;
                    int k2 = i - sq;
                    if (k1 >= 0 && k1 < n && l >= 0 && l < n && dis[k1][l] == -1)
                    {
                        dis[k1][l] = dis[i][j] + 1;
                        done++;
                        if (done == tot)
                            break;
                        q.push({k1, l});
                    }
                    if (k2 >= 0 && k2 < n && l >= 0 && l < n && dis[k2][l] == -1)
                    {
                        dis[k2][l] = dis[i][j] + 1;
                        done++;
                        if (done == tot)
                            break;
                        q.push({k2, l});
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dis[i][j] << " \n"[j == n - 1];
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