#include <bits/stdc++.h>
using namespace std;
#define lim 10002002
bitset<lim + 2> bit;
vector<long long> primes;
void make_primes()
{
    primes.push_back(2);
    for(int i = 4; i<lim; i+=2)
        bit[i] = 1;
    bit[1] = 1;
    for (int i = 3; i * i < lim; i += 2)
        if (!bit[i])
            for (int j = i * i; j < lim; j += 2 * i)
                bit[j] = 1;
    for (int i = 3; i < lim; i += 2)
        if (!bit[i])
            primes.push_back(i);
    return;
}
int ans[lim];
void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << "\n";
    return;
}
int32_t main()
{
    make_primes();
    ans[5] = 2;
    for (int i = 6; i <= 10000000; i++)
    {
        ans[i] += ans[i - 1];
        if (!bit[i] && !bit[i - 2])
            ans[i]++;
    }
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++tc << ": ";
        solve();
    }
    return 0;
}