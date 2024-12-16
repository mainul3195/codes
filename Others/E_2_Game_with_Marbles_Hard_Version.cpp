#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long v;
    int ind;
    bool operator<(const nd &a) const
    {
        return v < a.v;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    vector<nd> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {a[i] + b[i] - 2, i};
    sort(v.rbegin(), v.rend());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            ans -= b[v[i].ind] - 1;
        else
            ans += a[v[i].ind] - 1;
    }
    cout << ans << "\n";

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