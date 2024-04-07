#include <bits/stdc++.h>
using namespace std;
#define mod1 998255353
#define mod2 1000000007
void solve()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> v;
    map<pair<long long, long long>, long long> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        long long tot1 = 0, tot2 = 0;
        for (auto c : s)
        {
            tot1 = tot1 * 10 + c - '0';
            tot1 %= mod1;
            tot2 = tot2 * 10 + c - '0';
            tot2 %= mod2;
        }
        v.push_back({tot1, tot2});
        mp[{tot1, tot2}]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            long long p1 = v[i].first * v[j].first % mod1;
            long long p2 = v[i].second * v[j].second % mod2;
            ans += mp[{p1, p2}];
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