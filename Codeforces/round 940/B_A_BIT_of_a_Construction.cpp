#include <bits/stdc++.h>
using namespace std;
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1));
    long long T = bigMod(b, p / 2);
    return (T * T);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << k << "\n";
        return;
    }
    int nm = bigMod(2, log2(k + .5));
    int rem = k - nm;
    vector<int> v;
    v.push_back(nm - 1);
    v.push_back(rem + 1);
    while (v.size() < n)
        v.push_back(0);
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
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