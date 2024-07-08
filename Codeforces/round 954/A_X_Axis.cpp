#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v(3);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    cout << v[1] - v[0] + v[2] - v[1] << "\n";
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