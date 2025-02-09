#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int X, Y, n;
    cin >> X >> Y >> n;
    vector<pair<int, int>> v(n);
    set<int> x_c, y_c;
    for (auto &[a, b] : v)
        cin >> a >> b;
    v.push_back({0, 0});
    v.push_back({X, Y});
    for (auto [a, b] : v)
    {
        x_c.insert(a);
        y_c.insert(b);
    }
    vector<int> xc(x_c.begin(), x_c.end()), yc(y_c.begin(), y_c.end());
    // for(auto i: xc)
    //     cout << i << " ";
    //     cout << "\n";
    int x_index[10004], y_index[10004];
    for (int i = 0; i < xc.size(); i++)
        x_index[xc[i]] = i;
    for (int i = 0; i < yc.size(); i++)
        y_index[yc[i]] = i;
    vector<int> mid_y[x_c.size() + 1][x_c.size() + 1];
    for (auto [a, b] : v)
    {
        int ind = x_index[a];
        for (int i = 0; i < ind; i++)
            for (int j = ind + 1; j < x_c.size(); j++)
                mid_y[i][j].push_back(b);
    }

    for (int i = 0; i < x_c.size(); i++)
        for (int j = i + 1; j < x_c.size(); j++)
        {
            mid_y[i][j].push_back(0);
            mid_y[i][j].push_back(Y);
            sort(mid_y[i][j].begin(), mid_y[i][j].end());
        }

    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
        {
            int xi = x_index[v[i].first];
            int xj = x_index[v[j].first];
            int dif = 0;
            for (int k = 1; k < mid_y[xi][xj].size(); k++)
                dif = max(dif, mid_y[xi][xj][k] - mid_y[xi][xj][k - 1]);
            ans = max(ans, dif * (xc[xj] - xc[xi]));
        }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}