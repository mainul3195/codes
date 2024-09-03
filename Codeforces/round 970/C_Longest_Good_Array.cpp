#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
void solve()
{
    int l, r;
    cin >> l >> r;
    r = r - l + 1;
    cout << upper_bound(v.begin(), v.end(), r) - v.begin() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long cur = 1, dif = 1;
    do
    {
        v.push_back(cur);
        cur += dif;
        dif++;
    } while (cur <= 2000000000);
    // for (int i = 0; i < 100; i++)
    // cout << v[i] << "\n";
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}