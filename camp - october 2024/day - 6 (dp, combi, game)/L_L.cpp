#include <bits/stdc++.h>
using namespace std;
vector<int> prv;
int n;
int okdone(int l = 0, int r = n - 1)
{
    // cout << "here -> " << l << " " << r << "\n";
    if (l + 1 == r)
        return 1;
    if (prv[r] == l)
        return okdone(l + 1, r - 1) + 1;
    int xr = 0;
    int cur = r;
    while (cur > l)
    {
        xr ^= okdone(prv[cur], cur);
        cur = prv[cur] - 1;
    }
    return xr;
}
void solve()
{
    string s;
    cin >> s;
    n = s.size();
    prv = vector<int>(n + 1, 0);
    vector<int> stck;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            stck.push_back(i);
        else
        {
            prv[i] = stck.back();
            stck.pop_back();
        }
    }
    // for (int i = 0; i < n; i++)
    //     cout << prv[i] << " ";
    // cout << "\n";
    // cout << okdone() << " ..\n";
    if (okdone())
        cout << "ATM\n";
    else
        cout << "Bob\n";
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