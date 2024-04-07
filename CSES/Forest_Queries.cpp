#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> c_sum;
vector<string> grid;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    grid = vector<string>(n);
    for (auto &s : grid)
        cin >> s;
    c_sum = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c_sum[i][j] = c_sum[i - 1][j] + c_sum[i][j - 1] - c_sum[i - 1][j - 1] + (grid[i - 1][j - 1] == '*');
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << c_sum[x2][y2] - c_sum[x2][y1 - 1] - c_sum[x1 - 1][y2] + c_sum[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
}