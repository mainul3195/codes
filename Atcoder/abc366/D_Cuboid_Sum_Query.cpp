#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ar[n + 1][n + 1][n + 1];
    memset(ar, 0, sizeof(ar));
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            for (int z = 1; z <= n; z++)
            {
                cin >> ar[x][y][z];
                ar[x][y][z] += ar[x - 1][y][z] + ar[x][y - 1][z] + ar[x][y][z - 1] - ar[x - 1][y - 1][z] - ar[x - 1][y][z - 1] - ar[x][y - 1][z - 1] + ar[x - 1][y - 1][z - 1];
            }
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= n; j++)
    //     {
    //         for (int k = 0; k <= n; k++)
    //             cout << ar[i][j][k] << " ";
    //         cout << "\n";
    //     }
    int q;
    cin >> q;
    while (q--)
    {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        x1--, y1--, z1--;
        // cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << z1 << " " << z2 << "\n";
        // cout << ar[x2][y2][z2] << " " << ar[x1][y2][z2] << " " << ar[x2][y1][z2] << " " << ar[x2][y2][z1] << " " << ar[x1][y2][z2] << " " << ar[x1][y2][z1] << " " << ar[x2][y1][z1] << " " << ar[x1][y1][z1] << "\n";
        cout << ar[x2][y2][z2] - ar[x1][y2][z2] - ar[x2][y1][z2] - ar[x2][y2][z1] + ar[x1][y1][z2] + ar[x1][y2][z1] + ar[x2][y1][z1] - ar[x1][y1][z1] << "\n";
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