#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<string> grid, fog;
vector<vector<int>> dist;
struct nd {
    int dist, x, y;
    bool operator<(const nd &a) const
    {
        return dist>a.dist;
    }
};
void solve()
{
    cin >> n >> m >> k;
    dist = vector<vector<int>> (n+1, vector<int> (m+1, 2000000000));
    grid = vector<string>(n);
    for (auto &s : grid)
        cin >> s;
    fog = vector<string>(n);
    for (auto &s : fog)
        cin >> s;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'C')
                start = {i, j};
            if (grid[i][j] == 'R')
                end = {i, j};
        }
    priority_queue<nd> pq;

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}