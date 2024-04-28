#include <bits/stdc++.h>
using namespace std;
#define N 6
set<vector<vector<int>>> st;
void okdone(vector<vector<int>> v)
{
    vector<pair<int, int>> avail;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            bool ok = 1;
            for (int k = 0; k < N; k++)
                if (v[i][k] || v[k][j])
                {
                    ok = 0;
                    break;
                }
            if (ok)
                avail.push_back({i, j});
        }
    if (avail.size() == 0)
    {
        st.insert(v);
        return;
    }
    for (auto [a, b] : avail)
    {
        v[a][b] = 1;
        if (a != b)
            v[b][a] = 2;
        okdone(v);
        v[a][b] = v[b][a] = 0;
    }
    return;
}
void solve()
{
    vector<vector<int>> v;
    v = vector<vector<int>>(N, vector<int>(N, 0));
    okdone(v);
    cout << st.size() << "\n";
    for (auto vec : st)
    {
        for (auto a : vec)
        {
            for (auto b : a)
                cout << b << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}