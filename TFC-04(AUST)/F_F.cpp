#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a)
        cin >> i;
    vector<long long> c;
    c.push_back(0);
    for (auto i : a)
        c.push_back((c.back() + i) % mod);
    // for(auto i: c)
    //     cout << i << " ";
    //     cout << "\n";
    long long ans = 0;
    for (int i = 1; i < n; i++)
        ans = (ans + a[i] * c[i] % mod) % mod;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}