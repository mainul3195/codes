#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve()
{
    cin >> n >> k;
    vector<string> grid(n);
    for (auto &s : grid)
        cin >> s;
    for (int i = 0; i < n; i += k)
    {
        for (int j = 0; j < n; j += k)
            cout << grid[i][j];
        cout << "\n";
    }
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