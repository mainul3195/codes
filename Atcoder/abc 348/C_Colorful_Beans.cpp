#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a, c;
        cin >> a >> c;
        if (mp.find(c) == mp.end())
            mp[c] = a;
        else
            mp[c] = min(mp[c], a);
    }
    int mx = 0;
    for (auto [a, b] : mp)
        mx = max(mx, b);
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