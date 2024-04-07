#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;
long long tot;
long long ans;
void okdone(int i = 0, long long sum = 0)
{
    if (i == n)
    {
        ans = min(ans, abs(tot - 2 * sum));
        return;
    }
    okdone(i + 1, sum);
    okdone(i + 1, sum + v[i]);
    return;
}
void solve()
{
    tot = 0;
    cin >> n;
    v = vector<long long>(n);
    for (auto &i : v)
    {
        cin >> i;
        tot += i;
    }
    ans = 9223372036854775807;
    okdone();
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