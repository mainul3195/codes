#include <bits/stdc++.h>
using namespace std;
long long x, y, z, k;
long long cost(long long mx)
{
    long long tot_hit = (mx - 1) / k;
    long long tot_damage = k * tot_hit * (tot_hit + 1) / 2;
    if (tot_damage >= z)
    {
        long long c = tot_damage;
        long long hit = tot_hit;
        for (int j = tot_hit - 1; j >= 0; j--)
        {
            long long tmp_damage = k * j * (j + 1) / 2;
            if (tmp_damage >= z)
                c = tmp_damage, hit = j;
            else
                break;
        }
        return y * hit + hit * k * x;
    }
    long long rem_damage = z - tot_damage;
    return y * tot_hit + ((rem_damage + mx - 1) / mx) * y + mx * x;
}
void solve()
{
    cin >> x >> y >> z >> k;
    for (int mx = 1; mx <= z; mx++)
        cout << cost(mx) << " ";
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}