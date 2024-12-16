#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int dist[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
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