#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
int X[] = {1, 2, 2, 1, -1, -2, -2, -1}, Y[] = {2, 1, -1, -2, -2, -1, 1, 2};
struct nd
{
    int dist, x, y;
    bool operator<(const nd &a) const
    {
        return dist > a.dist;
    }
};
void solve()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        grid = vector<vector<int>>(8, vector<int>(8, 2000000000));
        grid[a][b] = 0;
        priority_queue<nd> q;
        q.push({0, a, b});
        while (q.size())
        {
            auto [d, x, y] = q.top();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int cx = x + X[i];
                int cy = y + Y[i];
                int cost = grid[x][y] + x * cx + y * cy;
                if (cx >= 0 && cy >= 0 && cx < 8 && cy < 8 && grid[cx][cy] > cost)
                {
                    grid[cx][cy] = cost;
                    q.push({cost, cx, cy});
                }
            }
        }
        if (grid[c][d] == 2000000000)
            cout << "-1\n";
        else
            cout << grid[c][d] << "\n";
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