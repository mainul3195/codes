#include <bits/stdc++.h>
using namespace std;
int h, w, X[] = {1, 0, -1, 0}, Y[] = {0, -1, 0, 1};
vector<string> grid;
vector<vector<int>> med, eng;
bool valid(int a, int b)
{
    return a >= 0 && b >= 0 && a < h && b < w && (grid[a][b] != '#');
}
struct nd
{
    int e, x, y;
    bool operator<(const nd &a) const
    {
        return e < a.e || (e == a.e && x < a.x) || (e == a.e && x == a.x && y < a.y);
    }
};
void solve()
{
    cin >> h >> w;
    grid = vector<string>(h);
    for (auto &s : grid)
        cin >> s;
    med = eng = vector<vector<int>>(h, vector<int>(w, 0));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r, c, a;
        cin >> r >> c >> a;
        r--, c--;
        med[r][c] = a;
    }
    int x = -1, y;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == 'S')
            {
                x = i, y = j;
                break;
            }
        }
        if (x != -1)
            break;
    }
    priority_queue<nd> q;
    eng[x][y] = max(0, med[x][y]);
    q.push({max(0, med[x][y]), x, y});
    while (q.size())
    {
        auto [e, u, v] = q.top();
        q.pop();
        if (!e)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nu = u + X[i];
            int nv = v + Y[i];
            if (valid(nu, nv))
            {
                if (grid[nu][nv] == 'T')
                {
                    cout << "Yes\n";
                    return;
                }
                int nw = max(e - 1, med[nu][nv]);
                if (eng[nu][nv] < nw)
                {
                    eng[nu][nv] = nw;
                    q.push({nw, nu, nv});
                }
            }
        }
    }
    cout << "No\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}