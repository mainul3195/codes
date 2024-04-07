#include <bits/stdc++.h>
using namespace std;
int n, m, x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
pair<int, int> b, e;
vector<string> grid;
bool valid(int &i, int &j)
{
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#';
}
void solve()
{
    cin >> n >> m;
    grid = vector<string>(n);
    for (auto &i : grid)
        cin >> i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
                b = {i, j};
            else if (grid[i][j] == 'B')
                e = {i, j};
        }
    char dir[5] = "DLUR";
    map<pair<int, int>, char> par;
    queue<pair<int, int>> q;
    q.push(b);
    bool found = 0;
    while (!found && q.size())
    {
        pair<int, int> p = q.front();
        q.pop();
        auto [X, Y] = p;
        for (int i = 0; i < 4; i++)
        {
            int nX = X + x[i];
            int nY = Y + y[i];
            if (valid(nX, nY))
            {
                par[{nX, nY}] = dir[i];
                if ((pair<int, int>){nX, nY} == e)
                {
                    found = 1;
                    break;
                }
                grid[nX][nY] = '#';
                q.push({nX, nY});
            }
        }
    }
    if (found)
    {
        cout << "YES\n";
        string path;
        while (e != b)
        {
            path.push_back(par[e]);
            if (par[e] == 'L')
                e.second++;
            else if (par[e] == 'R')
                e.second--;
            else if (par[e] == 'U')
                e.first++;
            else
                e.first--;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        cout << path << "\n";
        return;
    }
    cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}