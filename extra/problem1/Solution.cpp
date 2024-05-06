#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> xx, yy, m(n);
    for (auto &i : m)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < m[i]; j++)
            xx.push_back(x), yy.push_back(y);
    }
    long long X = xx[(xx.size() - 1) / 2];
    long long Y = yy[(yy.size() - 1) / 2];
    long long M = 0;
    for (int i = 0; i < xx.size(); i++)
        M += abs(xx[i]) + abs(yy[i]);
    cout << X << " " << Y << " " << M << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}