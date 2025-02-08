#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> e, o;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
            o.push_back(x);
        else
            e.push_back(x);
    }
    long long mx = -1;
    sort(o.rbegin(), o.rend());
    sort(e.rbegin(), e.rend());
    if (o.size() >= 2)
        mx = max(mx, o[0] + o[1]);
    if (e.size() >= 2)
        mx = max(mx, e[0] + e[1]);
    cout << mx << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}