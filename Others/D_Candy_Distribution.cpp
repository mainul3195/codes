#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;
    map<long long, long long> mp;
    mp[0] = 1;
    long long c_sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        c_sum += x;
        c_sum %= m;
        ans += mp[c_sum];
        mp[c_sum]++;
    }
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