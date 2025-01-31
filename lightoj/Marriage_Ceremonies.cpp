#include<bits/stdc++.h>
using namespace std;
int sq[17][17];
int n;
void solve()
{
    cin >> n;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> sq[i][j];
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}