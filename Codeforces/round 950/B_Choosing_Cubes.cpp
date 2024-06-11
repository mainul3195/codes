#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int val = v[f - 1];
    sort(v.rbegin(), v.rend());
    k--;
    if (k == n - 1)
    {
        cout << "YES\n";
        return;
    }
    if (v[k] < val || (v[k] == val && v[k + 1] != val))
    {
        cout << "YES\n";
        return;
    }
    if (v[k] == val && v[k + 1] == val)
        cout << "MAYBE\n";
    else
        cout << "NO\n";
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