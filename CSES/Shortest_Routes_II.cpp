#include <bits/stdc++.h>
using namespace std;
#define inf 10000000000000000
int n, m, q;
vector<vector<long long>> path;
void solve()
{
    cin >> n >> m >> q;
    path = vector<vector<long long>>(n + 1, vector<long long>(n + 1, inf));
    for (int i = 0; i <= n; i++)
        path[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        path[u][v] = min(path[u][v], (long long)w);
        path[v][u] = min(path[v][u], (long long)w);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (path[u][v] == inf)
            cout << "-1\n";
        else
            cout << path[u][v] << "\n";
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