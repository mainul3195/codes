#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    int mxa = 0, mxb = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mxa = max(mxa, x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        mxb = max(mxb, x);
    }
    if (mxa >= mxb)
    {
        cout << "Godzilla\n";
    }
    else if (mxb > mxa)
    {
        cout << "MechaGodzilla\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}