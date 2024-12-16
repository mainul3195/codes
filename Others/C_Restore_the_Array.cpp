#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n - 1);
    for (auto &i : v)
        cin >> i;
    vector<int> ans(n);
    ans[0] = v[0], ans[n - 1] = v[n - 2];
    for (int i = 1; i < n - 1; i++)
        ans[i] = min(v[i], v[i - 1]);
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
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