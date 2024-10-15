#include <bits/stdc++.h>
using namespace std;
#define lim 10000005
vector<int> spf(lim + 1);
void smallest_pf()
{
    for (int i = 2; i <= lim; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i <= lim; i += 2)
        if (!spf[i])
            for (int j = i; j <= lim; j += 2 * i)
                spf[j] = i;
    for (int i = 3; i <= lim; i += 2)
        if (!spf[i])
            spf[i] = i;
    return;
}
void find_factors(int x, vector<int> &v)
{
    while (x != 1)
    {
        v.push_back(spf[x]);
        int p = spf[x];
        while (x % p == 0)
            x /= p;
    }
}
void solve()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    long long tot = (long long)(r1 - l1 + 1) * (r2 - l2 + 1);
    long long non_co_prime = 0;
    for (int i = l1; i <= r1; i++)
    {
        vector<int> factors;
        find_factors(i, factors);
        int limit = (1 << factors.size());
        for (int j = 1; j < limit; j++)
        {
            int cur = 1, cnt = 0;
            for (int k = 0; k < factors.size(); k++)
            {
                if (j & (1 << k))
                    cur *= factors[k], cnt++;
            }
            non_co_prime += (long long)(cnt & 1 ? 1 : -1) * (r2 / cur - (l2 - 1) / cur);
        }
    }
    cout << tot - non_co_prime << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    smallest_pf();
    solve();
    return 0;
}