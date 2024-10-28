#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    map<int, int> fnd, occp;
    long long ans = 0, tot = 0;
    for (auto i : v)
    {
        ans += tot - occp[i];
        int pr = fnd[-i];
        tot += pr;
        if (i)
        {
            occp[i] += pr;
            occp[-i] += pr;
        }
        else
            occp[i] += pr;
        fnd[i]++;
    }
    cout << ans << "\n";
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