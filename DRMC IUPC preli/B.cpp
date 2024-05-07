#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    long long ans[n + 1] = {0};
    ans[0] = 0;
    for (int i = 1; i < n; i++)
        ans[i] = ans[i - 1] + i * (v[i] - v[i - 1]);
    long long tot = 0;
    for (int i = 0; i < n; i++)
        tot += ans[i];
    cout << tot << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}