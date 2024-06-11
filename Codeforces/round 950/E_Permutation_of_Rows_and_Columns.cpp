#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (auto &v : a)
        for (auto &i : v)
            cin >> i;
    for (auto &v : b)
        for (auto &i : v)
            cin >> i;
    vector<vector<int>> rows, cols;
    int row_ind[n * m + 2], col_ind[n * m + 2];
    memset(row_ind, -1, sizeof(row_ind));
    memset(col_ind, -1, sizeof(row_ind));
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
            v.push_back(b[i][j]);
        sort(v.begin(), v.end());
        rows.push_back(v);
        for (auto el : v)
            row_ind[el] = i;
    }
    for (int j = 0; j < m; j++)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(b[i][j]);
        sort(v.begin(), v.end());
        cols.push_back(v);
        for (auto el : v)
            col_ind[el] = j;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
            v.push_back(a[i][j]);
        sort(v.begin(), v.end());
        if (v != rows[row_ind[a[i][0]]])
        {
            cout << "NO\n";
            return;
            ;
        }
    }
    for (int j = 0; j < m; j++)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(a[i][j]);
        sort(v.begin(), v.end());
        if (v != cols[col_ind[a[0][j]]])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}