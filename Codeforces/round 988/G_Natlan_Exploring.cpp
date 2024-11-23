#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
vector<long long> vec(2000006, 0);
vector<int> spf(2000006, 1);
void find_spf()
{
    for (int i = 2; i <= 2000000; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i <= 2000000; i += 2)
        if (spf[i] == 1)
            for (int j = i * i; j <= 2000000; j += 2 * i)
                if (spf[j] == 1)
                    spf[j] = i;
    for (int i = 3; i <= 2000000; i += 2)
        if (spf[i] == 1)
            spf[i] = i;
    return;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long ans = 0;
        int x;
        cin >> x;
        vector<int> p;
        while (x != 1)
        {
            int f = spf[x];
            while (x % f == 0)
                x /= f;
            p.push_back(f);
        }
        int sz = p.size();
        int lim = (1 << sz);
        for (int j = 1; j < lim; j++)
        {
            x = j;
            int ind = 0;
            int num = 1;
            int ones = 0;
            while (x)
            {
                if (x & 1)
                    num *= p[ind], ones++;
                x >>= 1;
                ind++;
            }
            ans = (ans + vec[num] * (ones & 1 ? 1 : -1)) % mod;
        }
        if (i == 0)
            ans = 1;
        if (i == n - 1)
        {
            cout << (ans + mod) % mod << "\n";
            return;
        }
        for (int j = 1; j < lim; j++)
        {
            x = j;
            int ind = 0;
            int num = 1;
            while (x)
            {
                if (x & 1)
                    num *= p[ind];
                x >>= 1;
                ind++;
            }
            vec[num] = (vec[num] + ans) % mod;
        }
    }

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    find_spf();
    solve();
    return 0;
}